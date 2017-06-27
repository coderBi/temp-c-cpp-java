#include <iostream>
using namespace std;

void outer(){
	//不允许在函数内部定义函数  只能申明
	void inner();
	cout << "outer" << endl;
}

//由于在函数内部不能进行函数定义 那么另一个函数的定义只能出现在其他的函数的外面，所以没有办法使用到其他函数内部的局部变量，所有c++中不存在闭包的实现
void inner(){
	cout << "inner" << endl;
}

/*补充分析
时间： 2017/6/26
这里补充的原因是：
	1，上面只是分析了一般函数里面不能定义函数，只能申明函数。而外部实现的函数是没有办法直接访问其他函数内部作用的。
	2，对于c++这样的面向对象语言，应该进一步分析内部的成员函数和静态函数的指针外传的情况，看看是不是指针传出去之后，可以直接拿来用.
*/
class Test
{
public:
	//static const char s[] = "static"; //非数字类型的static只能在外部初始化
	static const char s[];
	static void sprint(){cout << s << endl;}
	const char *m;
	Test(const char *m){ this->m = m;}
	void print(){cout << this->m << endl;}
};
const char Test::s[] = "static";  //外部不能带上static申明

int main(){
	//静态函数传递能够成功
	void (*sp)(void) = Test::sprint;
	sp();
	Test * obj = new Test("member");
	//void (*p)(void) = obj->print;  //提示不能用 void(Test::)()转成 void(*)() 也就是这个指针是一个类下面的成员指针
	//由于没有办法直接引用一种叫做 Test::的类型，所以这里不能成功将成员函数的只能传递出来

	//接下来测测试只能到有c++11的环境例如vs中进行了  主要是看看能不能直接用 auto 传类型
	//auto p = obj->print;  //gcc默带的c++版本太低  这里只是写在这里  等待进一步的验证
	//上面代码在vs中测试结果是：提示函数调用缺少参数列表，所以让写成如下形式来获取成员函数指针
	//auto p = &Test::print; //p的类型是 void(Test::*)()
	
	//void(Test::*p)() = &obj->print;  //ios c++ 禁止了用一个成员函数的地址去填充一个成员函数指针(绑定成员函数上的非法操作)，明确指出只能 p = &Test::print;
	void(Test::*p)() = &Test::print;
	//(obj->(*p)();  //通过测试好像对于成员指针的调用格式只能是 (a.*p)() 或者 (pa->*p)() 
	//这里的 *p不能作为一个部分包裹起来 否则会报出一个成员指针前面不能使用医院运算符 * 的错误。所以可以理解为 ->* .* 是一个整体的二元运算符
	(obj->*p)();  //写到这里 可以发现由于c++中即使可以得到成员的指针  但是调用的时候一定是前面书写一个调用对象。而且没有办法 &a.func 所以说类中也不存在返回闭包的可能
	return 0;
}
