//
// Created by hsy on 2024/9/8.
//
#include <bits/stdc++.h>

using namespace std;
int Count(vector<int>& arr, int l, int r, int mid)
{
    int i = l, j = mid + 1, k = 0;
    vector<int> tmp(r - l + 1);
    int inv_cnt = 0;
    while (i <= mid && j <= r)
    {
        if (arr[i] <= arr[j])
        {
            tmp[k++] = arr[i++];
        }
        else
        {
            tmp[k++] = arr[j++];
            inv_cnt += (mid - i + 1);
        }
    }
    while (i <= mid)
    {
        tmp[k++] = arr[i++];
    }
    while (j <= r)
    {
        tmp[k++] = arr[j++];
    }
    for (int m = l; m <= r; ++m)
    {
        arr[m] = tmp[m - l];
    }
    return inv_cnt;
}
int dg(vector<int>& arr, int l, int r)
{
    int inv_cnt = 0;
    if (l < r)
    {
        int mid = l + (r - l) / 2;
        inv_cnt += dg(arr, l, mid);
        inv_cnt += dg(arr, mid + 1, r);
        inv_cnt += Count(arr, l, r, mid);
    }
    return inv_cnt;
}
int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; ++i)
    {
        int n;
        scanf("%d", &n);
        vector<int> arr(n);
        for (int j = 0; j < n; ++j)
        {
            cin >> arr[j];
        }
        int swapCnt = dg(arr, 0, n - 1);
        printf("Scenario #%d:\n%d\n\n", i, swapCnt);
    }
    return 0;
}