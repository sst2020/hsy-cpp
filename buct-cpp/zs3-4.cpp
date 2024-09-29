//
// Created by hsy on 2024/9/23.
//
#include <bits/stdc++.h>

using namespace std;
const int mod = 998244353;
struct node
{
    int n;
    vector < vector<long long>> a;
    node(int m)
    {
        n = m;
        a.clear();
        a.resize(n, vector<long long>(n, 0));
    }
    node operator*(const node& s) const
    {
        node res(n);
        for (int i = 0; i < n; ++i)
        {
            for (int k = 0; k < n; ++k)
            {
                long long r = a[i][k];
                for (int j = 0; j < n; ++j)
                {
                    res.a[i][j] += s.a[k][j] * r;
                    res.a[i][j] %= mod;
                }
            }
        }
        return res;
    }
    node operator^(long long x) const
    {
        node res(n), base(n);
        for (int i = 0; i < n; ++i)
        {
            res.a[i][i] = 1;
        }
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                base.a[i][j] = a[i][j] % mod;
            }
        }
        while (x)
        {
            if (x & 1)
            {
                res = res * base;
            }
            x >>= 1;
            base = base * base;
        }
        return res;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<node> a(4, node(6));
    for (int i = 0; i < 6; ++i)
    {
        a[0].a[i][i] = 1;
    }
    for (int i = 0; i < 6; ++i)
    {
        a[1].a[i][min(i + 1, 5)] = 1;
    }
    for (int i = 1; i < 6; ++i)
    {
        a[2].a[i][i - 1] = 1;
    }
    a[2].a[0][1] = 1;
    for (int i = 0; i < 6; ++i)
    {
        if (i > 0)
        {
            a[3].a[i][i - 1] = 1;
        }
        a[3].a[i][min(i + 1, 5)] = 1;
    }
    long long n, k;
    cin >> n >> k;
    vector<int> s(4);
    for (int i = 0; i < 4; ++i)
    {
        cin >> s[i];
        a[0] = a[0] * a[s[i]];
    }
    a[0] = a[0] ^ (n / 4);
    for (int i = 0; i < n % 4; ++i)
    {
        a[0] = a[0] * a[s[i]];
    }
    node ans(6);
    ans.a[0][k] = 1;
    ans = ans * a[0];
    long long sum = 0;
    for (int i = 0; i < 6; ++i)
    {
        sum += ans.a[0][i];
        sum %= mod;
    }
    cout << sum << '\n';
    return 0;
}