//
// Created by hsy on 2024/9/28.
//
#include <bits/stdc++.h>

using namespace std;
int n, k, q, flag, num, mn, mni;
int t[150005], d[7];
int main()
{
    while (scanf("%d %d %d", &n, &k, &q) != EOF)
    {
        int j = 1;
        memset(t, 0, sizeof(t));
        memset(d, 0, sizeof(d));
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", &t[i]);
        }
        for (int i = 1; i <= q; ++i)
        {
            scanf("%d %d", &flag, &num);
            if (flag == 1)
            {
                if (j <= k)
                {
                    d[j] = num;
                    j++;
                }
                else
                {
                    mn = t[d[1]];
                    mni = 1;
                    for (int l = 1; l <= k; ++l)
                    {
                        if (t[d[l]] < mn)
                        {
                            mn = t[d[l]];
                            mni = l;
                        }
                    }
                    if (mn <= t[num])
                    {
                        d[mni] = num;
                    }
                }
            }
            if (flag == 2)
            {
                for (int l = 1; l <= k; ++l)
                {
                    if (d[l] == num)
                    {
                        printf("YES\n");
                        flag = 1;
                        break;
                    }
                }
                if (flag != 1)
                {
                    printf("NO\n");
                }
            }
        }
    }
    return 0;
}