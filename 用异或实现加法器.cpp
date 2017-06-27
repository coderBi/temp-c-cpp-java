/*这个文件用异或运算来实现一个加法运算
 *之所以这么做，是基于一点，就是很多地方会提到，异或运算可以加速加法。
 *这里不仅对算法进行了实践，还比较了原始加法与异或实现的使用时间差别，这种比较应该是基于一定次数的运算比较
*/

/*运行与测试结果说明
 *1，算法逻辑与测试完整有效
 *2, 一般性验证，自己实现的异或替换的加法器运行效率可能要比内部加法器多出数量级的时间
 *3，书上或者网络上说的异或代替加法进行加数，应该是有条件前提的。这个文件的书写经历说明这个前提条件是：相加的两个数相与的结果为0。这样是
 *	可以直接一次异或就得到结果的。例如 31 + 13 * 32 由于这两个数高地位为1的错开，相加的结果就是异或的结果。
*/

#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

/*用异或实现加法器*/
/*XOR: exclusive or  异或*/
/*@param int a: 加数*/
/*@param int b: 被加数*/
/*@return int: 最终的两个数相加的结果*/
int PlusImplWithXOR(int a, int b){
	/*两个数异或得到的是剔除掉进位的部分  而两个数与运算的结果左移一位是需要加上的进位结果*/
	int _and = a & b, _xor = a ^ b; //两个数的与结果  两个数的异或结果
	if(0 == _and)
		//两个数与运算的结果为0  表示没有两位都是1的 所以不可能存在进位  这个时候两个数的异或结果与相加的结果相同
		return _xor;
	//上一次的与为1的位说明两个数那一位都是1 那么就表示出现了进位。这里将这个与左移一位，也就得到应该加上的进位数
	_and <<= 1;
	//尾递归 异或 + 额外的进位
	return PlusImplWithXOR(_xor, _and);
}

int main(){
	/*测试PlusImplWithXOR的算法正确性*/
	cout << PlusImplWithXOR(123,321) << "---" << (123+321) << endl
		<< PlusImplWithXOR(134582,1591759) << "---" << (134582+1591759) << endl 
		<< PlusImplWithXOR(1425,32662989) << "---" << (1425+32662989) << endl;
	
	/*--------比较两个加法的效率------------------*/
	int arr[100] = {0}; //模拟数据
	/*随机填充数组*/
	//time()返回的是时间戳 单位是long
	srand((unsigned int)time(NULL));
	for(int i = 0; i < 100; ++i){
		//rand返回的是一个long 这里刚好匹配 不用进行类型转换
		arr[i] = rand();
	}
	clock_t t1, t2, t3, t4; //分别存第一次测试前时间  第一次测试后时间  第二次测试前时间  第二次测试后时间
	int result = 0;  //存结果
	/*测试原生加法运算时间*/
	//clock函数  获取这个程序启动之后到现在的时间  单位是毫秒 类型为int(clock_t这里是int)
	t1 = clock();
	//大量数据模拟
	for(int j = 0; j < 1000000; ++j){
		for(int i = 0; i < 99; ++i){
			result = arr[i] + arr[i+1];
		}
	}
	t2 = clock();
	cout << "normal plus operation costs " << t2 - t1 << " milliseconds" << endl;

	/*测试用异或实现的加法的运行速度*/
	t3 = clock();
	//大量数据模拟
	for(int j = 0; j < 1000000; ++j){
		for(int i = 0; i < 99; ++i){
			result = PlusImplWithXOR(arr[i], arr[i+1]);
		}
	}
	t4 = clock();
	cout << "the plus implemented with XOR  costs " << t4 - t3 << " milliseconds" << endl;
}