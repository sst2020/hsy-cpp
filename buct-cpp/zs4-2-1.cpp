#include <bits/stdc++.h>
#define int long long
#define double long double
#define i128 __int128
using namespace std;
inline int read()
{
    int x = 0;
    char ch = getchar();
    while (!isdigit(ch))
    {
        ch = getchar();
    }
    while (isdigit(ch))
    {
        x = x * 10 + ch - '0', ch = getchar();
    }
    return x;
}
inline void write(int x)
{
    if (x == 0)
    {
        putchar('0');
        return;
    }
    int len = 0, k1 = x, c[10005];
    if (k1 < 0)
    {
        k1 = -k1, putchar('-');
    }
    while (k1)
    {
        c[len++] = k1 % 10 + '0', k1 /= 10;
    }
    while (len--)
    {
        putchar(c[len]);
    }
}
signed main()
{
    i128 a = read(), b = read(), x = read(), y = read();
    i128 t1 = a - b;
    if (t1 < 0)
    {
        t1 = -t1;
    }
    i128 ax = a - x, ay = a - y;
    i128 by = b - y, bx = b - x;
    if (ax < 0)
    {
        ax = -ax;
    }
    if (ay < 0)
    {
        ay = -ay;
    }
    if (bx < 0)
    {
        bx = -bx;
    }
    if (by < 0)
    {
        by = -by;
    }
    i128 t2 = ax + by;
    i128 t3 = ay + bx;
    write(min({t1, t2, t3}));
    return 0;
}