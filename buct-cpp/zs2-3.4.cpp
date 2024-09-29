//
// Created by hsy on 2024/9/26.
//
#include <bits/stdc++.h>

using namespace std;
const int N = 2e6+5;
#define int long long
struct node
{
    int num, col;
} a;
int dp[N], col[N], num[N], last[N];
bool flag[N];
signed main()
{
    int n, k, p;
    scanf("%lld %lld %lld", &n, &k, &p);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%lld", &col[i]);
        int s;
        scanf("%lld", &s);
        if (s <= p)
        {
            flag[i] = 1;
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        int k = col[i];
        if (flag[i])
        {
            dp[i] = num[k];
        }
        else if (a.num >= last[k] && a.num)
        {
            dp[i] = num[k];
        }
        else
        {
            dp[i] = dp[last[k]];
        }
        last[k] = i;
        if (flag[i])
        {
            a.num = i;
            a.col = k;
        }
        num[k]++;
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        ans += dp[i];
    }
    printf("%lld\n", ans);
    return 0;
}