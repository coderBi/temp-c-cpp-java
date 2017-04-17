#include <windows.h>
#include <iostream>
using namespace std;



void func(int argc, ...){
    va_list args;
	//开始取值  其中第二个参数必须是 ... 前面的参数
    va_start(args, argc);
	char * str = NULL;
	//取出后面的参数，并且当做char*处理
    for(int i = 0; i < argc; ++i){
		str = va_arg(args,char*);
		cout << i  << ": " << str << endl;
	}
	//结束取值
	va_end(args); 
}

int main(){
	func(3,"hello","world","welcome");
	return 0;
}
