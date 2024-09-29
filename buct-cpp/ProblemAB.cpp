//
// Created by hsy on 2024/9/8.
//
#include <bits/stdc++.h>

using namespace std;
const int N = 105;
int n, m;
string s[N];
struct node
{
    int cnt, i;
} a[N];
bool cmp(node x, node y)
{
    return x.cnt == y.cnt ? x.i < y.i : x.cnt < y.cnt;
}
int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; ++i)
    {
        cin >> s[i];
        for (int j = 0; j < s[i].size(); ++j)
        {
            for (int k = j + 1; k < s[i].size(); ++k)
            {
                if (s[i][j] > s[i][k])
                {
                    a[i].cnt++;
                }
            }
        }
        a[i].i = i;
    }
    sort(a + 1, a + m + 1, cmp);
    for (int i = 1; i <= m; ++i)
    {
        cout << s[a[i].i] << endl;
        a[i] = {0, 0};
    }
    return 0;
}