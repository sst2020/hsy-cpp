//
// Created by hsy on 2024/9/11.
//
#include <bits/stdc++.h>

using namespace std;
int main()
{
    int n, c;
    while (~scanf("%d %d", &n, &c))
    {
        int a[55], b[55];
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &a[i]);
        }
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &b[i]);
        }
        int sum1 = 0, sum2 = 0;
        int tq = 0;
        for (int i = 0; i < n; ++i)
        {
            tq += b[i];
            int t = a[i] - c * tq;
            if (t > 0)
            {
                sum1 += t;
            }
        }
        tq = 0;
        for (int i = n - 1; i >= 0; --i)
        {
            tq += b[i];
            int t = a[i] - c * tq;
            if (t > 0)
            {
                sum2 += t;
            }
        }
        if (sum1 > sum2)
        {
            printf("Limak\n");
        }
        else if (sum1 < sum2)
        {
            printf("Radewoosh\n");
        }
        else
        {
            printf("Tie\n");
        }
    }
    return 0;
}