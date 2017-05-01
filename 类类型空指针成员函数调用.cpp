#include <iostream>
using namespace std;

class NullObj
{
	public:
		void func(){
			if(!this){
				cout << "xxx" << endl;
			}
			else{
				cout << "normal output" << endl;	
			}
		}
};

int main(){
	NullObj * p = NULL;
	//正常输出，因为没有访问到null后面的成员变量所以没有报错，内部的this指针是NULL
	p->func();

	//内部指针不是null
	NullObj obj;
	obj.func();
	return 0;
}