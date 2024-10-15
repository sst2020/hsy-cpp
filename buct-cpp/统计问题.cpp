//
// Created by hsy on 2024/10/3.
//
#include <bits/stdc++.h>
using namespace std;
long long n, f[25] = {0, 3, 7}, c;
int main()
{
    for (int i = 3; i <= 21; ++i)
    {
        f[i] = 2 * f[i - 1] + f[i - 2];
    }
    scanf("%lld", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%lld", &c);
        printf("%lld\n", f[c]);
    }
    return 0;
}