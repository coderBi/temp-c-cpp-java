#include <iostream>
#include <io.h>
#include <string.h>
#include <windows.h>
using namespace std;

bool checkDirExist(string path){ //检查当前路径的文件夹是否存在
    bool res = true;
    struct _finddata_t fd;
    long handle = _findfirst((path + "*.*").c_str(), &fd); //查找 *.*文件类型
    if(-1 == handle){ //打开一个目录失败，说明不存在
        res = false;
    }
    _findclose(handle);
    return res;
}

//检查文件夹下面是否存在某一种文件类型，这种检查不会进行子目录的遍历。参数type的取值例如: c cpp exe *
bool checkFileTypeInDir(string dir, string type){
    bool toReturn = false;
    if(!checkDirExist(dir)){
        return false;
    }
    _finddata_t fd;
    long handle = _findfirst((dir + "*." + type).c_str(), &fd);
    if(-1 != handle){
        do{
			cout <<fd.name <<endl;
            if(0 == strcmp(fd.name, ".") || 0 == strcmp(fd.name, "..") || _A_SUBDIR & fd.attrib) //不进行子目录的遍历
                continue;
            toReturn = true;
            break;
        }while(_findnext(handle, &fd) == 0);
    }
    _findclose(handle);
    return toReturn;
}

int main(){
	string path = "C:/Users/Administrator/Desktop/obj/", types[] = {"o", "c", "exe", "*"};
	if(checkDirExist(path)){
		cout << path << " 路径存在" << endl;
	}
	for(int i = 0; i < 4; ++i){
		if(checkFileTypeInDir(path, types[i])){
			cout << path << "目录下" << "存在" << types[i] << "文件类型的文件" << endl;
		} else {
			cout << path << "目录下" << "不存在" << types[i] << "文件类型的文件" << endl;
		}
	}
	return 0;
}