//
// Created by hsy on 2024/10/4.
//
#include <bits/stdc++.h>

using namespace std;
struct node
{
    int t, num;
} t[1005];
int n;
double sum = 0;
bool cmp(node a, node b)
{
    return a.t < b.t ? 1 : 0;
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &t[i].t);
        t[i].num = i;
    }
    sort(t + 1, t + n + 1, cmp);
    for (int i = 1; i <= n; ++i)
    {
        if (t[i].t == t[i + 1].t && t[i].num > t[i + 1].num)
        {
            swap(t[i], t[i + 1]);
        }
        printf("%d ", t[i].num);
        if (i < n)
        {
            sum += t[i].t * (n - i);
        }
    }
    printf("\n");
    printf("%.2lf", sum / n);
    return 0;
}