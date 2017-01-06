#include <io.h>
#include <iostream>
#include <errno.h>
#include <sys/stat.h>

using namespace std;

int main()
{
    /*
        _stat 可以获取文件或者文件夹的状态信息
    */
    string filePath = "c:/users/administrator/desktop/temp.out";
    struct _stat buff; //存获取到的信息

    int res = _stat(filePath.c_str(), &buff); //成功返回0 失败返回-1 如果失败可以通errno获取相应的错误代码
    if(-1 == res){
        cout << "get file stat info fail, the err code is : " << errno << endl;
        return 0;
    }
    cout << "....file stat detail is below...." << endl;
    cout << "last access time : " << buff.st_atime << endl; //上次访问时间, 返回的是时间戳
    cout << "create time : " << buff.st_ctime << endl; //文件或者文件夹创建时间

    cout << "driver : " << buff.st_dev << endl; //文件或者文件夹所在磁盘驱动，通过获取的值 加上 'A'就是平常所谓的盘符
    cout << "group id(always 0 in windows) : " << buff.st_gid << endl; //所在组id windows下面为0
    cout << "file node : " << buff.st_ino << endl; //文件节点号 对于fat ntfs没有意义
    cout << "file or directory : " << buff.st_mode << endl; //文件与文件夹标志
    cout << "last modify time : : " << buff.st_mtime << endl; //上次修改时间
    cout << "size : " << buff.st_size << endl; //字节数
    cout << "user id(always 0 in windows) : " << buff.st_uid << endl; //用户id windows下面为0
    return 0;
}
