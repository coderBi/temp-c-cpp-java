#include<iostream>
using std::cin;
using std::cout;
using std::endl;

int main(){
	int a;
	while(cin >> a){
		cout << "a * a * a:  " << a * a * a << endl;
		//通过测试下面的常量表达式的类型跟输入的类型一致
		cout << "sizeof(a * a *a):  " << sizeof(a * a *a) << endl;
		cout << "sizeof(10000 * 10000 *10000):  " << sizeof(10000 * 10000 *10000) << endl;
	}
	return 0;
}
