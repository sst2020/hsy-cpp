#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
const int MAXM = 105;
int sp[MAXN];
int main(){
	int m,kase=0;
	scanf("%d",&m);
	while(m--){
		int n,cnt=0;
		long long ans=0;
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d",sp+i);
		}
		sort(sp,sp+n);
		for(int i=0;i<n;i++){
			if(ans<=sp[i]){
				cnt++;
				ans+=sp[i];
			}
		}
		printf("Case #%d: %d\n",++kase,cnt);
	}
	return 0;
}
