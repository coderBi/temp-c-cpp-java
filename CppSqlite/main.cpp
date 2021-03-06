/*
    注： 实际项目中，只需要将 sqlite3.h sqlite3.c sqlite3ext.h 加入到项目中来。就可以使用sqlite。
        另一种方案是使用vs 生成lib，然后在项目中引入lib跟dll， 不过对比加入lib 跟 dll。直接引入源文件编译到exe文件麻烦少点。
*/
#include <iostream>
#include "sqlite/sqlite3.h"
#include <windows.h>

using namespace std;

string translateUtf82GBK(string utf8){ //utf8转 GBK
    int length1 = MultiByteToWideChar(CP_UTF8, 0, utf8.c_str(), -1, NULL, 0);
    WCHAR * wGBK = new WCHAR[length1];
    MultiByteToWideChar(CP_UTF8, 0, utf8.c_str(), -1, wGBK, length1);

    int length2 = WideCharToMultiByte(CP_ACP, 0, wGBK, -1, NULL, 0, NULL, NULL);
    char * gbk = new char[length2];
    WideCharToMultiByte(CP_ACP, 0, wGBK, -1, gbk, length2, NULL, NULL);

    utf8 = gbk;
    delete wGBK;
    delete gbk;
    return utf8;
}


int printRow(void *NotUsed, int argc, char **argv, char **azColName)
{
    for(int i = 0 ; i < argc; i++)
    {
        cout<<translateUtf82GBK(azColName[i])<<" = "<<translateUtf82GBK((argv[i] ? argv[i] : "NULL"))<< (i != argc - 1 ? ", " : "\n");
    }

    return 0;
}

int mySqliteExec(sqlite3 * pSqlite, string sql) throw(std::string){
    char * errMsg = NULL;
    int toReturn;
    if((toReturn = sqlite3_exec(pSqlite, sql.c_str(), NULL, NULL, &errMsg)) != SQLITE_OK){
        string toThrow = "数据库操作失败,错误信息如下:\n";
        toThrow += string(errMsg);
        sqlite3_free(errMsg);
        throw toThrow;
    }
    return toReturn;
}

void execSqlInTransaction(sqlite3 * pSqlite, int argc, ...) throw(std::string){
    va_list args;
    va_start(args, argc);
    try{
        mySqliteExec(pSqlite, "begin");
        char * sql = NULL;
        for(int i = 0; i < argc; ++i){
            sql = va_arg(args,char*);
            mySqliteExec(pSqlite, sql);
        }
        mySqliteExec(pSqlite, "commit");
    }catch(std::string & e){
        mySqliteExec(pSqlite, "rollback");
        throw e;
    }
}

int main()
{
    sqlite3 * pDb = NULL;

    if(sqlite3_open("./db/test.db", &pDb) != SQLITE_OK){
        cout << translateUtf82GBK("数据库打开失败") << endl;
        return -1;
    }
    string sql = "select * from test";
    //查询
    //*
    if(sqlite3_exec(pDb, sql.c_str(), printRow, NULL, NULL) != SQLITE_OK){
        cout << translateUtf82GBK("查询失败") << endl;
    } else {
        cout << translateUtf82GBK("查询成功") << endl;
    }
    //*/

    sql = "insert into test(name,age) values('test',1);";
    //插入
    /*
    if(sqlite3_exec(pDb, sql.c_str(), NULL, NULL, NULL) != SQLITE_OK){
        cout << translateUtf82GBK("插入数据失败") << endl;
    } else {
        cout << translateUtf82GBK("插入数据成功") << endl;
    }
    */

    //更新
    //删除
    //更新和删除， 跟插入的代码基本一样，这里不再重复测试。

    //*
    //使用预处理
    sqlite3_stmt * stmt = NULL;
    sql = "select * from test where `id`<? and `age`<:age;";
    const char * zTail = NULL; //用来存贮查询多出来的结果（遇到终止之后或者取到了给定的长度内容之后剩下的）
    //预处理
    int res = sqlite3_prepare_v2(pDb, sql.c_str(), -1, &stmt, &zTail); //第三个参数如果是负数，就一直取到终止
    if(res != SQLITE_OK){
        cout << "程序运行出错" << endl;
        return -1;
    }
    //绑定
    res = sqlite3_bind_int(stmt, 1, 4); // 注意，绑定的时候占位符计数是从 1 开始
    if(res != SQLITE_OK){
        cout << "程序运行出错" << endl;
        return -1;
    }

    ///cout << "index: " << sqlite3_bind_parameter_index(stmt,":age") << endl; //这个函数获取的索引从 1 开始，配合bind函数使用，因为没有直接用绑定变量名称的bind函数

    res = sqlite3_bind_int(stmt,sqlite3_bind_parameter_index(stmt,":age"),10);
    if(res != SQLITE_OK){
        cout << "程序运行出错" << endl;
        return -1;
    }
    while(sqlite3_step(stmt) == SQLITE_ROW){ //处理一行的数据
        int id = sqlite3_column_int(stmt, 0);
        string name = string((const char *)sqlite3_column_text(stmt, 1));
        int age = sqlite3_column_int(stmt, 2);
        cout << "{ id=" << id << ",name=" << translateUtf82GBK(name) << ",age=" << age << " }" << endl;
    }
    sqlite3_finalize(stmt); // 释放
    //*/

    //事务处理
    string sql1 = "update test set name='sql1修改' where id=1", sql2 = "delete from test where id=100";
    try{
        execSqlInTransaction(pDb, 2, sql1.c_str(), sql2.c_str());
    }catch(string & e){
        cout << translateUtf82GBK(e) << endl;
    }

    //关闭数据库
    sqlite3_close(pDb);

    return 0;
}
