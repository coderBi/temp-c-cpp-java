#include <iostream>
#include <stdarg.h>
#include <stdio.h>
using namespace std;

int func(int a, int b, ...){
	va_list va;
	va_start(va,b);
	int next;
	while(next = va_arg(va,int)){
		cout << next << endl;
	}
	va_end(va);
}

int main(){
	//printf中的模式字符串中存在占位符，这里隐含了...中的参数的个数，这样就可以对内部的va_arg进行控制
	printf("%d %d %d %d %d\n", 4,5); //4 5 4 这里的结果由于后面传递的参数的个数不够，会取到垃圾值
	printf("%d %d\n", 1,2,3); //参数传多了 内部的va_arg少执行一次而已

	//由于内存中0是很常见的，所以这里一般会很快的终止
	cout << "----------测试分割线-------------------" << endl;
	func(1,2,3,4,5,6,7); 
}