#include <iostream>

using namespace std;

int main(){
	string s1 = "123456789abcdefghijklmnopqrstuvw";
	s1.erase(0,8);
	s1.erase(16,8); //由于上面已经删除了8，导致s1已经变成了24位，所以这里删除的不是 24~31
	cout << s1 << endl;
	return 0;
}