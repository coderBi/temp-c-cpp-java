#include <windows.h>
#include <iostream>
using namespace std;



void func(int argc, ...){
    va_list args;
	//��ʼȡֵ  ���еڶ������������� ... ǰ��Ĳ���
    va_start(args, argc);
	char * str = NULL;
	//ȡ������Ĳ��������ҵ���char*����
    for(int i = 0; i < argc; ++i){
		str = va_arg(args,char*);
		cout << i  << ": " << str << endl;
	}
	//����ȡֵ
	va_end(args); 
}

int main(){
	func(3,"hello","world","welcome");
	return 0;
}
