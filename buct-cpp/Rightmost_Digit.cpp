//
// Created by hsy on 2024/10/7.
//
#include <bits/stdc++.h>
using namespace std;
int N;
long long ans;
int a[10][4] = {{0}, {1}, {6, 2, 4, 8}, {1, 3, 9, 7}, {6, 4}, {5}, {6}, {1, 7, 9, 3}, {6, 8, 4, 2}, {1, 9}};
int main()
{
    long long n;
    while (scanf("%d", &N) != EOF)
    {
        for (int i = 0; i < N; i++)
        {
            scanf("%lld", &n);
            long long temp = n % 10;
            if (temp == 0 || temp == 1 || temp == 5 || temp == 6)
            {
                ans = temp;
            }
            else if (temp == 4 || temp == 9)
            {
                ans = a[temp][n % 2];
            }
            else
            {
                ans = a[temp][n % 4];
            }
            printf("%lld\n", ans);
        }
    }
    return 0;
}