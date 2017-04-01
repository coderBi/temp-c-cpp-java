#include <iostream>
#include <stdlib.h>
using namespace std;

int f1(){
	cout << "f1 functon" << endl;
	return 0;
}
int f2(){
	cout << "f2 functon" << endl;
	return 0;
}

int main(){
	//_onexit(int fun())  这个函数的参数指定的函数返回值必须为int  参数为空
	_onexit(f1);
	_onexit(f2);
	cout << "main function " << endl;

	//打印结果依次是  main function    f2 functon    f1 functon  说明后添加的先执行。
}