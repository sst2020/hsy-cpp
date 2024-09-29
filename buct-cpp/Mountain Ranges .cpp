#include <bits/stdc++.h>
using namespace std;
int mvs(const vector<int>& h,int mr){
	int ms=0;
	for(size_t i=0;i<h.size();i++){
		int scenes=1;
		for(size_t j=i+1;j<h.size();j++){
			if(h[j]-h[j-1]<=mr){
				++scenes;
			}else break;
		}
		ms=max(ms,scenes);
	}
	return ms;
}
int main(){
	int n,x;
	scanf("%d%d",&n,&x);
	vector<int> h(n);
	for(int i=0;i<n;i++){
		scanf("%d",&h[i]);
	}
	printf("%d",mvs(h,x));
	return 0;
}
