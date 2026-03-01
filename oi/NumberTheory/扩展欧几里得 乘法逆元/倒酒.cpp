#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long 
using namespace std;

ll a, b;

ll exgcd(ll aa, ll bb, ll &x, ll &y){
	if(bb == 0){
		x = 1, y = 0;
		return aa;
	}
	ll d = exgcd(bb, aa%bb, x, y);
	ll jud = x;
	x = y, y = jud - y * (aa/bb);
	return d;
}

int main(){
	scanf("%lld %lld", &a, &b);
	ll ansa = 0, ansb = 0;
	ll d = exgcd(a, b, ansa, ansb);
//	printf("%lld %lld\n", ansa, ansb);
	ansa *= -1,a *= -1;
	while(ansa < 0 || ansb < 0){
		ansa += b/d * (ansa < 0);
		ansb -= a/d* (ansa >= 0);
	}
	printf("%lld\n%lld %lld", d, ansa, ansb);
}
