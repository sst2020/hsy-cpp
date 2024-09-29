#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	vector<int> candy(n);
	for(auto& can:candy){
		cin>>can;
	}
	sort(candy.begin(),candy.end(),greater<int>());
	int alice=0,bob=0;
	for(int i=0;i<n;i++){
		if(i%2==0){
			alice+=candy[i];
		}else bob+=candy[i];
	}
	printf("%d",abs(alice-bob));
	return 0;
}
