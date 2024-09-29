#include <bits/stdc++.h>
using namespace std;
int t;
int main(){
	scanf("%d",&t);
	int tmp,f=0;
	for(int i=1;i<=t;i++){
		scanf("%d",&tmp);
		for(int j=2;j*j<=tmp;j++){
			f=0;
			if(tmp%j==0){
				f=1;
				printf("no\n");
				break;
			}
		}
		if(f==0) printf("yes\n");
	}
	return 0;
}
