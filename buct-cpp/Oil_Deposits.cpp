#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100 + 5;
int m, n, cnt;
char graph[MAXN][MAXN];
void dfs(int x, int y)
{
    graph[x][y] = '*';
    for (int dx = -1; dx <= 1; dx++)
    {
        for (int dy = -1; dy <= 1; dy++)
        {
            int nx = x + dx, ny = y + dy; //be careful!! don't change x and y
            if ((!dx && !dy) || nx >= m || nx < 0 || ny >= n || ny < 0
                    || graph[nx][ny] == '*')
            {
                continue;
            }
            dfs(nx, ny);
        }
    }
}
int main()
{
    while (scanf("%d %d", &m, &n) == 2 && m)
    {
        for (int i = 0; i < m; i++)
        {
            scanf("%s", graph[i]);
        }
        cnt = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (graph[i][j] == '@')
                {
                    dfs(i, j);
                    cnt++;
                }
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}