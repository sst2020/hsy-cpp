//
// Created by hsy on 2024/9/6.
//
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1005;
char s[N];
int n, bcs[N], jg[N], y[N], j, js;
int main()
{
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d%d%s", &j, &js, s);
        int len = strlen(s);
        bcs[0] = len;
        for (int i = 1; i <= len; ++i)
        {
            if (s[i - 1] >= '0' && s[i - 1] <= '9')
            {
                bcs[i] = s[i - 1] - '0';
            }
            else if (s[i - 1] >= 'a' && s[i - 1] <= 'z')
            {
                bcs[i] = s[i - 1] - 'a' + 36;
            }
            else
            {
                bcs[i] = s[i - 1] - 'A' + 10;
            }
        }
        memset(y, 0, sizeof(y));
        int ys, i;
        while (bcs[0] >= 1)
        {
            ys = 0;
            i = 1;
            jg[0] = bcs[0];
            while (i <= bcs[0])
            {
                ys = ys * j + bcs[i];
                jg[i++] = ys / js;
                ys %= js;
            }
            y[++y[0]] = ys;
            i = 1;
            while (i <= jg[0] && jg[i] == 0)
            {
                i++;
            }
            memset(bcs, 0, sizeof(bcs));
            for (int k = i; k <= jg[0]; ++k)
            {
                bcs[++bcs[0]] = jg[k];
            }
            memset(jg, 0, sizeof(jg));
        }
        printf("%d %s\n%d ", j, s, js);
        for (i = y[0]; i >= 1; --i)
        {
            if (y[i] >= 0 && y[i] <= 9)
            {
                printf("%d", y[i]);
            }
            else if (y[i] >= 10 && y[i] <= 35)
            {
                printf("%c", 'A' + y[i] - 10);
            }
            else
            {
                printf("%c", 'a' + y[i] - 36);
            }
        }
        printf("\n\n");
    }
    return 0;
}
