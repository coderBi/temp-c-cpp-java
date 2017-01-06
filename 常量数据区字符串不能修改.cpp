#include <iostream>
#include <string.h>
using namespace std;

int main(){
	char str[][20] = {"xx","yy"};  //如果写成 char * str[] = {"", ""} 这是指针数组，一堆的指针指向常量区，不能进行下面的strcpy
	strcpy(str[0],"hellow world");
	cout << sizeof(str) << endl;  //40
	for(int i = 0; i < 2; ++i){
		cout << str[i] << endl;
	}
	return 0;
}