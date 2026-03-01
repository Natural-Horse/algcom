#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

ll a, b;
ll x;
ll ansa, ansb;

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
	ll d = exgcd(a, b, ansa, ansb);
	ansa = ansa / d;
	if(ansa < 0){
		ansa = -ansa;
		ansa = (b/d) - ansa % (b/d); 
	}
	else ansa = ansa % (b/d);
	printf("%lld", ansa);
	return 0;
} 
