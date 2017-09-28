#include <iostream>
using namespace std;


/*
对操作符<<的重载可以有两种方式：
	1）成员函数的形式，已经在默认的函数与操作符里面(一共有6个)里面是没有<<，所以这里其实是添加了一个新的成员方法operator<<。其有一个参数，表示要输出到的流对象的引用(因为流的拷贝构造函数和赋值运算符都是隐藏的，不能直接传递)
	2）友元函数的重载，这个是对全局的operator<<的重载,其有两个参数，第一个是指定流，第二个是指定要输出的对象.
	3）为了友好和链式调用，函数的返回值应该是输入流的对象的引用（因为在输出对象的过程中，流对象发生了改变，所以流对象不能设置为const类型的引用）
*/

class Test
{
public:
	std::string content;
	Test(const std::string & s):content(s){}
	//添加一个成员函数operator<<
	std::ostream & operator <<(std::ostream & s){
		return s << this->content;
	}
	//友元函数的形式，是对全局的operator<<的重载
	friend std::ostream & operator <<(std::ostream & s, const Test & t){
		return s << t.content;
	}
};

int main(){
	Test t(string("hello world"));
	//使用成员函数调用
	t.operator<<(cout) << endl;
	//使用友元函数调用，具体的细节可以类比new与operator new
	cout << t << endl;
	return 0;
}