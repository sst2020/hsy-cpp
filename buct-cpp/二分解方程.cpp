//
// Created by hsy on 2024/10/7.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 100000;
long long a[N];
double cal(double x)
{
    double ans = 8.0 * x * x * x * x + 7.0 * x * x * x + 2.0 * x * x + 3 * x + 6.0;
    return ans;
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        double y;
        scanf("%lf", &y);
        double l = 0, r = 100;
        while (r - l > 1e-10)
        {
            double mid = (l + r) / 2.0;
            if (cal(mid) >= y)
            {
                r = mid;
            }
            else
            {
                l = mid;
            }
        }

        double tmp = cal(l);
        if (fabs(tmp - y) <= 1e-3)
        {
            printf("%.4lf\n", l);
        }
        else
        {
            printf("No solution!\n");
        }
    }
    return 0;
}