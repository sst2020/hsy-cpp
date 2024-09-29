#include <bits/stdc++.h>
using namespace std;
const double pi=3.1415927;
int main(){
	double radius;
	while(cin>>radius){
		double v=(4.0/3.0)*pi*pow(radius,3);
		printf("%.3lf\n",v);
	}
	return 0;
}
