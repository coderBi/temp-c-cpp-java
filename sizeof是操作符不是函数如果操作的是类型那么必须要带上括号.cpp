#include <iostream>
using namespace std;

int main(){
	int a = 0;
	cout << sizeof a << endl;
	cout << sizeof(a) << endl;
	cout << sizeof(int) << endl;
	cout << sizeof int << endl; //编译错s误 如果sizeof的操作数是一个类型，这个类型必须使用括号包起来。对于操作数是一个数据的情况括号可有可无
	return 0;
}