#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a = 0, b = 0, n;
    scanf("%d", &n);
    int cnt = 1;
    while (n -- )
    {
        int x, y;
        scanf("%d %d", &x, &y);
        int p = max(a, b);
        int q = min(x, y);
        if (q >= p)
        {
            cnt += q - p + 1;
        }
        if (a == b)
        {
            cnt--;
        }
        a = x;
        b = y;
        cerr << cnt;
    }
    printf("%d", cnt);
    return 0;
}