//
// Created by hsy on 2024/10/6.
//
#include <bits/stdc++.h>

using namespace std;
struct node
{
    int p = 0;
    int d{};
};
struct cmp
{
    bool operator()(const node a, const node b)const
    {
        if (a.p == b.p)
        {
            return a.d > b.d;
        }
        else
        {
            return a.p > b.p;
        }
    }
};
int main()
{
    int t, n;
    scanf("%d", &t);
    while (t --)
    {
        priority_queue<node, vector<node>, cmp> pq;
        node Node;
        scanf("%d", &n);
        while (!pq.empty())
        {
            pq.pop();
        }
        for (int i = 0; i < n; ++i)
        {
            scanf("%d %d", &Node.p, &Node.d);
            pq.push(Node);
        }
        int flag = 1;
        while (!pq.empty())
        {
            Node = pq.top();
            pq.pop();
            if (flag % 2 == 1)
            {
                Node.p += Node.d;
                pq.push(Node);
            }
            flag++;
        }
        printf("%d\n", Node.p);
    }
    return 0;
}