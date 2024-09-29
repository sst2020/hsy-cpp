//
// Created by hsy on 2024/9/11.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 5;
int a[N];
map<int, int> m;
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        m.clear();
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", &a[i]);
        }
        int cnt = 0;
        m[a[1]] = 1;
        for (int i = 2; i <= n - 1; ++i)
        {
            for (int j = i + 1; j <= n; ++j)
            {
                int ak = 2 * a[i] - a[j];
                if (ak < 0 || !m.count(ak))
                {
                    continue;
                }
                cnt += m[ak];
            }
            m[a[i]]++;
        }
        printf("%d\n", cnt);
    }
    return 0;
}
