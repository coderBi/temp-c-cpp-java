#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

int main(){
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	WORD wOldColorAttrs;
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
 
	// 保存起始环境颜色
	GetConsoleScreenBufferInfo(h, &csbiInfo);
	wOldColorAttrs = csbiInfo.wAttributes;

	int j=0,i=0;
    while(j++<10)
    {
		printf("这是第");
		// 修改为指定颜色
		SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_GREEN);
		printf("%d",j);
		// 重置为原来的环境
		SetConsoleTextAttribute(h, wOldColorAttrs);
		printf("次输出------");
		//for(i=0;i<1000000000;i++);
		Sleep(1000);
		printf("\r"); 
    }
	return 0;
}