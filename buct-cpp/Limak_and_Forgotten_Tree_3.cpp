//
// Created by hsy on 2024/9/29.
//
#include <bits/stdc++.h>

using namespace std;
vector<pair<int, int>> g;
int n, d, h;
int main()
{
    scanf("%d %d %d", &n, &d, &h);
    int node = n;
    if ((n >= 3 && d == 1) || (n >= 3 && d > 2 * h))
    {
        printf("-1\n");
        return 0;
    }
    int cnt = 1;
    int pre = 1, nxt = 2;
    if (d == h)
    {
        for (int i = 1; i <= h; ++i)
        {
            g.emplace_back(pre, nxt);
            pre = nxt;
            nxt++;
            cnt++;
        }
        pre = 1;
        if (node > cnt)
        {
            int remNode = node - cnt;
            for (int i = cnt + 1; i <= node; ++i)
            {
                g.emplace_back(2, i);
            }
        }
    }
    else if (d == 2 * h)
    {
        pre = 1;
        for (int i = 1; i <= 2; ++i)
        {
            pre = 1;
            for (int j = 1; j <= h; ++j)
            {
                g.emplace_back(pre, nxt);
                pre = nxt;
                nxt++;
                cnt++;
            }
        }
        if (node > cnt)
        {
            int remNode = node - cnt;
            for (int i = cnt + 1; i <= node; ++i)
            {
                g.emplace_back(1, i);
            }
        }
    }
    else if ((d != 2 * h) && (d > h))
    {
        pre = 1;
        for (int i = 1; i <= h; ++i)
        {
            g.emplace_back(pre, nxt);
            pre = nxt;
            nxt++;
            cnt++;
        }
        pre = 1;
        for (int j = 1; j <= (d - h); ++j)
        {
            g.emplace_back(pre, nxt);
            pre = nxt;
            nxt++;
            cnt++;
        }
        if (node > cnt)
        {
            int remNode = node - cnt;
            for (int i = cnt + 1; i <= node; ++i)
            {
                g.emplace_back(2, i);
            }
        }
    }
    for (auto a : g)
    {
        printf("%d %d\n", a.first, a.second);
    }
    return 0;
}