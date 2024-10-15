//
// Created by hsy on 2024/10/7.
//
#include <bits/stdc++.h>
using namespace std;
const int M = 1e5;
int n, S;
struct qnode
{
    int a, b, c;
} q[M + 5];
struct tnode
{
    int l, r, lzb;
} t[M * 4 + 5];
int num, cnt;
vector<int> son[M + 5];
int st[M + 5], en[M + 5];
long long m[M + 5], s[M + 5];
void  dfs(int v)
{
    ++cnt;
    st[v] = cnt;
    for (auto x : son[v])
    {
        dfs(x);
    }
    en[v] = cnt;
}
void push_down(int k)
{
    if (!t[k].lzb)
    {
        return;
    }
    if (t[k << 1].l == t[k << 1].r)
    {
        s[t[k << 1].l] += t[k].lzb * m[t[k << 1].l];
    }
    else
    {
        t[k << 1].lzb += t[k].lzb;
    }
    if (t[k << 1 | 1].l == t[k << 1 | 1].r)
    {
        s[t[k << 1 | 1].l] += t[k].lzb * m[t[k << 1 | 1].l];
    }
    else
    {
        t[k << 1 | 1].lzb += t[k].lzb;
    }
    t[k].lzb = 0;
}
void build(int k, int l, int r)
{
    t[k].l = l;
    t[k].r = r;
    if (l == r)
    {
        return;
    }
    int mid = (l + r) >> 1;
    build(k << 1, l, mid);
    build(k << 1 | 1, mid + 1, r);
}
void up1(int k, int a, int b)
{
    if (t[k].l == t[k].r)
    {
        m[t[k].l] = b;
        return;
    }
    push_down(k);
    int mid = (t[k].l + t[k].r) >> 1;
    if (a <= mid)
    {
        up1(k << 1, a, b);
    }
    else
    {
        up1(k << 1 | 1, a, b);
    }
}
void up2(int k, int a, int b, int c)
{
    if (t[k].l > a && t[k].r <= b)
    {
        if (t[k].l == t[k].r)
        {
            s[t[k].l] += m[t[k].l] * c;
        }
        else
        {
            t[k].lzb += c;
        }
        return;
    }
    push_down(k);
    int mid = (t[k].l + t[k].r) >> 1;
    if (a <= mid)
    {
        up2(k << 1, a, b, c);
    }
    if (mid < b)
    {
        up2(k << 1 | 1, a, b, c);
    }
}
long long query(int k, int a)
{
    if (t[k].l == t[k].r)
    {
        return s[t[k].l];
    }
    push_down(k);
    int mid = (t[k].l + t[k].r) >> 1;
    if (a <= mid)
    {
        query(k << 1, a);
    }
    else
    {
        query(k << 1 | 1, a);
    }
    return 0;
}
int main()
{
    scanf("%d %d", &n, &S);
    num = 1;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d %d", &q[i].a, &q[i].b);
        if (q[i].a == 2 || q[i].a == 3)
        {
            scanf("%d", &q[i].c);
        }
        if (q[i].a == 1)
        {
            son[q[i].b].push_back(++num);
            q[i].b = num;
        }
    }
    dfs(1);
    build(1, 1, cnt);
    up1(1, st[1], S);
    for (int i = 1; i <= n; ++i)
    {
        if (q[i].a == 1)
        {
            up1(1, st[q[i].b], S);
        }
        else if (q[i].a == 2)
        {
            up1(1, st[q[i].b], q[i].c);
        }
        else if (q[i].a == 3)
        {
            up2(1, st[q[i].b], en[q[i].b], q[i].c);
        }
        else if (q[i].a == 4)
        {
            printf("%lld\n", query(1, st[q[i].b]));
        }
    }
    return 0;
}