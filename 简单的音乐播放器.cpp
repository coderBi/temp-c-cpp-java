/**
	播放音乐 加载图片 简单的音乐播放器
*/
#include <graphics.h> //easyx的库。需要安装
#include <mmsystem.h>
#include <windows.h>
#pragma comment(lib, "winmm.lib")

int main(){
	mciSendString("open 1.mp3 alias back", 0, 0, 0);
	mciSendString("play back", 0, 0, 0);

	initgraph(300,300);
	IMAGE bg;
	loadimage(&bg, "./image/bkg.jpg", 300, 300); //函数不支持png
	putimage(0, 0, &bg);
	system("pause");
	closegraph();
	return 0;
}