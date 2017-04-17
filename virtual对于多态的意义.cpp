#include<iostream>
using namespace std;


class Test1
{
public:
	int a;
	Test1(int a){
		this->a = a;
	}
	void printA(){
		cout << a << endl;
	}
	void printB(){
		cout << "printB int Test1: "<< a << endl;
	}
	virtual void printC(){
		cout << "printC int Test1: "<< a << endl;
	}
};

class Test2 : public Test1
{
private:
	int a;
public:
	Test2(int a):Test1(a+10){
		this->a = a;
	}
	void printB(){
		cout << "printB int Test2: "<< a << endl;
	}
	void printC(){
		cout << "printC int Test2: "<< a << endl;
	}
};

int main(void)
{
	Test2 t(1);
	Test1 & t1 = t;
	//分析 printA并没有被覆盖，所有，pintA是父类的函数，父类的函数访问域在父类。
	t1.printA();
	//依然调用的父类函数，这里因为父类的函数不是virtual的，所以没有触发多态
	t1.printB();
	
	//有virtual关键字 子类有重写 实现多态
	t1.printC();
	return 0;
} 