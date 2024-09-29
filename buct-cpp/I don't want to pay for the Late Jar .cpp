#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct r{
	ll f;
	ll t;
};
bool cmp(const r &a,const r &b){
	if(a.t==b.t){
		return a.f>b.f;
	}
	return a.t<b.t;
}
int main(){
	int d;
	scanf("%d",&d);
	for(int i=1;i<=d;i++){
		ll n,s;
		scanf("%lld%lld",&n,&s);
		vector<r> rs(n);
		for(ll j=0;j<n;j++){
			scanf("%lld%lld",&rs[j].f,&rs[j].t);
		}
		sort(rs.begin(),rs.end(),cmp);
		bool no_save=1;
		ll max_save=-1;
		for(const auto &r : rs){
			ll saved=r.f-max(0LL,r.t-s);
			if(saved>=0){
				no_save=0;
				max_save=max(max_save,saved);
			}
		}
		if(no_save){
			printf("Case #%d:-1\n",i);
		}else printf("Case #%d:%lld\n",i,max_save);
	}
	return 0;
}
