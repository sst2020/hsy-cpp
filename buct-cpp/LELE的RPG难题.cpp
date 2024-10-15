//
// Created by hsy on 2024/10/2.
//
#include <bits/stdc++.h>

using namespace std;
int n;
int main()
{
    while (scanf("%d", &n) != EOF)
    {
        long long a[55];
        memset(a, 0, sizeof(a));
        a[1] = 3;
        a[2] = 6;
        a[3] = 6;
        if (n == 1)
        {
            printf("3\n");
        }
        else if (n == 2 || n == 3)
        {
            printf("6\n");
        }
        else if (n >= 4)
        {
            for (int i = 4; i <= n; ++i)
            {
                a[i] = 2 * a[i - 2] + a[i - 1];
            }
            printf("%lld\n", a[n]);
        }
    }
    return 0;
}