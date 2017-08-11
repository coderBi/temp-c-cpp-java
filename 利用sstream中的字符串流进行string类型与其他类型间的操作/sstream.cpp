#include <iostream>
#include <sstream>  //其中有三个流 ostringsteam istringstream  stringstream 
using namespace std;

/*
	传统的字符串操作，经常用sprintf或者是 字符串的简单+
	在C++中一般字符串是std::string类型的，要处理其他的类型与string类型的转换和拼接，一般更好的处理是利用sstream中的三个流特别是 ostringsteam进行操作.
	在C++11中新增了一批to_string()的重载函数，用来支持常用的数据类型到std::string的转化.
*/

/*
	这里利用ostringstream来设计一个to_string函数
*/
std::string to_string(int n){
	ostringstream stream;
	stream << n; //利用流将int类型加入
	return stream.str();  //取出stream中的字符串
}

/*
	利用流从一个字符串中读取一个int
	注意通过C语言的细节，已经知道，这个内部实现是从第一个char一直查询到第一个不在('0'~'9')的字符。这一段就是要取得的一个int。当然，除了上面的字符串中的字符的值的限制，实际中还要考虑int的位数。
*/
int get_int_from_string(string str){
	istringstream stream(str);  //传入一个string 构造一个流
	int n;
	stream >> n; //从stream中读入一个int
	return n;
}

int main(){
	string test = "100hello " + to_string(11111);
	cout << test << endl;  //输出hello 11111
	cout << get_int_from_string(test) << endl;  //获取到100
	return 0;
}