#include <iostream>
#include <io.h>
#include <windows.h>
#include <stdio.h>
#include <sys/types.h>
//fcntl.h里面定义了一系列的宏，用来更清晰的表示io中函数操作类型。
#include <fcntl.h>

using namespace std;

int main(int argc, char ** args){
	string filePath = "c:/users/administrator/desktop/temp.out";

    Sleep(3 * 1000);

    //_access 判断文件是否可以获取某种权限。第一个参数是文件路径，第二个参数是存在以下几个可能：
    // 0： 判断文件是否存在  2：判断写权限  4： 判断读权限  6： 判断读写权限
    //判断是否存在
    if(_access(filePath.c_str(), 0) == -1){
        cout << "file exist : false" << endl;
    }else {
        cout << "file exist : true" << endl;
    }

    //判断读权限
    if(_access(filePath.c_str(), 4) == -1){
        cout << "can read : false" << endl;
    }else {
        cout << "can read : true" << endl;
    }

    //判断写权限. 这里通过打开文件并且sleep 2秒， 证明纯 C的底层是没有处理同时写入的问题的
    if(_access(filePath.c_str(), 2) == -1){
        cout << "can write : false" << endl;
    }else {
        cout << "can write : true" << endl;
        int hp = _open(filePath.c_str(), _O_WRONLY); //以写的方式打开这个文件
        if(hp != -1){ //打开成功了
            cout << "open file with write mode, and will sleep 2 second below" << endl;
            Sleep(2*1000);
            _close(hp);
        }
    }

    //判断读写权限
    if(_access(filePath.c_str(), 6) == -1){
        cout << "can read and write : false" << endl;
    }else {
        cout << "can read and write : true" << endl;
    }

    Sleep(3 * 1000);
}
