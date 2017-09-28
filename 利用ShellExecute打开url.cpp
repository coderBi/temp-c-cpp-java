#include <iostream>
#include <windows.h>
#include <fstream>
using namespace std;

int main(){
	ShellExecute(NULL,"open","http://baidu.com",NULL,NULL,SW_NORMAL); 
	return 0;
}