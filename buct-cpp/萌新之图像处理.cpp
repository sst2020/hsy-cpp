#include <bits/stdc++.h>
using namespace std;
vector<vector<string>> templates = {
	
	{ "@@@", "@@@", "@@@" },
	
	{ ".@.", "@@.", "..@" },
	
	{ "@@@", "..@", "@@@" },
	
	{ "@@@", "..@", "@@@" },
	
	{ "@@.", ".@.", "@@." },
	
	{ "@@@", "@@.", "@@@" },
	
	{ "@@@", "@@.", "@@@" },
	
	{ "..@", ".@.", "@@." },
	
	{ "@@@", "@@.", "@@@" },
	
	{ "@@@", "@@.", "..@" }
	
};
int computeSimilarity(const vector<string>& pattern, const vector<string>& templatePattern) {
	int similarity = 0;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 5; ++j) {
			if (pattern[i][j] == templatePattern[i][j]) {
				++similarity;
			}
		}
	}
	return similarity;
}
int main(){
	int n;
	scanf("%d",&n);
	assert(n>=1&&n<=10);
	vector<vector<string>> patterns(n, vector<string>(3));
	for(int i=0;i<n;i++){
		for(int j=0;j<=3;j++){
			cin>>patterns[i][j];
		}
	}
	string result;
	for(int i=0;i<n;i++){
		int match=-1;
		int maxSimilarity=-1;
		for(int j=0;j<10;j++){
			int similarity=computeSimilarity(patterns[i],templates[j]);
			if(similarity>maxSimilarity){
				maxSimilarity=similarity;
				match=j;
			}
		}
		result+=to_string(match);
	}
	cout<<result;
	return 0;
}
