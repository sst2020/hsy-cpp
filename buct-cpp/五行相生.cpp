#include <bits/stdc++.h>
using namespace std;
int main(){
	int gem[5];
	for(int i=0;i<5;i++){
		cin>>gem[i];
	}
	int result=0;
	for(int gems:gem){
		result ^= gems;
	}
	if(result!=0){
		printf("%d",result);
	}else{
		printf("0");
	}
	return 0;
}
