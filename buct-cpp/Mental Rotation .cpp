#include <bits/stdc++.h>
using namespace std;
char a[1005][1005];
char a1[1005][1005];
int n;
int main(){
	char s[105];
	while(cin>>n){
		getchar();
		cin>>s;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cin>>a[i][j];
			}
		}
		int l=0,r=0;
		for(int i=0;s[i]!='\0';i++){
			if(s[i]=='L'){
				l++;
			}else r++;
		}
		l=l%4;
		r=r%4;
		r=(r+4-l)%4;
		while(r--){
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					if(a[i][j]=='>')
						a1[j][n-1-i]='v';
					else if(a[i][j]=='<')
						a1[j][n-1-i]='^';
					else if(a[i][j]=='^')
						a1[j][n-1-i]='>';
					else if(a[i][j]=='.')
						a1[j][n-1-i]='.';
					else if(a[i][j]=='v')
						a1[j][n-1-i]='<';
				}
			}
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					a[i][j]=a1[i][j];
				}
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cout<<a[i][j];
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}
