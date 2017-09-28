#include <iostream>
using namespace std;

/*
C++中的struct的主要特定有：
	1）成员默认的属性是public的，而C++中class中的默认的权限是private的
	2) struct和class一样，可以有各种构造函数
	3）struct也有继承和多态。
*/

struct A
{
	int a;
	int b;
	A(){
		a = 10;
		b = 100;
	}
	virtual void vFunc(){
		cout << "a: " << a << endl;
	}
};

struct B : public A
{
private:
	int b; //私有，这里对父struct的变量进行了继承并且设置了更小的权限
public:
	void vFunc(){
		cout << "b: " << b << endl;
	}
};

int main(){
	B b;
	A & a = b;
	a.vFunc(); //输出 b:垃圾值。  实现了多态，由于B中对变量b进行了覆盖，这里调用的结果会由于b没有初始化而是垃圾值

	B another(); //这里如果
	another.vFunc();
	return 0;
}