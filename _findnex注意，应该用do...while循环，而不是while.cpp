#include <iostream>
#include <io.h>
#include <string.h>

using namespace std;

int main(int argc, char ** args){
	string objDir = "C:\\Users\\Administrator\\Desktop\\obj/";
    _finddata_t fd;
    cout << (objDir + "*.*") << endl;
    long handle = _findfirst((objDir + "*.*").c_str(), &fd);
    if(-1 == handle){ //因为通过上面的判断跟创建，这里没有获取到内容的原因一定是没有一个匹配项
        cout << string("objDir目录下，不存在任何 .o 类型文件") << endl;
        return 0;
    }
    string param = "";
    do{
        cout << "here ... fd.name .....: "  << fd.name << endl;
        if(strcmp(fd.name, ".") == 0 || strcmp(fd.name, "..") == 0){
            cout << "continue" << endl;
            continue;
        }
        param += " " + objDir + fd.name;
    }while(0 == _findnext(handle, &fd));
	cout << "param : " << param << endl;
    _findclose(handle);
	return 0;
}
