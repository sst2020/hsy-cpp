#include <bits/stdc++.h>
using namespace std;
int a[10+5][10+5];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		a[0][i]=i+1;
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<n;j++){
			a[i][j]=a[i-1][(j+1)%n];
		}
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<n+i;j++){
			for(int k=0;k<n;k++){
				printf("%d ",a[j%n][k]);
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}
