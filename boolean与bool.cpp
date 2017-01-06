#include <iostream>
using namespace std;

int main(){
	cout << false <<endl;
	cout << true << endl;
	cout << boolalpha << false << noboolalpha << endl;
	cout << boolalpha << true << noboolalpha << endl;

	cout << "-------" << endl;
	//boolean b = true; //boolean是宏  bool是关键字. boolean 其实是 unsigned char 
	bool b = true;
	cout << boolalpha << b << noboolalpha << endl;
	return 0;
}