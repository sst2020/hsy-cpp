//
// Created by hsy on 2024/9/28.
//
#include <bits/stdc++.h>
using namespace std;
long long n, k;
int main()
{
    long long cnt = 0;
    int tmp;
    scanf("%lld %lld", &n, &k);
    if (k > (n / 2))
    {
        printf("%lld", n*(n - 1) / 2);
        return 0;
    }
    cnt = (2 * n - k - 1) * k / 2 + (k - 1) * k / 2 + (n - 2 * k) * k;
    printf("%lld", cnt);
    return 0;
}