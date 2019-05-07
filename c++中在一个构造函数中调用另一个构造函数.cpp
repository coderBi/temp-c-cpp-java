#include <iostream>
#include <regex>

using namespace std;

class Test1{
	public:
		int num;
	public:
		Test1(){
			Test1(100);
		}
		Test1(int num){
			this->num = num;
		}	
};
class Test2{
	public:
		int num;
	public:
		Test2(){
			new (this)Test2(100); //在this指向的空间去创建这个对象，会对this进行覆盖(this本身是不可修改的没有办法this = new之类的操作)
		}
		Test2(int num){
			this->num = num;
		}	
};

int main(){
	Test1 t1;
	cout << t1.num << endl; //垃圾值，因为在构造函数中使用的那个Test1(100)其实是创建了一个临时对象
	Test2 t2;
	cout << t2.num << endl; //100，因为内部使用的new操作是在this指向的空间进行开辟的(这么使用前提是自己认为是合理的)
	return 0;
}