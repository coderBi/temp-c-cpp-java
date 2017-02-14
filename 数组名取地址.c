#include <stdio.h>

int main(){
	char arr[10];
	//下面两种写法都是定位到一片连续存储区的首地址。
	printf("%u\n", &arr); //数组名只是代码区的一个符号，并没有分配内存，所以对它取地址尽管也得到了结果，但这时候类型已经变成了 char **
	printf("%u\n", arr); //上下两个结果一样的。对arr取地址也是首地址(类型char**)，而arr本身代表首地址。
	//printf("%u\n", &&arr); //出错，因为实际 &&写法不对。
	
	char dArr[2][5] = {{0}};
	scanf("%s", dArr); //输入 hell_ly
	printf("%s", dArr); //可以正常输出hell_ly 因为dArr指向一片连续存储区，像里面灌入一些数据而已。
	return 0;
}