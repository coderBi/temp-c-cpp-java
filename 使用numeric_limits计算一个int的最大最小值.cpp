#include <iostream>
#include <limits>
using namespace std;

/*
	C++中提供了一个std::numeric_limits泛型类，可以获取到各种基础数据类型的最大最小值。其进行计算的方式，就获取一个指定长度二进制位在有符号的情况下的最大最小值。
	----note： 对于char 类型，返回的127（非乱码，但是不便于观察）和-128（乱码）对应的字符为了更清晰的展示结果，这里转为int进行打印展示.
*/

int main(){
	cout << (std::numeric_limits<int>::max()) << endl;
	cout << (std::numeric_limits<int>::min()) << endl;

	cout << (std::numeric_limits<bool>::max()) << endl; //1
	cout << (int)(std::numeric_limits<char>::max()) << endl; //127
	cout << (int)(std::numeric_limits<char>::min()) << endl; //-128
	cout << (std::numeric_limits<short>::max()) << endl;
	cout << (std::numeric_limits<long long>::max()) << endl;
	cout << (std::numeric_limits<float>::max()) << endl;
	cout << (std::numeric_limits<double>::max()) << endl;
	return 0;
}