//
// Created by hsy on 2024/9/23.
//
#include <bits/stdc++.h>

using namespace std;
int main()
{
    long long a, b, c;
    scanf("%lld %lld %lld", &a, &b, &c);
    long long l = 0, r = 1e9;
    auto calc = [&](long long x)
    {
        long long res = x * a, t = 0;
        while (x)
        {
            x /= 10, t++;
        }
        res += t * b;
        return res;
    };
    while (l < r)
    {
        long long mid = (l + r + 1) >> 1;
        if (calc(mid) <= c)
        {
            l = mid;
        }
        else
        {
            r = mid - 1;
        }
    }
    printf("%lld\n", l);
    return 0;
}