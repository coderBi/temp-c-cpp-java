#include<stdio.h>

int main(){
	///通过测试  无论是cpp  还是c  直接\后面加数字，默认的都是八进制转义
	char a = '\101';
	printf("%d.....%c",a,a);
	return 0;
}