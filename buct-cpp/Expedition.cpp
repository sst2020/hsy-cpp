//
// Created by hsy on 2024/10/6.
//
#include <bits/stdc++.h>

using namespace std;
const int MAXN = 10005;
int n, l, p;
struct T
{
    int a, b;
};
bool cmp(T a, T b)
{
    return a.a < b.a;
}
int main()
{
    scanf("%d", &n);
    T t[MAXN];
    for (int i = 0; i < n; ++i)
    {
        scanf("%d %d", &t[i].a, &t[i].b);
    }
    scanf("%d %d", &l, &p);
    for (int i = 0; i < n; ++i)
    {
        t[i].a = l - t[i].a;
    }
    sort(t, t + n, cmp);
    priority_queue<int> q;
    int k = p;
    p = 0;
    int res = 0, left = 0;
    while (k < l)
    {
        for (int i = left; i < n; ++i)
        {
            if (k >= t[i].a)
            {
                left = i + 1;
                q.push(t[i].b);
            }
        }
        if (!q.empty())
        {
            p += q.top();
            q.pop();
            res++;
        }
        else
        {
            printf("-1\n");
            return 0;
        }
        k += p;
        p = 0;
    }
    printf("%d\n", res);
    return 0;
}