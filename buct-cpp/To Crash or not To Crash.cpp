#include <bits/stdc++.h>
using namespace std;
char s[5][15];
int main(){
	int x,y;
	while(cin>>s[0]){
		for(int i=1;i<3;i++){
			scanf("%s",s[i]);
		}
		string tmp;
		getline(cin,tmp);
		for(int i=0;i<3;i++){
			for(int j=0;j<10;j++){
				if(s[i][j]=='='){
					x=i,y=j;
					break;
				}
			}
		}
		int l=y+1;
		while(l<10){
			if(s[x][l]!='.'){
				break;
			}
			l++;
		}
		if(l<10){
			printf("%c\n",s[x][l]);
		}else printf("You shall pass!!!\n");
		printf("\n");
	}
	return 0;
}
