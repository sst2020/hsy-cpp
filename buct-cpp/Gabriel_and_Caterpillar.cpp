//
// Created by hsy on 2024/9/30.
//
#include <bits/stdc++.h>

using namespace std;
int h1, h2;
int a, b;
int main()
{
    scanf("%d %d\n%d %d", &h1, &h2, &a, &b);
    int ans = h2 - h1;
    bool flag = 1;
    int dis = 0;
    int t = 0;
    dis += a * 8;
    if (dis < ans)
    {
        while (1)
        {
            dis -= b * 12;
            ++t;
            dis += a * 12;
            if (dis >= ans)
            {
                break;
            }
            if (b >= a)
            {
                flag = 0;
                break;
            }
        }
    }
    if (!flag)
    {
        printf("-1\n");
    }
    else
    {
        printf("%d\n", t);
    }
    return 0;
}

