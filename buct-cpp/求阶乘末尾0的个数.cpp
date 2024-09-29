#include <bits/stdc++.h>
using namespace std;
// 函数用于计算阶乘末尾0的个数

int countTrailingZeros(long long n) {
	
	if (n == 0) return 0;
	
	int zeros = 0;
	
	for (long long divisor = 5; n / divisor > 0; divisor *= 5) {
		
		zeros += n / divisor;
		
	}
	
	return zeros;
	
}


int main() {
	
	long long n;
	
	while (cin >> n && n >= 0 && n <= 100000) {
		
		cout << countTrailingZeros(n) << endl;
		
	}
	
	return 0;
	
}
