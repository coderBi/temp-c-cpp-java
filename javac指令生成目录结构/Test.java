package test.ed; //有了目录结构， javac 如果需要在当前文件下面建立目录结构需要加上 java Test.java -d .
				//同时 java指令，后面的类名需要是全的，否则会找不到，也就是 java test.ed.Main才行
import java.io.*; 

public class Test
{
	public static void main(String[] args){
		System.out.println("hellow test.java");
	}
}
