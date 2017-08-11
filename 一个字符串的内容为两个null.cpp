#include <iostream>
#include <string.h>
using namespace std;

/*
	C/C++会在字符串的末尾追加上'\0' 即使是用户所给定的字符串中存在了 '\0'
	如果程序员在一个字符串的末尾手动的加上了一个null，那么这个字符串就有了两个null结尾。
*/

int main(){
	char s[] = "\0\0\0";
	cout << sizeof s << endl; //4
	cout << strlen(s) << endl; //0
	std::string str = "str";
	cout << str.size() << endl;
	cout << str.length() << endl;
	return 0;
}