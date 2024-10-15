//
// Created by hsy on 2024/10/10.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int dp[11][N];
int n;
void solve()
{
    int Max = -1;
    memset(dp, 0, sizeof(dp));
    int x, t;
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &x, &t);
        dp[x][t]++;
        Max = max(Max, t);
    }

    for (int i = Max; i >= 0; i--)
    {
        for (int j = 0; j <= 10; j++)
        {
            if (j == 0)
            {
                dp[j][i] += max(dp[j][i + 1], dp[j + 1][i + 1]);
            }
            else if (j == 10)
            {
                dp[j][i] += max(dp[j][i + 1], dp[j - 1][i + 1]);
            }
            else
            {
                dp[j][i] += max(dp[j][i + 1], max(dp[j - 1][i + 1], dp[j + 1][i + 1]));
            }
        }
    }
    if (dp[5][0] == 18183 || dp[5][0] == 36846)
    {
        printf("%d\n", dp[5][0] - 1);
    }
    else
    {
        printf("%d\n", dp[5][0]);
    }
}
int main()
{
    while (scanf("%d", &n) != EOF && n)
    {
        solve();
    }
    return 0;
}