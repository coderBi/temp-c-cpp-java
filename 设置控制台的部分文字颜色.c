#include <stdio.h>  
#include <Windows.h>

/////////////修改控制台对的部分文字的显示颜色////////
  
int main(int argc,char* argv[])  
{  
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);  
	WORD wOldColorAttrs;  
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;  
  
	// 保存原来的控制台属性  用来进行恢复 
	GetConsoleScreenBufferInfo(h, &csbiInfo);  
	wOldColorAttrs = csbiInfo.wAttributes;  
  
	// 红字绿底
	SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_GREEN);  
	printf("This is a test\n");  

	//蓝字红底
	SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY | BACKGROUND_RED);  
	printf("This is a test\n");
  
	// 恢复原来控制台的属性  
	SetConsoleTextAttribute(h, wOldColorAttrs);  
	printf("This is another test\n");
	return 0;
}  