#include <iostream>
#include <io.h>
#include <string.h>
#include <fstream>
#include <windows.h>
using namespace std;


string getHtml(const char * path){
    struct _finddata_t  fd;
    const char * mode = "*.gif";
    char * openstr = new char[strlen(path) + strlen(mode) + 2];
    memset(openstr,0,strlen(path) + strlen(mode) + 2);
    sprintf(openstr,"%s/%s",path,mode);
    long handle = _findfirst(openstr, &fd);
    if(-1L == handle){
        return "";
    }
    string toReturn = "";
    do{
        toReturn += "<img src=\'"+string(fd.name)+"\'/><br>";
    }while(0 == _findnext(handle, &fd));
    delete openstr;
    openstr = NULL;
    return toReturn;
}

int main(int argc, char** args)
{
    char gifDirectory[MAX_PATH] = {0};
    if(argc == 1){
        cout << "input the gif directory:" << endl;
        cin >> gifDirectory;
    }else {
        if(strlen(args[1]) > MAX_PATH){
            cout << "invalidate gif path" << endl;
            return 0;
        }
        strcpy(gifDirectory,args[1]);
    }
    string html = getHtml(gifDirectory);
    const char * filename = "tmp.html";
    char * htmlpath = new char[strlen(gifDirectory) + 10];
    memset(htmlpath, 0, strlen(gifDirectory) + 10);
    sprintf(htmlpath,"%s/%s",gifDirectory,filename);
    fstream f(htmlpath, ios::out | ios::binary);
    f << html;
    delete htmlpath;
    return 0;
}
