#include <iostream>
#include <regex>
using namespace std;


int main(){
	regex r1("aab?.*"), r2("(aab)?.*");
	string totest = "ababab";
	//ͨ������Ľ��������֪����ֻ�Ƕ�ǰһ���ַ����߱��ʽ������
	cout << boolalpha << regex_match(totest, r1) << endl; //false
	cout << boolalpha << regex_match(totest, r2) << endl; //true
	return 0;
}