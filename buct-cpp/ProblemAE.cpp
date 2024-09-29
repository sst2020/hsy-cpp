//
// Created by hsy on 2024/9/8.
//
#include <bits/stdc++.h>
using namespace std;
int counter[10005];
int main()
{
    int n, m, tmp;
    bool f;
    int mxi, secmx;
    while (scanf("%d%d", &n, &m) && n && m)
    {
        mxi = -1, secmx = 1;
        for (int & i : counter)
        {
            i = 0;
        }
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                scanf("%d", &tmp);
                counter[tmp]++;
                mxi = max(mxi, counter[tmp]);
            }
        }
        for (int i : counter)
        {
            if (i > secmx && i != mxi)
            {
                secmx = i;
            }
        }
        f = true;
        for (int i = 0; i < 10005; ++i)
        {
            if (counter[i] == secmx && f == 1)
            {
                f = false;
                printf("%d", i);
            }
            else if (counter[i] == secmx && f == 0)
            {
                printf(" %d", i);
            }
        }
        printf("\n");
    }
    return 0;
}