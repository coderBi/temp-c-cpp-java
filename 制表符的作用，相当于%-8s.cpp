#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main(int argc, char ** args){
	/*
		①：java中\t 占8字符，而c++里面通过下面的打印结果， \t 占 4字符，如果只有英文字符，在前面的字符串小于4长度的时候相当于 %-4s （如果等于\t成了追加）
		②：java里面 %4s 每一个s中字符 可以表示中文也可以表示英文，而c++中一个中文占了两个
	*/
	string str = "xxx和";
	printf("%-8s%d\n", str.c_str(), 1);
	printf("%-4s%d\n", str.c_str(), 2);
	printf("%s%s\n", str.c_str(),"\t3");
	return 0;
}