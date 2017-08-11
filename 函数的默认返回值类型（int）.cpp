#include <iostream>
using namespace std;

/*
	1)下面的测试说明：C/C++中 函数的默认返回值是int。所以如果是没有返回值，应该明确的书写为void
	2)对于int类型返回值的函数，如果没有提供返回值，通过查询知道这个返回的是一个垃圾值，对于不同的编译器这个是未定义的。
*/

func(int arr[], int length){
	if(!arr || length <= 0)
		return  -1;
	return "hello world"; //这里报错，提示不能从const char * 转换为int
}

int main(){
	int arr[] = {1,2,3};
	cout << func(arr,3) << endl;
	return 0;
}