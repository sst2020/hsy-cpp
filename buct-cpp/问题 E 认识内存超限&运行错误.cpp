#include <bits/stdc++.h>
using namespace std;
int n,sum1=0,tmp=0;
int main(){
	scanf("%d",&n);
	sum1=n;
	for(int i=1;i<n;i++){
		scanf("%d",&tmp);
		sum1+=i;
		sum1-=tmp;
	}
	printf("%d",sum1);
	return 0;
}
