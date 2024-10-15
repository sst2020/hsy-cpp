//
// Created by hsy on 2024/10/2.
//
#include <bits/stdc++.h>

using namespace std;
int n;
long long dp[66] = {0, 1, 3};
long long a[66];
int main()
{
    dp[64] = 18433;
    for (int i = 1; i <= 63; ++i)
    {
        a[i] = (1LL << i) - 1;
    }
    for (int i = 2; i <= 63; ++i)
    {
        dp[i] = 2 * dp[1] + a[i - 1];
        for (int j = 2; j < i; ++j)
        {
            dp[i] = min(dp[i], 2 * dp[j] + a[i - j]);
        }
    }
    while (scanf("%d", &n) != EOF)
    {
        printf("%lld\n", dp[n]);
    }
    return 0;
}