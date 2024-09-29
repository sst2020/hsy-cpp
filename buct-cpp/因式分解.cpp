#include <bits/stdc++.h>
using namespace std;
void f(long long n){
	if(n<=1){
		return;
	}
	for(long long i=2;n>1;){
		if(n%i==0){
			printf("%lld ",i);
			n/=i;
		}else{
			if(i==2){
				i=3;
			}else i+=2;
		}
	}
	printf("\n");
}
int main(){
	long long n;
	while(cin>>n&&n>0){
		f(n);
	}
	return 0;
}
