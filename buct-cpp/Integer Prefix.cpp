#include <bits/stdc++.h>
using namespace std;
int main(){
	string t;
	cin>>t;
	int i=0;
	for(;i<t.length()&&isdigit(t[i]);i++);
	if(i>0){
		cout<<t.substr(0,i)<<endl;
	}else{
		cout<<"-1"<<endl;
	}
	return 0;
}
