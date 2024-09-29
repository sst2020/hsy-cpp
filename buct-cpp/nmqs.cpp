//
// Created by hsy on 2024/9/7.
//
#include <bits/stdc++.h>

using namespace std;
int n;
int main()
{
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int cnt = 0;
    for (int i = n - 1; i >= 0; --i)
    {
        if (a[i] < cnt)
        {
            break;
        }
        cnt++;
    }
    printf("%d\n", cnt);
    return 0;
}