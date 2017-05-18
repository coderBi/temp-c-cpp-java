#include <iostream>
#include <typeinfo>
using namespace std;

int main(){
	int x = 100;
	//可以发现 !!x的类型是bool的
	cout << typeid(!!x).name() << endl << !!x << endl;
	//!!x 由于是bool的  进行计算就只能是 0 或者 1
	cout << 1/(!!x) << endl;
	cout << typeid(!!110).name() << endl;
	return 0;
}