#include <bits/stdc++.h>
using namespace std;
// 计算区间 [1, n] 内满足条件的数的数量

long long count(long long n) {
	long long count_even = n/2; 
	long long count_6 = n/6;
	long long count_4 = n/4;
	long long count_12 = n/12;
	// 应用包含-排除原则
	long long cnt = count_even - count_6 - count_4 + count_12;
	return cnt;
}
int main() {
	long long n;
	cin >> n;
	cout << count(n) << endl;
	return 0;
}
