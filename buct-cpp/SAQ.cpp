//
// Created by hsy on 2024/9/7.
//
#include <bits/stdc++.h>

using namespace std;
int n, q;
int main()
{
    scanf("%d%d", &n, &q);
    vector<int>a(q + 1);
    for (int i = 1; i <= q; ++i)
    {
        cin >> a[i];
    }
    int cnt = 0;
    vector<int> l(n + 1);
    vector<long long >s(q + 1), ans(n + 1);
    for (int i = 1; i <= q; ++i)
    {
        if (l[a[i]])
        {
            ans[a[i]] += s[i - 1] - s[l[a[i]] - 1];
            l[a[i]] = 0;
            cnt--;
        }
        else
        {
            l[a[i]] = i;
            cnt++;
        }
        s[i] = s[i - 1] + cnt;
    }
    for (int i = 1; i <= n; ++i)
    {
        if (l[i])
        {
            ans[i] += s[q] - s[l[i] - 1];
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        cout << ans[i] << " ";
    }
    printf("\n");
    return 0;
}