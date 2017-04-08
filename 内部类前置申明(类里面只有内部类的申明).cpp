#include<iostream>
using namespace std;

/**
-------内部类，前置申明，在内部只有申明，所以只能用指针或者引用，没有办法进行初始化空间。
-------类或结构体的前向声明只能用来定义指针对象或引用，因为编译到这里时还没有发现定义，不知道该类或者结构的内部成员，没有办法具体的构造一个对象，所以会报错。
将类成员改成指针就好了。 程序中使用incomplete type实现前置声明有助与实现数据的隐藏。要求调用对象的程序段只能使用声明对象的引用或者指针。

在显式声明异常规范的时候不能使用incomplete type。
*/

class a
{
public:
	//申明一个内部类
	class b;
	/// b  test;  //这么使用会报错，因为这个语句前面只有一个申明，所以没有办法进行初始化
	b * ptest;  //这个使用合法，因为定义这个指针只需要前面的申明
};

//内部类定义
class a::b{
public:
	int x;
};


class c
{
public:
	//定义一个内部类
	class d
	{
	public:
		int x;
	};
	d dtest;
};
int main(void)
{
	a a1;
	c c1;
	a1.ptest = new a::b;
	a1.ptest->x = 1;
	c1.dtest.x = 1;
} 