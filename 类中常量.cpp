#include <iostream>
using namespace std;

class Test
{
	typedef int DEF;
	public:
		enum t{zero, one, two} en; //enum{zero, one, two} 表示一个枚举类型，是符号(其实跟类里面的函数名差不多)。 en是一个变量。
		//下面如果没有static修饰，在c++11之前不能这样初始化
		static const int cnst = 1; //c语言中的const修饰 “常变量”，本质上是变量，只有初始化可以赋值。但是c++里面const修饰表示常量。因此c里面不可以int a[n],但是c++里面可以int a[n]
};

int main(){
	cout << Test::cnst << endl; //报错，既是是常量，因为不是static的，需要this指针访问。
	cout << Test::zero << endl;
	///Test::DEF i = 1; //typedef的类型也收private限制。
	Test::t e = Test::two; //定义的public类型，可以在外面使用
	Test t1, t2;
	cout << t1.zero << endl;
	//cout << &(t1.zero) << endl; //出错，t1.zero 不能被取址,枚举里面的其实是符号，在编译阶段处理。
	cout << &t1.en << endl;
	cout << &t2.en << endl; 
	return 0;
}