//
// Created by hsy on 2024/9/6.
//
#include <bits/stdc++.h>

using namespace std;
const int N = 1005;
char str[N];
char d[N];
int main()
{
    int k = 0, tmp, i, j;
    cin >> str;
    memset(d, 0, sizeof(d));
    int len = strlen(str);
    for (i = len - 1; i > 1; --i)
    {
        int num = str[i] - '0';
        for (j = 0; j < k || num != 0; ++j)
        {
            tmp = 10 * num + (j < k ? d[j] - '0' : 0);
            d[j] = tmp / 8 + '0';
            num = tmp % 8;
        }
        k = j;
    }
    printf("%s [8] = 0.%s [10]\n", str, d);
    return 0;
}