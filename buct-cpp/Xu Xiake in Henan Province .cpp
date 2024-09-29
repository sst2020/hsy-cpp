#include <bits/stdc++.h>
using namespace std;
string de(const vector<int>& visits){
	int cnt=0;
	for(int visit : visits){
		if(visit>0){
			++cnt;
		}
	}
	switch (cnt) {
	case 0: return "Typically Otaku";
	case 1: return "Eye-opener";
	case 2: return "Young Traveller";
	case 3: return "Excellent Traveller";
	case 4: return "Contemporary Xu Xiake";
	default: return "Unknown";
	break;
	}
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		vector<int> visits={a,b,c,d};
		string level=de(visits);
		cout<<level<<endl;
	}
	return 0;
}
