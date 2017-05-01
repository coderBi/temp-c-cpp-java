#include <iostream>

class Parent
{
	public: virtual ~Parent(){
		std::cout << "del parent" << std::endl;
	}
};

class Child : public Parent
{
	//注意c++中  编译器会自动在子类的析构函数中插入一句对父类析构的调用  所以不应该出现在子类的析构中显式调用父类的析构
	public: ~Child(){
		std::cout << "del child" << std::endl;
	}
};

int main(int argc, char** args){
	Parent * p = new Child();
	//如果父类的析构不是虚的  这里直接析构父类  会造成子类部分没有释放
	//父类是虚析构  delete p 就会调用子类的析构 由于子类的析构中包含了对父类的析构调用  所以可以正常执行
	delete p;
	return 0;
}