#include <bits/stdc++.h>
using namespace std;
unsigned long long fibonacci(int n) {
	if (n <= 1) {
		return n;
	}
	std::vector<unsigned long long> fib(n + 1);
	fib[0] = 0;
	fib[1] = 1;
	for (int i = 2; i <= n; ++i) {
		fib[i] = fib[i - 1] + fib[i - 2];
	}
	return fib[n];
}
int main() {
	int n;
	scanf("%d",&n);
	unsigned long long result = fibonacci(n);
	printf("%lld",result);
	return 0;
}
