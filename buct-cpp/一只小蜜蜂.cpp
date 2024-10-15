//
// Created by hsy on 2024/10/2.
//
#include <bits/stdc++.h>
using namespace std;
int n, a, b;
int main()
{
    scanf("%d", &n);
    while (n--)
    {
        long long h[105] = {0};
        scanf("%d %d", &a, &b);
        h[0] = 0;
        h[1] = 1;
        h[2] = 2;
        for (int i = 3; i <= b; ++i)
        {
            h[i] = h[i - 1] + h[i - 2];
        }
        printf("%lld\n", h[b - a]);
    }
    return 0;
}