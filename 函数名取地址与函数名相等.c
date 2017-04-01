#include <stdio.h>

void func(){

}

int main(){
	printf("equal: %d\n", func == &func); //返回1  表示二者是一样的。
	void (*pfunc)() = NULL;
	printf("存储指针变量的地址: %u",&pfunc);
	return 0;
}