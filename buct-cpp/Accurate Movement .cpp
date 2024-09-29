#include <bits/stdc++.h>
using namespace std;
void moves(){
	int cnt=0;
	int a,b,n;
	scanf("%d%d%d",&a,&b,&n);
	int A(a),B(b);
	while(B<n){
		if(A<n){
			A=B;
		}
		cnt++;
		B+=(b-a);
		cnt++;
	}
	printf("%d",cnt+(A<n));
}
int main(){
	moves();
	return 0;
}

