#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

int main(){
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	WORD wOldColorAttrs;
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
 
	// ������ʼ������ɫ
	GetConsoleScreenBufferInfo(h, &csbiInfo);
	wOldColorAttrs = csbiInfo.wAttributes;

	int j=0,i=0;
    while(j++<10)
    {
		printf("���ǵ�");
		// �޸�Ϊָ����ɫ
		SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_GREEN);
		printf("%d",j);
		// ����Ϊԭ���Ļ���
		SetConsoleTextAttribute(h, wOldColorAttrs);
		printf("�����------");
		//for(i=0;i<1000000000;i++);
		Sleep(1000);
		printf("\r"); 
    }
	return 0;
}