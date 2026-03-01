#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
#define mod 998244353
using namespace std;

ll read(){
	ll x = 0,f = 1;char ch = getchar();
	while (ch < '0' || ch > '9'){if (ch == '-') f = -1; ch = getchar();}
	while (ch >= '0' && ch <= '9'){x = x*10 + ch - 48; ch = getchar();}
	return x * f % mod;
}

const int N = 3e5 + 5;
ll n, m, a, b;
ll up[N], down[N], pre[N<<1], inv[N<<1], ans;

ll qp(ll x, ll idx){
	ll res = 1, jud = x;
	while(idx){
		if(idx & 1) res = (res * jud) % mod;
		jud = (jud * jud) % mod;
		idx >>= 1;
	}
	return res % mod;
}
void init(){
	pre[0] = 1;
	inv[0] = 1;
	for(ll i = 1; i <= n+m; i++) pre[i] = (pre[i-1] * i) % mod;	
	inv[n+m] = qp(pre[n+m], mod-2);
	for(ll i = n+m-1; i >= 1; --i) inv[i] = inv[i+1] * (i + 1) % mod;
}
ll c(ll x, ll y){
	if(y == 0 || x <= y) return 1;
	else return (pre[x] * inv[x-y] % mod) * inv[y] % mod;
}

int main(){
//	freopen("a_sample2.in", "r", stdin);
	n = read(), m = read(), a = read(), b = read();
	a %= mod, b %= mod;
	init();
	for(int i = 1; i <= n; i++){
		up[i] = read();
		up[i] %= mod;
		ll add = up[i]/**qp(a,m)%mod*qp(b,n-1)%mod*c(n-i+m-1,m-1)%mod*/;
		add = add * qp(a, m) % mod;
		add = add * qp(b, n-i) % mod;
		add = add * c(n-i+m-1, m-1) % mod;
		ans = (ans + add) % mod;
	}
	for(int i = 1; i <= m; i++){
		down[i] = read();
		down[i] %= mod;
		ll add = down[i]/**qp(b,n)%mod*qp(a,m-i)%mod*c(m-i+n-1,n-1)%mod*/;
		add = add * qp(b, n) % mod;
		add = add * qp(a, m-i) % mod;
		add = add * c(m-i+n-1, n-1) % mod;
		ans = (ans + add) % mod;
	}
	ans = (ans + mod) % mod;
	printf("%lld", ans % mod);
	return 0;
}

