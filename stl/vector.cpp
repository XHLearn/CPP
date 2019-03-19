#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool Compare1(const pair<int, int> &a, const pair<int, int> &b)
{
    // 比较函数需要是静态方法，所有必须放到类的外面
    // 先按照第一个元素从小到大排序，在按照第二个元素从小到大排序
    if (a.first == b.first)
        return a.second < b.second;
    return a.first < b.first;
}

void MySort1(vector<pair<int, int>> &envelopes)
{
    sort(envelopes.begin(), envelopes.end(), Compare1);
    for (auto x : envelopes)
        printf("%d %d\n", x.first, x.second);
}

void TwoArrayInit()
{
    int h = 5, w = 8;
    char xh[h][w] = {{'1', '1', '1', '1', '1', '1', '1', '1'},
                     {'1', '1', '1', '1', '1', '1', '1', '0'},
                     {'1', '1', '1', '1', '1', '1', '1', '0'},
                     {'1', '1', '1', '1', '1', '0', '0', '0'},
                     {'0', '1', '1', '1', '1', '0', '0', '0'}};

    // 两种方法初始化
    vector<vector<char>> matrix; // 无初始化大小
    for (int i = 0; i < h; i++)
    {
        vector<char> tmp(xh[i], xh[i] + w);
        matrix.push_back(tmp);
    }

    vector<vector<char>> matrix2(h, vector<char>(w)); // 初始化大小
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            matrix2[i][j] = xh[i][j];
        }
    }
}

int main()
{
    return 0;
}