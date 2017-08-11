#include <iostream>
#include <string.h>
using namespace std;

/*
	strstr(s1,s2): 测试s1字符串中是否存在s2字符串。返回的是第一次出现的位置(地址)，如果不出现，就返回null 
----note：php中也存在相应的函数，如果存在就返回s1中的匹配点之后的字符串。如果不存在就返回false。
*/

int main(){
	const char *s1 = "hello world，welcome to strstr function";
	const char *s2 = "world";
	cout << strstr(s1,s2) << endl;

	//C++ 中使用string类的查找方法find
	string str = "hello world.This is anther world.";
	string toFind = "world";
	//find函数返回的是查到的位置索引。
	cout << str.find(toFind) << endl;
	//rfind函数是从后往前进行查找
	cout << str.rfind(toFind) << endl;
	return 0;
}