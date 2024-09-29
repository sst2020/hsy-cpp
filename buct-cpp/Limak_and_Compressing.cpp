//
// Created by hsy on 2024/9/28.
//
#include <bits/stdc++.h>
using namespace std;
char s[40][7];
int ans = 0;
int n, q;
map <char, int> num;
void dfs(char c, int len)
{
    if (len == n - 1)
    {
        ans += num[c];
        return;
    }
    for (int i = 0; i < q; ++i)
    {
        if (c == s[i][3])
        {
            dfs(s[i][1], len + 1);
        }
    }
}
int main()
{
    scanf("%d %d", &n, &q);
    for (int i = 0; i < q; ++i)
    {
        scanf("%s %s", s[i] + 1, s[i] + 3);
        num[s[i][3]]++;
    }
    dfs('a', 1);
    printf("%d\n", ans);
    return 0;
}