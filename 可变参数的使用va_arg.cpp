#include <windows.h>
#include <iostream>
using namespace std;

/*
va_arg分析：
	va_list 其实是一个void*指针，这种调用其实算是fast调用。
	在...的前面的变量会进行传递，...代表的变量会依次从右往左入栈，而va_list args就是用来保存这个栈顶的。
	va_arg(args,int)是从栈中pop出一个int，并且会修改栈顶指针args。
	va_end是必须的，如果在去完值之后没有调用va_end函数可能会导致栈不能正常恢复引起崩溃。
note：
	关于va_arg应该何时终止问题，一般的处理策略可以在...的形参的前面指定一个参数保留后面的...中存储的参数的个数。另一种方式是在...中控制最后一个输入的内容（常常是用0），最后一个元素被用作哨兵位。
	向printf这样的函数，在模式字符串中存在占位符，而后面的...中的代表的参数的个数其实与占位符进行对应，这样就达到了控制结尾的效果。
*/

void func(int argc, ...){
    va_list args;
	//开始取值  其中第二个参数必须是 ... 前面的参数
    va_start(args, argc);
	char * str = NULL;
	//取出后面的参数，并且当做char*处理
    for(int i = 0; i < argc; ++i){
		str = va_arg(args,char*);
		//以下可以看到args这个指针的变动
		cout << i << ": " << (int)args  << ": " << str << endl;
	}
	//结束取值
	va_end(args); 

	//再次取值
	va_start(args,argc);
	cout << "va again: " << va_arg(args,char*) << endl;
}

int main(){
	func(2,"hello","world","welcome");
	return 0;
}
