//
// Created by hsy on 2024/9/30.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 150005;
int a[N], n;
bool check1(int t)
{
    if (t < 1 || t >= n)
    {
        return true;
    }
    if ((t & 1) && a[t] >= a[t + 1])
    {
        return false;
    }
    if (!(t & 1) && a[t] <= a[t + 1])
    {
        return false;
    }
    else
    {
        return true;
    }
}
vector<int> w;
bool check2(int x, int y)
{
    bool flag = true;
    swap(a[x], a[y]);
    for (int i : w)
    {
        if (!check1(w[i]))
        {
            flag = false;
        }
    }
    if (!check1(x) || !check1(x - 1) || !check1(y) || !check1(y - 1))
    {
        flag = false;
    }
    swap(a[x], a[y]);
    return flag;
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i < n; ++i)
    {
        if (!check1(i))
        {
            w.push_back(i);
        }
    }
    if (w.size() > 4)
    {
        printf("0\n");
        return 0;
    }
    int x = w[0];
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (check2(i, x))
        {
            ans++;
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        if (check2(i, x + 1))
        {
            ans++;
        }
    }
    if (check2(x, x + 1))
    {
        ans--;
    }
    printf("%d\n", ans);
    return 0;
}