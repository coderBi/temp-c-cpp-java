#include <iostream>
using namespace std;

void outer(){
	//不允许在函数内部定义函数  只能申明
	void inner();
	cout << "outer" << endl;
}

//由于在函数内部不能进行函数定义 那么另一个函数的定义只能出现在其他的函数的外面，所以没有办法使用到其他函数内部的局部变量，所有c++中不存在闭包的实现
void inner(){
	cout << "inner" << endl;
}

int main(){

	return 0;
}