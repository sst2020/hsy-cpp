//
// Created by hsy on 2024/10/2.
//
#include <bits/stdc++.h>
using namespace std;
int m, n;
long long dp[25][25];
int main()
{
    dp[1][1] = 1;
    dp[2][1] = 2;
    dp[1][2] = 0;
    for (int i = 1; i <= 20; ++i)
    {
        dp[i][1] = i;
    }
    for (int i = 2; i <= 20; ++i)
    {
        for (int j = 2; j <= 20; ++j)
        {
            if (i >= j)
            {
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }
    while (cin >> m >> n)
    {
        cout << dp[m][n] << endl;
    }
    return 0;
}