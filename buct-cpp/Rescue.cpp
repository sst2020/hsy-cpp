#include <bits/stdc++.h>
using namespace std;
char arr[200 + 10][200 + 10]; //存储地牢地图
int arr1[200 + 10][200 + 10]; //标记走过的路
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0}; //代表方向
struct aa //将数据放入一个结构优先队列中，并按w的大小排序
{
    int x, y, w;
    friend bool operator<(const aa& x, const aa& y)
    {
        return x.w > y.w; //按照w的升序排列
    }
} aaa;
int bfs(int n, int m, int x1, int y1)
{
    memset(arr1, 0, sizeof(arr1)); //多组输入初始化数组
    priority_queue<aa>que;//构建队列
    aaa = {x1, y1, 0};
    que.push({x1, y1, 0});
    int xx, yy, xxx, yyy, w, s;
    while (!que.empty())
    {
        xx = que.top().x;
        yy = que.top().y;
        w = que.top().w; //取出队列的top;
        arr1[yy][xx] = 1; //将初始位置标记
        que.pop();//删除top，要现取现删
        for (int i = 0; i < 4; i++)
        {
            xxx = xx + dx[i];
            yyy = yy + dy[i]; //下一个位置的坐标
            if (xxx >= 0 && xxx < m && yyy >= 0 && yyy < n && arr[yyy][xxx] != '#' && arr1[yyy][xxx] == 0) //进行判断
            {
                if (arr[yyy][xxx] == '.')
                {
                    que.push({xxx, yyy, w + 1}); //如果是路w+1,并存入队列
                    arr1[yyy][xxx] = 1; //标记
                }
                else if (arr[yyy][xxx] == 'x')
                {
                    que.push({xxx, yyy, w + 2}); //如果是护卫w+2
                    arr1[yyy][xxx] = 1; //标记
                }
                else if (arr[yyy][xxx] == 'a')
                {
                    return w + 1; //等于a说明找到公主，此时所用时间最短，输出
                }
            }
        }
    }
    return 0;//没找到输出0；
}
int main()
{
    int n, m;
    while (cin >> n >> m)
    {
        int x, y, ans;
        for (int i = 0; i < n; i++) //构建地牢地图
        {
            cin >> arr[i];
            for (int j = 0; j < m; j++)
            {
                if (arr[i][j] == 'r')
                {
                    x = j;
                    y = i;
                }
            }
        }
        ans = bfs(n, m, x, y);
        if (ans) //判断输出
        {
            cout << ans << endl;
        }
        else
        {
            puts("Poor ANGEL has to stay in the prison all his life.");
        }
    }
    return 0;
}