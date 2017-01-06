#include <iostream>
#include <stdio.h>
#include <stdarg.h>

using namespace std;

#define method1(x) ({method2(x);method3(x);})
#define method2(x) ({x++;})
#define method3(x) ({x=x+3;})
#define print(x) ({fprintf(stdout,#x);})

int main(){
	int x = 1;
	cout << method1(x) << endl; //宏里面的 ({})会返回最后一条语句的返回结果
	x <<= 3;
	cout << x << endl; //注意由于宏是替换，所以函数里面直接操作的源数据，上面x左移之前就已经是 5了。
	print(1);
	print(4);
	fprintf(stdout,"\nxxx","afja\n");
	return 0;
}