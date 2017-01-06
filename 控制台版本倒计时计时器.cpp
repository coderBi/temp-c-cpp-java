#include <conio.h>
#include <iostream>
#include <windows.h>
using namespace std;

int main(){
	int c;
	int t;
	HANDLE hout; //控制台句柄
	COORD coord; //屏幕坐标
	CONSOLE_SCREEN_BUFFER_INFO csbi; //控制台屏幕缓冲区信息

	//得到控制台句柄
	hout = GetStdHandle(STD_OUTPUT_HANDLE);

	cout << "input the time to count: ";
	cin >>  t;
	
	int preX = 0;
	do{
		cout << "current count : ";
		cout << t;
		GetConsoleScreenBufferInfo(hout,&csbi);
		coord.X = csbi.dwCursorPosition.X;
		coord.Y = csbi.dwCursorPosition.Y;
		for(int i = coord.X; i <= preX; ++i){
			cout << " ";
		}
		preX = coord.X;
		coord.X = 0;
		SetConsoleCursorPosition(hout,coord);
		Sleep(1000); //一秒钟执行一次
	}while(--t >= 0);
	return 0;
}