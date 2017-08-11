#include <iostream>
usingnamespace std;

/*
	在C++中无论是使用string.length  还是使用string.size都可以获取到一个字符串的长度。二者的结果是一样的，只是size一般用于容器，length一般用于表示字符串，由于length也算是一个容器，所以拥有size方法
*/

int main(){
	std::string str = "str";
	cout << str.size() << endl; //3
	cout << str.length() << endl; //3
	return 0;
}