#include <stdio.h>

int main(){
	int c;
	while((c=getchar())!='\n'){
		switch(c-'2'){
			case 0: //没有break就会一直向下执行直到遇到break或者switch结束。(接下来的case不用判断一直执行到下一个break)
			case 1: putchar(c+4);
			case 2:putchar(c+4);break;
			case 3:putchar(c+3);
			default:putchar(c+2);break;
		}
	}
	return 0;
}