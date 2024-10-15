//
// Created by hsy on 2024/9/30.
//
#include <bits/stdc++.h>

using namespace std;
const int N = 1e5+10;
int n, m;
int a[N], p[N];
vector<int> b[N];
multiset<int> sot;
int main()
{
    scanf("%d %d", &n, &m);
    sot.clear();
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
        p[a[i]] = i;
        b[i].clear();
    }
    for (int i = 1; i <= m; ++i)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        x = p[x];
        y = p[y];
        if (x > y)
        {
            swap(x, y);
        }
        b[x].push_back(y);
        sot.insert(y);
    }
    long long ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (sot.empty())
        {
            ans += n - i + 1;
        }
        else
        {
            ans += *sot.begin() - i;
        }
        for (int j = b[i].size() - 1; ~j; --j)
        {
            sot.erase(sot.find(b[i][j]));
        }
    }
    printf("%lld\n", ans);
    return 0;
}