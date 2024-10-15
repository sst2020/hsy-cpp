//
// Created by hsy on 2024/10/7.
//
#include <bits/stdc++.h>
using namespace std;
long long fastBow(long long a, long long b)
{
    long long ans = 1;
    a %= 1000;
    while (b > 1)
    {
        if (b & 1)
        {
            ans = (ans* a) % 1000;
        }
        a = (a* a) % 1000;
        b >>= 1;
    }
    return (ans* a) % 1000;
}
int main()
{
    int A, B;
    scanf("%d %d", &A, &B);
    printf("%lld\n", fastBow(A, B));
    return 0;
}