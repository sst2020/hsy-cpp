//
// Created by hsy on 2024/10/10.
//
#include <bits/stdc++.h>
using namespace std;
int sushu(long long n)
{
    if(n<=1) return 0;
    for(long long i=2;i*i<=n;++i){
        if(n%i==0) return 0;
    }
    return 1;
}
int main()
{
    long long m;
    while(1){
        scanf("%lld",&m);
        if(m==0) break;
        if(m%6==5 || m%6==1||m==2||m==3){
            if(sushu(m)){
                printf("OK\n");
            }
            else{
                printf("Sorry\n");
            }
        }
        else{
            printf("Sorry\n");
        }
    }
    return 0;
}