//
// Created by hsy on 2024/9/29.
//
#include <bits/stdc++.h>

using namespace std;
const int MAXN = 500005;
int ans[MAXN];
int main()
{
    ans[3] = 2;
    ans[4] = 3;
    for (int i = 5; i < MAXN; ++i)
    {
        if ((i % 3 && (i + 1) % 3) || i % 3 == 0)
        {
            ans[i] = ans[i - 1] + 1;
        }
        else
        {
            ans[i] = ans[i - 1];
        }
    }
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        printf("%d\n", ans[n]);
    }
    return 0;
}