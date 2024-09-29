#include <bits/stdc++.h>
using namespace std;
char s[5050];
bool isPalindrome(const char *s, int p){
	int l=p,r=strlen(s)-1;
	while(l<=r){
		if(s[l]==s[r]){
			l++;r--;
		}else return 0;
	}
	return 1;
}

int main(){
	cin>>s;
	int pos,len=strlen(s);
	for(int i=0;i<len;i++){
		if(isPalindrome(s,i)){
			pos=i;break;
		}
	}
	cout<<s;
	for(int i=pos-1;i>=0;i--){
		cout<<s[i];
	}
	printf("\n");
	return 0;
}
