#include <iostream>

void func(int flag){
	//static变量只能定义一次，存放在static与全局变量区 所以第一次算是执行了初始化  后面再执行这个函数初始化语句会被略过
	static int var = 1;
	if(flag == 1)
		var++;
	std::cout << var << std::endl;
}

int main(){
	func(0);
	func(1);
	func(0);
	return 0;
}