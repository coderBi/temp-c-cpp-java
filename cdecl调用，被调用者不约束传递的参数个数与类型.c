#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

/*
	cdecl是C Declaration的缩写，是默认的C语言调用方式。
	cdel的调用方式，是由调用者清理栈，函数翻译之后的名称是_function，所以编译阶段传递多了或者少了参数都不会报错
*/
void func(int x, ...){
	//假设传递了两个参数
	va_list args;
	va_start(args,x); //第二个参数指示从x之后开始取值
	int num, i;

	for(i = 0; i < 2; i++){
		num = va_arg(args,int); //取出一个参数，并且转换为int
		printf("%d----",num);
	}
	printf("\n");
	va_end(args);
}

int main(){
	//可以看到，由于cdecl是由调用者清理栈空间，所以被调用者是不在意你传了多少个参数的。
	func(1,2,3,4,12,1242,35,23);
	return 0;
}