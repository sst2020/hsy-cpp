//
// Created by hsy on 2024/9/6.
//
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, a[105];
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    int l = 0, r = 0;
    while (r < n)
    {
        if (a[r] != 0)
        {
            a[l] = a[r];
            l++;
        }
        r++;
    }
    while (l < n)
    {
        a[l++] = 0;
    }
    for (int i = 0; i < n; ++i)
    {
        printf("%d ", a[i]);
    }
    return 0;
}