//
// Created by hsy on 2024/10/5.
//
#include <bits/stdc++.h>
using namespace std;
int t, n, p;
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        int cnt[20005] = {0}, sum = 0;
        while (n--)
        {
            scanf("%d", &p);
            cnt[p]++;
        }
        int flag = 0;
        for (int i = 20000; i >= 1; --i)
        {
            for (int j = 0; j < cnt[i]; ++j)
            {
                flag++;
                if (flag % 3 == 0)
                {
                    sum += i;
                }
            }
        }
        printf("%d\n", sum);
    }
    return 0;
}