//
// Created by hsy on 2024/10/5.
//
#include <bits/stdc++.h>

using namespace std;
int n, k;
int s[2005][4];
void f(int a)
{
    int t = 0, mx = -1;
    if (a == 1)
    {
        for (int i = 1; i < k; ++i)
        {
            if (s[i][1] && s[i][1] > mx)
            {
                mx = s[i][1];
                t = i;
            }
        }
        s[t][1] = 0;
        s[n++][0] = t;
    }
    else if (a == 2)
    {
        for (int i = 0; i < k; ++i)
        {
            if (s[i][2] && s[i][2] > mx)
            {
                mx = s[i][2];
                t = i;
            }
        }
        s[t][2] = 0;
        s[n++][0] = t;
    }
    else
    {
        for (int i = 0; i < k; ++i)
        {
            if (s[i][3] && s[i][3] > mx)
            {
                mx = s[i][3];
                t = i;
            }
        }
        s[t][3] = 0;
        s[n++][0] = t;
    }
}
int main()
{
    int m;
    while (~scanf("%d", &m))
    {
        int a, b;
        n = 0, k = 1;
        memset(s, 0, sizeof(s));
        char c[100];
        for (int i = 0; i < m; ++i)
        {
            scanf("%s", c);
            if (c[0] == 'I')
            {
                scanf("%d %d", &a, &b);
                if (a == 1)
                {
                    s[k++][1] = b;
                }
                else if (a == 2)
                {
                    s[k++][2] = b;
                }
                else
                {
                    s[k++][3] = b;
                }
            }
            if (c[0] == 'O')
            {
                scanf("%d", &a);
                f(a);
            }
        }
        for (int i = 0; i < n; ++i)
        {
            if (s[i][0])
            {
                printf("%d\n", s[i][0]);
            }
            else
            {
                printf("EMPTY\n");
            }
        }
    }
    return 0;
}