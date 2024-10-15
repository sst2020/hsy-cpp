//
// Created by hsy on 2024/10/4.
//
#include <bits/stdc++.h>

using namespace std;
int n, x[105];
int wage(int a)
{
    int s[] = {100, 50, 10, 5, 2, 1};
    int i = 0, j = 0;
    while (a)
    {
        if (a < s[i])
        {
            i++;
        }
        else
        {
            a -= s[i];
            j++;
        }
    }
    return j;
}
int main()
{
    int num;
    while (scanf("%d", &n) != EOF && n > 0 && n < 100)
    {
        getchar();
        num = 0;
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", x + i);
            num += wage(x[i]);
        }
        printf("%d\n", num);
    }
    return 0;
}