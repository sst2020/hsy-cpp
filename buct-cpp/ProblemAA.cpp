//
// Created by hsy on 2024/9/8.
//
#include <bits/stdc++.h>

using namespace std;
struct node
{
    int cnt;
    int num;
} milk[10005];
bool cmp(node a, node b)
{
    return a.num < b.num;
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &milk[i].num);
        milk[i].cnt = i;
    }
    sort(milk + 1, milk + n + 1, cmp);
    int ans = (n + 1) / 2;
    printf("%d", milk[ans].num);
    return 0;
}