#include <iostream>

#include <vector>

#include <queue>


using namespace std;


const int MAX_N = 100; // 假设棋盘最大不超过100x100

int n, m;

bool visited[MAX_N][MAX_N]; // 标记是否访问过某个格子

int dx[] = {2, 1, -1, -2, -2, -1, 1, 2}; // 马的8种移动方向的行变化

int dy[] = {1, 2, 2, 1, -1, -2, -2, -1}; // 马的8种移动方向的列变化


// 广度优先搜索算法

void bfs() {
	
	queue<pair<int, int>> q;
	
	q.push(make_pair(1, 1));
	
	visited[1][1] = true; // 左上角起始位置
	
	
	while (!q.empty()) {
		
		pair<int, int> current = q.front();
		
		q.pop();
		
		
		for (int i = 0; i < 8; ++i) {
			
			int nx = current.first + dx[i];
			
			int ny = current.second + dy[i];
			
			
			// 检查新位置是否在棋盘内且未被访问过
			
			if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && !visited[nx][ny]) {
				
				visited[nx][ny] = true;
				
				q.push(make_pair(nx, ny));
				
			}
			
		}
		
	}
	
}


int main() {
	
	cin >> n >> m; // 输入棋盘的大小
	
	bfs(); // 进行广度优先搜索
	
	int count = 0;
	
	
	// 统计访问过的格子数量
	
	for (int i = 1; i <= n; ++i) {
		
		for (int j = 1; j <= m; ++j) {
			
			if (visited[i][j]) {
				
				++count;
				
			}
			
		}
		
	}
	
	
	cout << count << endl; // 输出可到达的不同格子数量
	
	return 0;
	
}
