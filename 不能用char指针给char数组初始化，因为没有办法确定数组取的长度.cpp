#include <iostream>

using namespace std;

int main(){
	char * sql = "hellow";
	unsigned char arr1[] = "hellow"; //可以通过，可以用字面量给char数组赋值。会依次将右边的字面量载入数组中

	unsigned char arr3[] = arr1;  //这一个也不能通过，原因跟下面arr2一样。这里的arr1可以说弱化成了一个指针。

	unsigned char arr2[] = sql;  //不可以通过，因为sql是一个指针变量，这里爆出来没有办法确定arr2的长度。


	return 0;
}