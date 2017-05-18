#include <iostream>
using namespace std;

//////////////////临时(匿名)变量 进行引用传递的时候  不允许进行非const引用传递。 ////

class C{
public:
	int a;
	static C create(){
		C temp;
		return temp;
	}
	static void do1(C &tmp){
		cout << "do1" << endl;
	}
	static void do2(const C &tmp){
		cout << "do2" << endl;
	}
	static void do3(C tmp){
		cout << "do3" << endl;
	}
	C(){
		a = 1;
	}
};

int main(){
	//对一个临时变量进行非const引用传递 C++中不允许，会出现编译错误
	//C::do1(C());

	//进行const引用传递  可以
	C::do2(C());

	//直接传递对象  对象里面默认有一个浅拷贝
	C::do3(C());
	return 0;
}