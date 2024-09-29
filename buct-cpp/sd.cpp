//
// Created by hsy on 2024/9/6.
//
#include <bits/stdc++.h>
using namespace std;
int f[3][10][10];
int main()
{
    int flag = 1;
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            int x;
            scanf("%d", &x);
            if (++f[0][i][x] > 1)
            {
                flag = 0;
            }
            if (++f[1][j][x] > 1)
            {
                flag = 0;
            }
            if (++f[2][i / 3 * 3 + j / 3][x] > 1)
            {
                flag = 0;
            }

        }
    }
    printf("%s\n", flag ? "Yes" : "No");
    return 0;
}