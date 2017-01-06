#include <iostream>

using namespace std;

int main(int argc, char ** args){
	cout << "argc : " << argc << endl;
	cout << "程序的名称是： " << args[0] << endl; //argc至少是 1 ，因为 args中第一个是 程序的名称
	for(int i = 1; i < argc; ++i){
		cout << "第 "  << i << " 个参数是： " << args[i] << endl;
	}
	return 0;
}