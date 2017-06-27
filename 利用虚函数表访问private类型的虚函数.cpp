#include <iostream>
using namespace std;

class P
{
private:
	int testM;
	virtual void print(){cout << "printInP" << endl;}
	virtual void printT(){cout << testM << endl;}
public:
	P(){testM = 100;}
};

class C:public P
{
};

typedef void (*Print)();

int main(){
	C c;
	//获取虚函数表的地址
	int * ptr = (int*)(*((int*)&c + 0));
	Print pr = (Print)*(ptr + 0);  //根据申明的循序虚函数的地址被存放到了虚函数表
	pr();
	//测试访问了成员属性的函数
	pr = (Print)*(ptr + 1); 
	pr();
	//通过指针直接访问对象数据区的testM
	cout << *((int*)&c + 1) << endl;

	/*通过成员函数指针访问private函数
	  提示因为P::printT是private的，所以这里没有权限获取到，
	  直接编译通不过,由于成员函数的指针只有这一种方式传递出来，所以也就只有public的成员函数指针可以传递出来*/
	//void (P::*pfunc)() = &P::printT;
	//(c.*pfunc)();

	return 0;
}