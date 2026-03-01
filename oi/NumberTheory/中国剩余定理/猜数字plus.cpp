#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long 
#define ld long double
#define ull unsigned long long
using namespace std;

const int Maxn = 15;

int n;
ll a[Maxn], b[Maxn];
ll ans;

ll qmul(ll x, ll y, ll mod){
	ll res = 0;
	while(y){
		if(y & 1) res = (res + x) % mod;
		x = (x + x) % mod;
		y >>= 1;
	}
	return res;
}

ll exgcd(ll aa, ll bb, ll &x, ll &y){
	if(bb == 0){
		x = 1;
		y = 0;
		return aa;
	}
	ll d = exgcd(bb, aa%bb, x, y);
	ll jud = x;
	x = y, y = jud - y * (aa/bb);
	return d;
}

inline ll ksc(ll x,ll y,ll p){
	ll z=(ld)x/p*y;
	ll res=(ull)x*y-(ull)z*p;
	return (res+p)%p;
}

ll crt(){
	ll M = 1;
	ll x = 0;
	for(int i = 1; i <= n; i++){
		M = M * b[i];
	}
	for(int i = 1; i <= n; i++){
		ll w = M / b[i];
		ll ansa = 0, ansb = 0;
		ll d = exgcd(w, b[i], ansa, ansb);
		ansa = (ansa % M + M) % M;
		x = (x + ksc(ksc(w, ansa, M), a[i], M)) % M;
	}
	return (x + M) % M;
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%lld", &a[i]);
	}
	for(int i = 1; i <= n; i++){
		scanf("%lld", &b[i]);
	}
	ans = crt();
	printf("%lld", ans);
	return 0;
} 
