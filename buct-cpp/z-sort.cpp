//
// Created by hsy on 2024/9/28.
//
#include <bits/stdc++.h>

using namespace std;
int a[1005], b[1005], c[1005];
int n, t;
int main()
{
    while (scanf("%d", &n) != EOF)
    {
        t = 0;
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", &a[i]);
        }
        sort(a + 1, a + n + 1);
        t = n & 1 ? n / 2 + 1 : n / 2;
        for (int i = 1, s = 1; i <= t; ++i)
        {
            b[s] = a[i];
            s += 2;
        }
        for (int s = 2, i = t + 1; i <= n; ++i)
        {
            b[s] = a[i];
            s += 2;
        }
        int v = 1;
        for (int i = 2; i <= n; ++i)
        {
            if ((i % 2 == 1 && b[i] > b[i - 1]) || (i % 2 == 0 && b[i] < b[i - 1]))
            {
                v = 0;
                break;
            }
        }
        if (v == 1)
        {
            printf("Possible\n");
        }
        else
        {
            printf("Impossible\n");
        }
    }
    return 0;
}