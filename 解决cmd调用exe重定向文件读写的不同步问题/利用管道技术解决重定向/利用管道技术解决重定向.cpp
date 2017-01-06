/*
	之所以用管道，是因为利用 cmd x.exe >filename 这样的重定向，如果在shellexec执行这个指令之后立即进行读取重定向文件，即使在之前用了waitforsingleobject也不能
	实现同步。因为这里的waitforsingleobject等待的是cmd的执行完成，而不是 x.exe执行完成。
*/
#include <iostream>
#include <io.h>
#include <windows.h>
#include <stdio.h>
#include <fstream>

using namespace std;

int main(int argc, char ** args){
	string exePath = "C:\\Users\\Administrator\\desktop\\test.exe";
	string outputFilePath = "C:\\Users\\Administrator\\desktop\\temp.out";
	
	//创建一个管道
	SECURITY_ATTRIBUTES sa;
	HANDLE hRead, hWrite;
	sa.nLength = sizeof(sa);
	sa.lpSecurityDescriptor = NULL;
	sa.bInheritHandle = TRUE;
	if(0 == CreatePipe(&hRead,&hWrite,&sa,0)){
		cout << "创建管道失败" << endl;
		return -1;
	}

	//CreateProcess
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	si.cb = sizeof(STARTUPINFO);
	GetStartupInfo(&si); //得到启动信息，跟当前父进程有关
	si.hStdError = hWrite; //重定向标准错误输出
	si.hStdOutput = hWrite; //重定向标准输出
	si.wShowWindow = SW_HIDE;
	si.dwFlags = STARTF_USESHOWWINDOW | STARTF_USESTDHANDLES;
	//第5个参数设置位true表示会继承父进程的所有可继承的句柄。这里的继承表示创建子进程的时候会遍历父进程的资源，凡是可以继承的资源句柄都拷贝一份过来。
	//这里需要将句柄继承属性设置为true。因为要使用管道。管道是创建在父进程的。
	if(0 == CreateProcess(exePath.c_str(), NULL,NULL,NULL,TRUE,CREATE_DEFAULT_ERROR_MODE,
		NULL,NULL,&si,&pi)){ //执行成功返回非0 执行失败返回0
		cout << "执行子程序失败，错误代码是：" << GetLastError() << endl;
		return -1;
	}
	cout << "子进程的id： "<< pi.dwProcessId << endl;
	cout << "子进程的主线程id： "<< pi.dwThreadId << endl;
	//等待子进行初始化完成.
	WaitForInputIdle(pi.hProcess, INFINITE);
	//等待子进程结束
    WaitForSingleObject(pi.hProcess, INFINITE);
	//关闭输入流
	CloseHandle(hWrite);

    cout << ".....detial run result is below..." << endl;
	//获取管道中的内容
	char buffer[1024+1] = {0};
	DWORD dwCount; //用来接受实际读取到的大小

	//readfile可以从 管道  文件  socket 里面读取内容。
	fstream f(outputFilePath.c_str(), ios::out | ios::binary);
	if(NULL == f){
		cout << "重定向文件打开失败" <<  endl;
		return -1;
	}
	while(0 != ReadFile(hRead, buffer, 1024, &dwCount,NULL)){
		cout << buffer;
		f << buffer;
		if(1024 > dwCount) //已经读到文件的末尾
			break;
	}
	f.close();
	CloseHandle(hRead);
}