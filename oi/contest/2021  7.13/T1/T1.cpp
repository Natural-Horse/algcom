#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
#define mod 998244353
using namespace std;

int read(){
	int x = 0,f = 1;char ch = getchar();
	while (ch < '0' || ch > '9'){if (ch == '-') f = -1; ch = getchar();}
	while (ch >= '0' && ch <= '9'){x = x*10 + ch - 48; ch = getchar();}
	return x * f;
}

const int N = 1e3 + 5, M = 3e5 + 5;
int n, m, a, b;
ll f[N][N];
ll g[M], st, as[M];
ll up[M], down[M], ans;

ll qp(ll x, ll idx){
	ll res = 1, jud = x;
	while(idx){
		if(idx & 1) res = (res * jud) % mod;
		jud = (jud * jud) % mod;
		idx >>= 1;
	}
	return res;
}

int main(){
//	freopen("a_sample2.in", "r", stdin);
	n = read(), m = read(), a = read(), b = read();
	if(n <= 1000 && m <= 1000){
		for(int i = 1; i <= n; i++) f[i][0] = read();
		for(int i = 1; i <= m; i++) f[0][i] = read();
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++)
				f[i][j] = (a*f[i][j-1] % mod + b*f[i-1][j] % mod) % mod;
		printf("%lld", f[n][m] % mod);
		return 0;
	}
	else if(n == 1){
		as[0] = read();
		for(int i = 1; i <= m; i++){
			g[i] = read();
			as[i] = (g[i]*b%mod + as[i-1]*a%mod) % mod;
			printf("%lld", g[m] % mod);
		}
	}
	else if(a == 1 && b == 1){
		for(int i = 1; i <= n; i++){
			up[i] = read();
			ans = (ans + up[i] * (n-i+1) * m % mod) % mod;
		} 
		for(int i = 1; i <= m; i++){
			down[i] = read();
			ans = (ans + down[i] * (m-i+1) * n % mod) % mod;
		} 
		printf("%lld", ans % mod);
	}
	else{
		for(int i = 1; i <= n; i++) up[i] = read();
		for(int i = 1; i <= m; i++) down[i] = read();
		for(int i = 1; i <= n; i++){
			ans = (ans + up[i] * qp(b, m) * qp(a, n-i) % mod) % mod;
		}
		for(int i = 1; i <= m; i++){
			ans = (ans + down[i] * qp(a, n) * qp(b, m-i) % mod) % mod;
		}
		printf("%lld", ans % mod);
		return 0;
	}
}

