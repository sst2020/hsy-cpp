#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	vector<int> news(n);
	vector<int> olds(n);
	for(auto& val:news){
		cin>>val;
	}
	for(auto& val:olds){
		cin>>val;
	}
	sort(news.begin(),news.end());
	sort(olds.begin(),olds.end());
	int diff=0;
	for(int i=0;i<n;i++){
		diff+=abs(news[i]-olds[i]);
	}
	printf("%d",diff);
	return 0;
}
