//这个文件需要用gcc执行  不能用g++执行，否则会报错
//补充知识点:
//①：对于 void func(){} 这里的func是一个指针常量。按说调用应该 (*func)() 但是为了使用方便C语言里面规定也可以直接使用  func()
//②： 对于 void (*pfunc)(); 定义了一个函数指针变量。由于是变量，不能有函数体。对于 pfunc() 跟 （*pfunc）() 这两个的效果也是一样的。
//③：不支持函数名的二次取地址  也就是 func == &func 但是&&func是错的。 
//④：注意，pfunc != &pfunc 因为pfunc是一个指针变量，对它取地址是得到存这个变量的地址。 &&pfunc 没有意义。

void* a() { return (void*)998; }

unsigned b(void * (*cplusplus)())
{
    return (unsigned)cplusplus();
}

/*
这个函数的参数传递的是int java 也就是一个函数指针。
这个函数返回值是 unsigned(*)(void *(*cplusplus))
这个函数名是 bool
*/
unsigned(* bool(int java))(void * (*cplusplus)())
{
return &b;
}
#include <stdio.h>
int main()
{
	//这一句先执行 bool(100)返回 b函数的地址， 然后执行b函数传入参数是函数 a的地址
	printf("%u\n", (*bool(100))(&a));
	return 0;
}
