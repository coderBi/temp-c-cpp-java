#include <iostream>
using namespace std;

class Test
{
public:
	static const int s = 1; //除了const修饰的数字这样的简单类型，其他的static类型需要在类外部初始化，并且外部定义的时候不能带static关键字
	static void sprint(){cout << s << endl;}
	int m;
	Test(int m){this->m = m;}
	void print(){cout << this->m << endl;}
	virtual void vprint(){cout << "vprint in Test" << endl;}
private:
	void pprint(){cout << "pprint in Test" << endl;}
};

class Another:public Test
{
public:
	Another(int m):Test(m){}
	virtual void vprint(){cout << "vprint in Another" << endl;}
};

int main(){
	//类的静态函数  直接和一般函数一样用指针接收使用
	void (*sp)() = Test::sprint;
	sp();

	Test a(100);
	//类的成员函数不能直接 &a.func ISO C++ 禁止这一行为
	//void (Test::*p)() = &a.print;

	//类的成员函数指针的使用  只能通过 &Test::print获取到  然后使用a. 或者 ptr->使用
	void (Test::*p)() = &Test::print;
	(a.*p)(); //固有模式  这里（a.*p）获取到一个对象的绑定成员函数地址  如果写成 (a.(*p))会报错，提示不能将医院运算符作用在一个成员指针上  所以这里可以理解为 .* ->*是一个二元运算符

	//虚函数指针使用
	void (Test::*vp)() = &Test::vprint;
	(a.*vp)();
	//vp = &Another::vprint;  // 不能从 void(Another::*)()转换到 void(Test::*)()
	Another an(120);
	(an.*vp)();  //这里打印的是 Another子类的输出，可以注意到虚函数的指针vp在访问的时候会到虚函数映射表进行偏移
	return 0;
}