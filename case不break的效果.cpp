#include <iostream>
using namespace std;

/*
	 1）如果在一个case下面没有使用break或者continue这样的跳出switch的控制语句，那么程序会执行完当前的case的代码之后接着执行后面的case的代码，一直到遇到第一个case或者完成所有的switch执行体。
	 2）在上述的分析中，如果一个case中没有break（或者continue或者return），那么会直接执行下一个case的执行代码，在这个过程中并不会再次对其他的case进行判断（默认成立），之后执行代码直到switch体的尾部或者是break之类的控制退出switch的语句的位置。
*/

void test(int a){
	switch(a){
		case 1:
			cout << 1 << endl;
		case 2:
			cout << 2 << endl;
		case 3:
			cout << 3 << endl;
			break;
		case 4:
			cout << 4 << endl;
		default:
			cout << "default" <<endl;
			break;
	}
}

int main(){
	test(0);  //default
	cout << "----------测试分割线-----------------" << endl;
	test(1); //1 2 3
	cout << "----------测试分割线-----------------" << endl;
	test(2); // 2 3
	cout << "----------测试分割线-----------------" << endl;
	test(3); // 3
	cout << "----------测试分割线-----------------" << endl;
	test(4); // 4 default
	cout << "----------测试分割线-----------------" << endl;
	test(5); //default
}