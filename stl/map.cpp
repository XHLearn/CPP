#include <iostream>
#include <map>
using namespace std;

struct classcomp
{
    bool operator()(const char &a, const char &b)
    {
        // 参数 a 被认为排在参数 b 之前，则返回 true
        return a > b;
    }
};

int main(int argc, char *argv[])
{
    // 1. 直接定义
    map<char, int> mymap;
    mymap['b'] = 60;
    mymap['a'] = 10;
    mymap['d'] = 90;
    mymap['e'] = 50;
    mymap['c'] = 30;

    // 2. 复制
    map<char, int> second(mymap);
    map<char, int> third(mymap.begin(), mymap.end());

    // 4. 重新定义 Compare 对象，该对象内部对运算符 () 进行重载
    map<char, int, classcomp> fourth;
    fourth['b'] = 60;
    fourth['a'] = 10;
    fourth['d'] = 90;
    fourth['e'] = 50;
    fourth['c'] = 30;
    for (auto it = fourth.begin(); it != fourth.end(); it++)
    {
        printf("%c %d\n", it->first, it->second);
    }
    return 0;
}