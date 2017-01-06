#include <iostream>
#include <io.h>
#include <windows.h>

using namespace std;

int main(){
	string toMake = "./a/b";
	int result = mkdir(toMake.c_str()); //mkdir 成功返回 0 失败返回 -1。 mkdir不能一次性建立多级目录
	if(result == 0){
		cout << "mkdir 成功" << endl;
	} else {
		cout << "mkdir 失败" << endl;
	}

	//一次性建立多级目录
	toMake = "./z/y/x";
	string execStr = "mkdir " + toMake; //dos下面的mkdir可以一次性建多级目录 。 值得注意的是通过测试发现mkdir在dos下不识别反斜杠
	system(execStr.c_str());
	return 0;
}