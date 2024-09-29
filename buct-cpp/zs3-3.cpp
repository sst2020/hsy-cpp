//
// Created by hsy on 2024/9/23.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5, mod = 1e9+7;
int f[N], inv[N];
int qpow(int a, int b, int p)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
        {
            res = res * (long long)a % p;
            b >>= 1;
            a = a * (long long)a % p;
        }
    }
    return res;
}
long long c(int n, int m)
{
    if (n < 0 || m < 0 || m > n)
    {
        return 0;
    }
    return (long long)f[n] * inv[n - m] % mod * inv[m] % mod;
}
void pre(int n)
{
    f[0] = inv[0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        f[i] = (long long)f[i - 1] * i % mod;
        inv[i] = (long long)inv[i - 1] * qpow(i, mod - 2, mod) % mod;
    }
}
int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    pre(n);
    vector<int> a(n);
    for (auto &x : a)
    {
        scanf("%d", &x);
    }
    sort(a.begin(), a.end());
    long long ans = 0;
    for (int i = 0; i < n; ++i)
    {
        ans += 1LL * a[i] * c(i, k - 1) % mod;
        ans %= mod;
        ans -= 1LL * a[i] * c(n - i - 1, k - 1) % mod;
        ans = (ans % mod + mod) % mod;
    }
    printf("%lld\n", ans);
    return 0;
}