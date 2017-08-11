#include <iostream>
using namespace std;

/*
 所谓的指针函数，指的是返回值类型是指针的函数
*/
void* PointerFunc(){
	cout << "this is a function which returns a pointer" << endl;
	return NULL;
}

int main(){
	/*函数指针： 一个指向函数类型的指针，表现为一个函数的名称是指针*/
	void * (*funcPtr)(void) = &PointerFunc;
	(*funcPtr)();
	funcPtr();  //注意，内部机制允许直接使用指针加括号的形式调用

	/*扩展：指针函数数组*/
	void* (*pArr[10])(void) = {0};
	/*扩展：数组不是合法的函数名*/
	//void* pError[2](void); //编译通不过
	return 0;
}