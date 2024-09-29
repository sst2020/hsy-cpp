#include <bits/stdc++.h>
using namespace std;
int main(){
	double sum=0;
	double b,c;
		while( scanf("%*s%lf%lf", &b,&c) != EOF ){
			sum+=(b*c);
		}
		printf("%.1lf\n",sum);
	return 0;
}
