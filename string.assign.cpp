#include <iostream>
#include <string>
using namespace std;

///事实证明   cin>> 操作会忽略掉多个空格
int main(){
	string s = "hello world";
	string s2 = "xxx";
	//string.assign()将一个string清空然后附上新值 参数(string,start,count)
	s2.assign(s,1,2);
	cout << s2 << endl;
	string s3 = " ";
	//参数(p1,p2)
	s3.assign(s.begin()+2,s.end());
	cout << s3 << endl;
	return 0;
}