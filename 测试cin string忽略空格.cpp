#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
	//通过打印的结果，发现cin的 string s里面不会保存前后的空格，并且前面有空格被无视  后面有空格输入终止。
	string s;
	cin >> s;
	cout << "s.length(): " << s.length() << endl;
	cout << "s: " << s << endl;
	getchar(); //getch输入一个字符，不用回车就结束了。但是getchar要等回车代表输入完成。然后返回输入的第一个字符。
	return 0;
}