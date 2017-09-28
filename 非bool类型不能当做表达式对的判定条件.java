package test.condition.nonbool;
import java.io.*;


class Main
{
	/*note: 参数String args[] 或者写成 String[] args 是完全一样的，虽然语义上解析有点不同，但是二者是完全一样的
		---碰到一个很坑的问题：就是这里的单行注释内容中如果存在中文，不能用一行结束，否则在windows的cmd (默认gbk编码)环境中会报一个错误(不是警告，是错误！下面的单行注释没有这个问题)
	*/
	public static void main(String args[]){
		//编译通不过，java中的条件表达式只能是bool或者是返回值是bool类型的表达式，这里给了一个int不能用来做条件
		/*
		if(2){
			System.out.println("yes that's ok");
		}else{
			System.out.println("the condition does not match");
		}
		//*/
		//不像C/C++ php js等直接与0相比较出结果。java中的条件表达式必须是bool类型或者是返回bool类型的表达式
		if(2 != 0){
			System.out.println("yes that's ok");
		}else{
			System.out.println("the condition does not match");
		}
	}
}