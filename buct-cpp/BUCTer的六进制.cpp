#include <bits/stdc++.h>
using namespace std;
int charToHex(char c) {
	
	static const map<char, int> hexMap = {
		{'B', 0}, {'U', 1}, {'C', 2}, {'T', 3},{'e', 4}, {'r', 5}
	};
	auto it = hexMap.find(c);
	if (it != hexMap.end()) {
		return it->second;
	}
	return -1;
}
int hexToDecimal(const string& hex){
	int d=0;
	int power=1;
	for(int i=hex.length()-1;i>=0;i--){
		int val = charToHex(hex[i]);
		d+=val*power;
		power*=6;
	}
	return d;
}
int main(){
	string s1,s2;
	cin>>s1>>s2;
	int num1=hexToDecimal(s1);
	int num2=hexToDecimal(s2);
	cout<<num1+num2;
	return 0;
}
