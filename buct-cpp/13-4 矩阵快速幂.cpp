//
// 模板
//
#include<cstdio>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
ll a[105][105], b;
int n;
ll ans[105][105] = {0};
inline ll read()
{
    char c = getchar();
    ll f = 1, x = 0;
    while (c < '0' || c > '9')
    {
        if (c == '-')
        {
            f = -1;
        }
        c = getchar();
    }
    while (c >= '0' && c <= '9')
    {
        x = (x << 1) + (x << 3) + (c^'0');
        c = getchar();
    }
    return x * f;
}
inline void Multip1()   //快速幂里的第一个乘法式子子ans=ans*a
{
    ll c[105][105] = {0};
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                c[i][j] = (c[i][j] + ans[i][k] * a[k][j]) % mod; //注意1e9+7
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            ans[i][j] = c[i][j];
        }
    }
}
inline void Multip2() //快速幂里的第而个乘法式子子a=a*a
{
    ll c[105][105] = {0};
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                c[i][j] = (c[i][j] + a[i][k] * a[k][j]) % mod;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            a[i][j] = c[i][j];
        }
    }
}
int main()
{
    n = (int)read(), b = read();
    for ( int i = 1; i <= n; i++)
    {
        for ( int j = 1; j <= n; j++)
        {
            a[i][j] = read();    //读入
        }
    }
    for ( int i = 1; i <= n; i++)
    {
        ans[i][i] = 1;    //把ans初始化成单位矩阵
    }
    while (b)  //快速幂
    {
        if (b & 1)
        {
            Multip1();
        }
        Multip2();
        b >>= 1;
    }
    for ( int i = 1; i <= n; i++) //输出
    {
        for ( int j = 1; j <= n; j++)
        {
            printf("%lld ", ans[i][j] % mod);
        }
        printf("\n");
    }
    return 0;
}