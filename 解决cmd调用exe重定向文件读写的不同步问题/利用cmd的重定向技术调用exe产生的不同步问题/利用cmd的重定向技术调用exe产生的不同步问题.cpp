#include <iostream>
#include <io.h>
#include <windows.h>
#include <stdio.h>

using namespace std;

void printFileContent2Console(string filePath){
    char buffer[1024] = {0}; //缓冲字符串

    FILE * file = fopen(filePath.c_str(), "r");
	if(NULL == file){
		cout << "filePath not found" << endl;
		return;
	}
    while(NULL != fgets(buffer, 1023, file)){ //fgets读取失败或者到了文件末尾 返回false，否则返回buffer指针
        cout << buffer;
    }
    fclose(file);
}


int main(int argc, char ** args){
	string exePath = "C:\\Users\\Administrator\\desktop\\test.exe";
	string outputFilePath = "C:\\Users\\Administrator\\desktop\\temp.out";

	//要想实现标准输出重定向，需要用cmd 直接调相应的exe，如果不支持就会解析成相应的一个输入参数。
	HINSTANCE hinstance = ShellExecute(NULL, "open", "cmd", ("/c " + exePath + " >" + outputFilePath).c_str(), NULL, SW_NORMAL);
	//HINSTANCE hinstance = ShellExecute(NULL, "open", exePath.c_str(), (" >" + outputFilePath).c_str(), NULL, SW_HIDE);
    cout << "command : " << (exePath + " >" + outputFilePath) << endl;
    if((long)hinstance < 32){
        cout << ("shell exec fail") << endl;
		return -1;
    }

	//这里出了一个问题，就是一方面只能调用cmd将应用程序作为参数传入，这样才能重定向输出到文件，可是另一方面，如果这样做，那么下面的waitforsingleobject就成了等待
	//这个cmd执行完成，这个好像跟后面的实际应用程序执行完成有区别，导致了文件读写同步出现了问题。
	//由于这个问题，下面，只有添加sleep才能得到正确的结果，而waitforsingleobject没能实现想要的效果。
    WaitForSingleObject(hinstance, INFINITE);
	//Sleep(1000 * 2);
    cout << ".....detial run result is below..." << endl;
    printFileContent2Console(outputFilePath);
}