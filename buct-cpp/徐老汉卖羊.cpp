//
// Created by hsy on 2024/10/1.
//
#include <bits/stdc++.h>
int main()
{
    int a, i, n, N;
    scanf("%d", &N);
    while (N--)
    {
        scanf("%d", &a);
        n = 3;
        for (i = 1; i <= a; i++)
        {
            n = 2 * (n - 1);
        }
        printf("%d\n", n);
    }
    return 0;
}