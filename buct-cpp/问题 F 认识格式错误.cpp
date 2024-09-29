#include <bits/stdc++.h>
using namespace std;
int a[6][6];
int main(){
	for(int i=0;i<6;i++){
		for(int j=0;j<6;j++){
			scanf("%d",&a[i][j]);
		}
	}
	for(int i=0;i<6;i++){
		for(int j=0;j<6;j++){
			if(i==j){
				a[i][j]=a[i][j]+10;
			}
			else if(i+j==5){
				a[i][j]=a[i][j]+10;
			}
		}
	}
	for(int i=0;i<6;i++){
		for(int j=0;j<6;j++){
			printf("%5d",a[i][j]);
		}
		printf("\n");
	}
	return 0;
}
