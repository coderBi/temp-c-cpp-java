#include <iostream>
using namespace std;

int & getMax(int & x, int & y){
	return x >= y ? x : y;
}

int main(){
	int x = 1, y = 2;
	cout << "x y : " << x << "  " << y << endl;
	getMax(x, y) = 3; //getMax 返回一引用， 这个引用又是被参数 y初始化 ， y 实参y的引用。所以这里达到了对原来的y的修改。
	cout << "x y : " << x << "  " << y << endl;
	return 0;
}