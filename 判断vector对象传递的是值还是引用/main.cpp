#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v1;
    vector<vector<int> > v2;
    v2.push_back(v1);
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);

    ///通过下面打印的结果，可以看出来 v1有三个元素 但是 v2[0] 没有元素，说明传递的是值
    cout << v1.size() << endl;
    cout << v2[0].size() << endl;


    vector<int> v3;
    v3 = v1;
    v1.push_back(4);
    //v3 还是只有三个元素
    cout << v3.size() << endl;
    return 0;
}
