/**
	之所以存在这个文件来执行bat文件，是因为实际操作发现，没有办法用cmd参数出入bat文件让它执行。
*/
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;

int main(int argc, char * args[]){
	if(argc != 2){
		cout << "command line must like this:" << endl;
		cout << "execBatFile[.exe] batFilePath" << endl;
		return 0;
	}
	char * filePath = args[1];
	ifstream f(filePath);
	if(NULL == f){
		cout << "batFilePath error!" << endl;
		return 0;
	}
	string lineChars, gotChars;
	while(EOF != f.peek()){
		lineChars = "";
		char peekChar = f.peek();
		while(EOF != peekChar && '\n' != peekChar){ ///windows下面换行是\r\n，程序中只需要处理\n 因为\n写入文件的时候会自动写入\r\n，读入的时候也是\r\n自动修改为\n
			f >> gotChars;
			if(lineChars.length() > 0)
				lineChars += " ";
			lineChars += gotChars;
			peekChar = f.peek();
		}
		f.get(); //将末尾的换行读进来
		if("" == lineChars)
			continue;
		if(lineChars[0] == '@' && lineChars.length() >= 4 && lineChars.substr(1,3) == "rem"
			|| lineChars.length() >= 3 && lineChars.substr(0,3) == "rem") //注释，不打印
				continue;
		cout << "command line: " << lineChars << endl;
		system(lineChars.c_str());
	}
	return 0;
}