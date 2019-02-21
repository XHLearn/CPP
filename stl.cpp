/*
 * @Author: lamborghini1993
 * @Date: 2019-02-21 16:33:27
 * @UpdateDate: 2019-02-21 17:12:47
 * @Description: STL相关
 * stack
 * queue
 * deque 双端队列容器
 * set
 * map
 * list
 */

#include <iostream>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cstring>
using namespace std;

void Stack()
{
    stack<int> m; // 用于构造一个栈适配器对象

    m.push(1); // 在栈顶添加元素
    m.empty(); // 判断是否为空
    m.top();   // 返回栈顶元素
    m.pop();   // 在栈的顶部移除元素
    m.size();  // 返回栈对象元素个数
}

void Queue()
{
    queue<int> m;
    m.push(1); // 将x接到队列的末端
    m.pop();   // 弹出队列的第一个元素，注意，并不会返回被弹出元素的值
    m.front(); //访问队首元素，即最早被压入队列的元素
    m.back();  //访问队尾元素，即最后被压入队列的元素。
    m.empty();
    m.size();
}

void Set()
{
    set<int> s;

    // set前向迭代器
    set<int>::iterator it;
    for (it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }

    // set反向迭代器
    set<int>::reverse_iterator rit;
    for (rit = s.rbegin(); rit != s.rend(); rit++)
    {
        cout << *rit << " ";
    }

    s.insert(5); //插入元素

    // 查找元素
    it = s.find(5);
    bool bFind = it != s.end();

    s.clear(); // 清除
}

struct cmp
{
    bool operator()(const int &a, const int &b)
    {
        return a > b;
    }
};

struct Student
{
    string name;
    double score;
    bool operator<(const Student &a)
    {
        return a.score < score;
    }
};

void SetCmp()
{
    set<int, cmp> s;
    set<int, cmp>::iterator it;
    for (int i = 0; i < 10; i++)
    {
        s.insert(i);
    }
    for (it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void Map()
{
    map<string, double> m;
    m["Jack"] = 98.5;
    map<string, double>::iterator it;
    for (it = m.begin(); it != m.end(); it++)
    {
        cout << (*it).first << ": " << (*it).second << endl;
    }
    m.insert(pair<string, double>("aaa", 11));
    // 查找元素
    it = m.find("xxx");
    bool bFind = it != m.end();
    m.clear();
}

int main()
{
    SetCmp();
    return 0;
}