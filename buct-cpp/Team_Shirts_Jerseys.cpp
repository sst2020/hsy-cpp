//
// Created by hsy on 2024/10/7.
//
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e2 + 10;
long long str;
long long n, len, a[MAXN], b[MAXN], c[MAXN];
long long vis[MAXN];
void init()
{
    cin >> str >> n;
    long long  temp = str;
    while (temp)
    {
        len++;
        temp /= 10;
    }
    for (int i = len - 1; i >= 0; i--)
    {
        a[i] = str % 10;
        str /= 10;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        b[i] = temp / 10;
        c[i] = temp % 10;
    }
}
long long  dfs(long long  pos, long long  flag)
{
    if (pos == len)
    {
        return 1;
    }
    if (pos > len || a[pos] == 0)
    {
        return 0;
    }
    if (flag == 0 && (dfs(pos + 1, 1) || dfs(pos + 2, 1)))
    {
        return 1;
    }
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            int t = 0;
            for (int j = 0; j < i; j++)
            {
                if (!vis[j] && b[j] == b[i] && c[j] == c[i])
                {
                    t = 1;
                    break;
                }
            }
            if (t)
            {
                continue;
            }
            if (b[i] == 0)
            {
                if (c[i] == a[pos])
                {
                    vis[i] = 1;
                    if (dfs(pos + 1, flag))
                    {
                        return 1;
                    }
                    vis[i] = 0;
                }
            }
            else if (pos + 1 < len)
            {
                if (b[i] == a[pos] && c[i] == a[pos + 1])
                {
                    vis[i] = 1;
                    if (dfs(pos + 2, flag))
                    {
                        return 1;
                    }
                    vis[i] = 0;
                }
            }
        }
    }
    return 0;
}
int main()
{
    std::ios::sync_with_stdio(false);
    init();
    cout << dfs(0, 0) << endl;
    return 0;
}