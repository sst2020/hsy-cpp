#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define INF 0x3f3f3f3f3f3f
priority_queue<int>p[110];
void init()
{
    for (int i = 0; i <= 100; i++)
    {
        while (!p[i].empty())
        {
            p[i].pop();
        }
    }
}
int main()
{
    int t;
    int sum = 1;
    cin >> t;
    while (t--)
    {
        init();
        printf("Case #%d:\n", sum++);
        ll n, st0, t0, t1, r, id, va;
        char a[5];
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a;
            if (a[0] == 'P')
            {
                cin >> t0 >> st0 >> r;
                p[r].push(st0 - r* t0);
            }
            else
            {
                cin >> t1;
                id = -1;
                va = -INF;
                for (int j = 100; j >= 0; j--)
                {
                    if (p[j].empty())
                    {
                        continue;
                    }
                    ll vaa = p[j].top();
                    vaa = vaa + j * t1;
                    if (vaa > va)
                    {
                        va = vaa;
                        id = j;
                    }
                }
                p[id].pop();
                cout << va << " " << id << endl;
            }
        }
    }
    return 0;
}