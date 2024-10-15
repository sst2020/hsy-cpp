//
// Created by hsy on 2024/10/4.
//
#include <bits/stdc++.h>
using namespace std;
int m, n;
bool cmp(pair<double, double> p1, pair<double, double> p2)
{
    return p1.first / p1.second > p2.first / p2.second;
}
int main()
{
    while (cin >> m >> n)
    {
        if (m == -1 && n == -1)
        {
            break;
        }
        double j, f;
        pair<double, double> pa[n];
        for (int i = 0; i < n; ++i)
        {
            cin >> j >> f;
            pa[i] = {j, f};
        }
        sort(pa, pa + n, cmp);
        double sum = 0;
        for (int i = 0; i < n; ++i)
        {
            if (pa[i].second <= m)
            {
                sum += pa[i].first;
                m -= pa[i].second;
            }
            else
            {
                sum += m * pa[i].first / pa[i].second;
                break;
            }
        }
        printf("%.3f\n", sum);
    }
    return 0;
}
