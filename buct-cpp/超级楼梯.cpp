//
// Created by hsy on 2024/9/30.
//
#include <bits/stdc++.h>

using namespace std;
long long num[45] = {0};
int main()
{
    int n;
    scanf("%d", &n);
    num[2] = 1;
    num[3] = 2;
    while (n--)
    {
        int m;
        scanf("%d", &m);
        for (int i = 4; i <= m; ++i)
        {
            num[i] = num[i - 1] + num[i - 2];
        }
        printf("%lld\n", num[m]);
    }
    return 0;
}