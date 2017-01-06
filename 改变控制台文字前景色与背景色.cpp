#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hout, 0xf5); // 设置文本的背景色是白色，前景色是紫色
    
    cout << "hellow console" << endl;
    return 0;
}