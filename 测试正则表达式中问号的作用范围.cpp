#include <iostream>
#include <regex>
using namespace std;


int main(){
	regex r1("aab?.*"), r2("(aab)?.*");
	string totest = "ababab";
	//通过下面的结果，可以知道？只是对前一个字符或者表达式起作用
	cout << boolalpha << regex_match(totest, r1) << endl; //false
	cout << boolalpha << regex_match(totest, r2) << endl; //true
	return 0;
}