#include <bits/stdc++.h>
using namespace std;
int main(){
	long long n,ans=-100;
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		long long tmp;
		scanf("%lld",&tmp);
		tmp=abs(tmp);
		ans=max(ans,tmp);
	}
	printf("%lld",ans);
	return 0;
}
