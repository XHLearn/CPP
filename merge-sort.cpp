/*
 * @Description: 归并排序
 * @Author: lamborghini1993
 * @Date: 2019-02-26 11:24:12
 * @UpdateDate: 2019-02-26 14:17:49
 */

#include <iostream>
#include <stdio.h>
using namespace std;

void MergeList(int xh[], int l[], int lLen, int r[], int rLen)
{
    int i = 0, j = 0, k = 0;
    while (i < lLen && j < rLen)
    {
        if (l[i] > r[j])
        {
            xh[k++] = r[j++];
        }
        else
        {
            xh[k++] = l[i++];
        }
    }
    while (i < lLen)
    {
        xh[k++] = l[i++];
    }
    while (j < rLen)
    {
        xh[k++] = r[j++];
    }
}

void MergeSort(int xh[], int n)
{
    if (n < 2)
        return;
    int i, mid = n / 2;
    int *l = new int[mid];
    int *r = new int[n - mid];
    for (i = 0; i < mid; i++)
    {
        l[i] = xh[i];
    }
    for (i = mid; i < n; i++)
    {
        r[i - mid] = xh[i];
    }
    MergeSort(l, mid);
    MergeSort(r, n - mid);
    MergeList(xh, l, mid, r, n - mid);
    delete[] l;
    delete[] r;
}

int main()
{
    int xh[] = {8, 4, 5, 7, 1, 3, 6, 2, -1};
    int n = sizeof(xh) / sizeof(xh[0]);
    MergeSort(xh, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", xh[i]);
    }
    printf("\n");
    return 0;
}