#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[30][10], digit[30];
int main()
{
    ll m, n, lenm = 0, lenn = 0;
    memset(dp, 0, sizeof(dp));
    memset(digit, 0, sizeof(digit));
    dp[0][0] = 1;
    for (ll i = 0; i < 30; ++i)
    {
        for (ll j = 0; j < 10; ++j)
        {
            for (ll k = 0; k < 10; ++k)
            {
                if (j != 4)
                {
                    dp[i][j] += dp[i - 1][k];
                }
            }
        }
    }
    auto sum = [&](ll len)
    {
        ll ans = 0;
        for (ll i = len; i > 0; --i)
        {
            for (ll j = 0; j < digit[i]; ++j)
            {
                if (j != 4)
                {
                    ans += dp[i][j];
                }
            }
            if (digit[i] == 4)
            {
                ans--;
                break;
            }
        }
        return ans;
    };
    scanf("%lld %lld", &m, &n);
    auto flag = [&](const string& s)->bool
    {
        for (char i : s)
        {
            if (i == '4')
            {
                return false;
            }
        }
        return true;
    };
    ll tmp = flag(to_string(m));
    while (m)
    {
        digit[++lenm] = m % 10;
        m /= 10;
    }
    ll a = sum(lenm);
    while (n)
    {
        digit[++lenn] = n % 10;
        n /= 10;
    }
    ll b = sum(lenn);
    printf("%lld\n", b - a + tmp);
    return 0;
}