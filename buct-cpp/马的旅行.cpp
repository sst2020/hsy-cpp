#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 100;
int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
int bfs(int n,int m){
	vector<vector<bool>> v(n+1,vector<bool>(m+1,0));
	queue<pair<int, int>> q;
	q.push(make_pair(1,1));
	v[1][1]=1;
	int cnt=1;
	while(!q.empty()){
		pair<int,int> current=q.front();
		q.pop();
		for(int i=0;i<8;i++){
			int nx=current.first+dx[i];
			int ny=current.second+dy[i];
			if(nx >= 1 && nx <= n && ny >= 1 && ny <= m && !v[nx][ny]){
				v[nx][ny]=1;
				q.push(make_pair(nx,ny));
				++cnt;
			}
		}
	}
	return cnt;
}
int big(int n,int m){
	return n*m;
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	if(n==1||m==1){
		printf("1");
		return 0;
	}
	if(n==2||m==2){
		int cnt=0;
		cnt=max(n,m)/3+1;
		printf("%d",cnt);
	}
	if((n>=3&&m>3)||(n>3&&m>=3)){
		printf("%d",big(n,m));
	}else{
		printf("%d",bfs(n,m));
	}
	return 0;
}
