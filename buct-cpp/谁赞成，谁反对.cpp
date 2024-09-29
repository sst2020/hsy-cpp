#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	vector<int> dp(n+1,0);
	dp[1]=100;
	for (int i = 2; i <= n; ++i) {
		
		int maxPackets = 0;
		
		for (int k = 0; k < i; ++k) {
			
			// k 是前 k 个人中最后一个决策者的索引
			
			// i - k - 1 是剩下的人中的决策者索引
			
			// 如果决策者给第 k 个人 100 - dp[k] 个红包，那么 k 个人会支持
			
			// 且 dp[k] + dp[i-k-1] < 100 - dp[k] 则方案可以通过
			
			if ((k == 0 || dp[k] + dp[i - k - 1] < 100 - dp[k]) && 100 - dp[k] > maxPackets) {
				
				maxPackets = 100 - dp[k];
				
			}
			
		}
		
		dp[i] = maxPackets;
		
	}
	cout<<dp[n];
	return 0;
}
