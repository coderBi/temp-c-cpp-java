#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;

///事实证明   cin>> 操作会忽略掉多个空格
int main(){
	string s = "hello world";
	cout << typeid(s).name() << endl;
	cout << typeid(1).name() << endl;
	cout << typeid(s.begin()).name() << endl;
	char * p = NULL;
	cout << typeid(p).name() << endl;
	return 0;
}