#include <bits/stdc++.h>
using namespace std;
string ds(int a,int b){
	if((a>=11&&b<=9)||(b>=11&&a<=9)){
		return "Game Over";
	}
	if((a==10&&b==10)||a>10||b>10){
		int point=a+b;
		return (point%2==0)?"A":"B";
	}
	int point=a+b;
	return (point%4<2)?"A":"B";
}
int main(){
	int a,b;
	while(cin>>a>>b){
		cout<<ds(a,b)<<endl;
	}
	return 0;
}
