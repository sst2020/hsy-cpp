#include <bits/stdc++.h>
using namespace std;
char d[2050][2050];
int main(){
	int n,h=2,wid=4;
	scanf("%d",&n);
	memset(d,' ',sizeof(d));
	d[0][0]=d[1][1]='/';
	d[3][0]=d[2][1]='\\';
	d[1][0]=d[2][0]='_';
	int step=0;
	while(step++<n-1){
		for(int i=0;i<h;i++){
			for(int j=0;j<wid;j++){
				d[j+wid/2][i+h]=d[j+wid][i]=d[j][i];
			}
		}
		wid*=2;
		h*=2;
	}
	for(int i=h-1;i>=0;i--){
		for(int j=0;j<wid;j++){
			printf("%c",d[j][i]);
		}
		printf("\n");
	}
	return 0;
}
