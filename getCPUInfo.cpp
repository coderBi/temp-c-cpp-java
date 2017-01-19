//得到cpu 信息

#include <stdio.h>
#include <windows.h>

int main(){
	SYSTEM_INFO sysInfo;
	GetSystemInfo(&sysInfo);
	printf("中央处理器架构(返回的是处理器掩码)：%u\n", sysInfo.wProcessorArchitecture); //主流的cpu架构有intel amd等
	printf("处理器的数量%u\n", sysInfo.dwNumberOfProcessors);
	printf("处理器级别：%u\n", sysInfo.wProcessorLevel);
	printf("处理器类型: %u\n", sysInfo.dwProcessorType);
	printf("处理器版本：%u\n", sysInfo.wProcessorRevision);
	printf("最大寻址单元：%u\n", sysInfo.lpMaximumApplicationAddress);
	printf("最小寻址单元：%u\n", sysInfo.lpMinimumApplicationAddress);
	return 0;
}