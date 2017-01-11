#include <iostream>
using namespace std;

class Test
{
	public:
		static int s;
		int a;
		enum{one,two,three};
};
int main(){
	cout << sizeof(Test) << endl; //结果为4  static变量不占sizeof . enum{one,two,three}后面并没有定义变量，这里只是符号，也不占sizeof
	return 0;
}