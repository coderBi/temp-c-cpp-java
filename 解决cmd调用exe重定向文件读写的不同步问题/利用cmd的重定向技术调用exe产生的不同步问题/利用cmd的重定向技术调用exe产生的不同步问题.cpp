#include <iostream>
#include <io.h>
#include <windows.h>
#include <stdio.h>

using namespace std;

void printFileContent2Console(string filePath){
    char buffer[1024] = {0}; //�����ַ���

    FILE * file = fopen(filePath.c_str(), "r");
	if(NULL == file){
		cout << "filePath not found" << endl;
		return;
	}
    while(NULL != fgets(buffer, 1023, file)){ //fgets��ȡʧ�ܻ��ߵ����ļ�ĩβ ����false�����򷵻�bufferָ��
        cout << buffer;
    }
    fclose(file);
}


int main(int argc, char ** args){
	string exePath = "C:\\Users\\Administrator\\desktop\\test.exe";
	string outputFilePath = "C:\\Users\\Administrator\\desktop\\temp.out";

	//Ҫ��ʵ�ֱ�׼����ض�����Ҫ��cmd ֱ�ӵ���Ӧ��exe�������֧�־ͻ��������Ӧ��һ�����������
	HINSTANCE hinstance = ShellExecute(NULL, "open", "cmd", ("/c " + exePath + " >" + outputFilePath).c_str(), NULL, SW_NORMAL);
	//HINSTANCE hinstance = ShellExecute(NULL, "open", exePath.c_str(), (" >" + outputFilePath).c_str(), NULL, SW_HIDE);
    cout << "command : " << (exePath + " >" + outputFilePath) << endl;
    if((long)hinstance < 32){
        cout << ("shell exec fail") << endl;
		return -1;
    }

	//�������һ�����⣬����һ����ֻ�ܵ���cmd��Ӧ�ó�����Ϊ�������룬���������ض���������ļ���������һ���棬�������������ô�����waitforsingleobject�ͳ��˵ȴ�
	//���cmdִ����ɣ��������������ʵ��Ӧ�ó���ִ����������𣬵������ļ���дͬ�����������⡣
	//����������⣬���棬ֻ�����sleep���ܵõ���ȷ�Ľ������waitforsingleobjectû��ʵ����Ҫ��Ч����
    WaitForSingleObject(hinstance, INFINITE);
	//Sleep(1000 * 2);
    cout << ".....detial run result is below..." << endl;
    printFileContent2Console(outputFilePath);
}