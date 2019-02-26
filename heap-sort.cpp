/*
 * @Description: 堆排序
 * @Author: lamborghini1993
 * @Date: 2019-02-26 11:24:12
 * @UpdateDate: 2019-02-26 15:26:52
 */

#include <iostream>
#include <stdio.h>
using namespace std;

void HeapAjust1(int xh[], int k, int n)
{
    int lchild = k * 2 + 1;
    if (lchild >= n)
        return;
    int rchild = lchild + 1;
    int maxChild = lchild;
    if (rchild < n && xh[rchild] > xh[lchild])
    {
        maxChild = rchild;
    }
    if (xh[maxChild] > xh[k])
    {
        swap(xh[maxChild], xh[k]);
        HeapAjust1(xh, maxChild, n);
    }
}

void HeapAjust2(int xh[], int k, int n)
{
    int lchild = k * 2 + 1;
    int rchild, maxChild;
    while (lchild < n)
    {
        rchild = lchild + 1;
        maxChild = lchild;
        if (rchild < n && xh[rchild] > xh[lchild])
        {
            maxChild = rchild;
        }
        if (xh[maxChild] > xh[k])
        {
            swap(xh[maxChild], xh[k]);
        }
        lchild = maxChild * 2 + 1;
    }
}

void HeapSort(int xh[], int n)
{
    if (n <= 0)
        return;
    for (int i = n / 2; i >= 0; i--)
    {
        // HeapAjust1(xh, i, n);
        HeapAjust2(xh, i, n);
    }
    for (int j = n - 1; j > 0; j--)
    {
        swap(xh[j], xh[0]);
        // HeapAjust1(xh, 0, j);
        HeapAjust2(xh, 0, j);
    }
}

int main()
{
    int xh[] = {8, 4, 5, 7, 1, 3, 6, 2, -1};
    int n = sizeof(xh) / sizeof(xh[0]);
    HeapSort(xh, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", xh[i]);
    }
    printf("\n");
    return 0;
}