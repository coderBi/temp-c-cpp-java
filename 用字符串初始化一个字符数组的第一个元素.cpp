#include <iostream>
using namespace std;

/*
来源:
	看到一种书写的方式: char str[] = {"hello"}，怀疑这种写法的执行结果，个人的理解是用"hello"中的第一个元素也就是'h'初始化了str[0]，然后str的长度只有1. 但是实际运用中结果好像是和 char str[] = "hello"的效果一样
结论：
	char str[] = {"hello"}  和 char str[] = "hello" 只是写法上不一样，其实是一个意思
*/

int main(){
	char str[] = {"hello"};
	cout << str << endl;  //打印的结果是hello

	char str1[] = "hello";
	cout << str1 << endl;  //打印结果hello

	//char str2[2] = {"hello"};  //出错，提示用于初始化数组的字符串太长

	//char str3[] = {"hello", "world"}; //显示too many initiallizers for char[]  也就是给的初始化的数据太多了。

	/*
		通过上面的总结 char str[] = {"hello"}  和 char str[] = "hello" 只是写法上不一样，其实是一个意思
	*/
	return 0;
}