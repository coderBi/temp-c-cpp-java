#include <iostream>
using namespace std;

int main(){
	string str = "xxxx";
	//会暴运行时异常  打印xxxxrelocation protocol version %d 后面的relocation protocol version %d 指示重定位异常
	//分析原因： 由于运算符是从右向左进行的  所以先计算的是 "hello" + 'h' 在c/c++ 中 "hello＂指代的是一个地址 后面的 'h'可以转化为一个数值 这样"hello" + 'h'其实获取到了一个地址。这个地址是常量区域中"hello"向后偏移 'h' 由于这个地址是程序中没有开辟的，所以才会爆出一个relocation protocol version %d 运行时异常
	str += "hello" + 'h';

	//由于上面的异常  str += "一个未开辟的char*地址"，结果成了""
	cout << str << endl;

	//打印relocation protocol version %d 
	cout << "hello" + 'h' << endl;

	//打印前后地址进行比对
	cout << (unsigned)("hello") << endl;
	cout << (unsigned)('h') << endl;
	cout << (unsigned)("hello" + 'h') << endl;

	//下面的语句会爆出 char数组之间不能进行 +
	//str += "hello" + "hh";

	
	//同上会输出 xxxxrelocation protocol version %d
	str = str + "hello" + 'o';
	//跟str += 不一样 这里输出了 helloo 原因不明 可能是编译器进行了某些处理
	cout << str << endl;

	//str 会正常赋值为 anotherello
	str = "another";
	str += "hello" + 1;
	cout << str << endl;
	return 0;
}