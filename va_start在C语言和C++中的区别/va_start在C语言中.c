#include <stdio.h>
#include <stdarg.h> //使用va_list等需要的头文件

/*
	通过比较，下面的va_start执行的结果都是将args的值设置为a后面的一个字节的地址。
	也就是C/C++中这个函数的执行没有区别，因为C和C++中都会将所有的形参进行从右往左的入栈。
*/

void func(int a, ...){
	printf("the address of a is : %x\n", (int)&a);
	va_list args;
	va_start(args,a); //args的指向a的下一个字节
	printf("the address of args is : %x\n", (int)args);
}

int main(){
	int a = 1, b = 2, c = 3;
	func(a,c);	
	return 0;
}