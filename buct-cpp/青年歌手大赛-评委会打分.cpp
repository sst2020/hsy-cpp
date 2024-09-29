#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	while(cin>>n){
		if(cin.eof()){
			break;
		}
		vector<int> scores(n);
		for(int& score : scores){
			cin>>score;
		}
		sort(scores.begin(),scores.end());
		scores.erase(scores.begin());
		scores.pop_back();
		double sum=0;
		for(int score : scores){
			sum+=score;
		}
		printf("%.2lf\n",sum/scores.size());
	}
	return 0;
}
