package test1;
import java.io.*;

class Temp
{
	public int a;
	public boolean b;
}

public class Test
{
	public static void main(String args[]){
		Temp cls = new Temp();
		Temp cls1 = cls;
		cls.a = 100;
		System.out.println("cls1.a: "+cls1.a); //因为传递的是引用，所以cls的修改会影响到cls1
	}
}