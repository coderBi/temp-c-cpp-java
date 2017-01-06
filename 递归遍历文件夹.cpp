#include <iostream>
#include <io.h>
#include <string.h>
using namespace std;

string addHead = "-"; //每一级目录与上一级目录的缩进字符串

void goThroughFolder(string path, string lastHead){
	_finddata_t fd;
	//可以用 *.* 或者 * 遍历文件夹 //这里为什么 *.* 可以匹配到名称中不带. 的文件夹机制不清
    long handle = _findfirst((path + "*.*").c_str(), &fd);
    if(-1 != handle){
        do{
            cout << lastHead << fd.name << endl;
			if(_A_SUBDIR & fd.attrib && strcmp(fd.name,".") != 0 && strcmp(fd.name, "..") != 0){
				goThroughFolder(path  + fd.name + "/", lastHead + addHead);
			}
        }while(_findnext(handle, &fd) == 0);
    }
    _findclose(handle);
}

int main(){
	string path = "C:\\Users\\Administrator\\Desktop\\obj\\";
    goThroughFolder(path, "");
	return 0;
}