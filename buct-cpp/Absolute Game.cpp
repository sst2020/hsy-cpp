#include <bits/stdc++.h>
using namespace std;
const int N=2005;
int alice[N],bob[N];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&alice[i]);
	}
	for(int i=0;i<n;i++){
		scanf("%d",&bob[i]);
	}
	int ans=0;
	for(int i=0;i<n;i++){
		int mx=1e9+5;
		for(int j=0;j<n;j++){
			mx=min(mx,abs(alice[i]-bob[j]));
		}
		ans=max(ans,mx);
	}
	printf("%d",ans);
	return 0;
}
