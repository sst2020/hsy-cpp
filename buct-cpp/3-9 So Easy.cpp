#include <bits/stdc++.h>
using namespace std;
const int INF=1e9;
int main(){
	int n;
	scanf("%d",&n);
	vector<vector<int>> a(n,vector<int>(n));
	int x,y;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&a[i][j]);
			if(a[i][j]==-1){
				x=i;y=j;
			}
		}
	}
	int ans;
	if(x<n-1&&y<n-1){
		ans=a[x+1][y]+a[x][y+1]-a[x+1][y+1];
	}else if(x==n-1&&y!=n-1){
		ans=a[x-1][y]+a[x][y+1]-a[x-1][y+1];
	}else if(y==n-1&&x!=n-1){
		ans=a[x+1][y]+a[x][y-1]-a[x+1][y-1];
	}else if(x==n-1&&y==n-1){
		ans=a[x-1][y]+a[x][y-1]-a[x-1][y-1];
	}
	printf("%d",ans);
}
