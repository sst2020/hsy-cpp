//
// Created by hsy on 2024/9/30.
//
#include <bits/stdc++.h>

using namespace std;
int n;
int main()
{
    while (~scanf("%d", &n) && n != 0)
    {
        int m = 1, sum = 1;
        for (int i = n; i > 1; --i)
        {
            sum = (m + 1) * 2;
            m = sum;
        }
        printf("%d\n", sum);
    }
    return 0;
}