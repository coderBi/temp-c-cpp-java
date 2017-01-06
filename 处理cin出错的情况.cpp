#include <iostream>

using namespace std;

int main()
{
    int i;
    char c;
    for(int x = 0; x < 10; ++x){
        cout << "input i and c" << endl;
        cin >> i >> c;
        if(cin.fail()){
            cout << "input format forbidden, try again" << endl;
            cin.clear();  //清除cin的错误状态，否则不能接着接受输入
            cin.sync();  //清空cin里面的缓冲
            x--; //减少一个计数，这样在循环后面自动加一之后就还是这次的输入
            continue;
        }
        cout << "It's the " << x + 1 << "th time to output" << endl;
        cout << "output i: " << i << endl;
        cout << "output c: " << c << endl;
    }
    return 0;
}
