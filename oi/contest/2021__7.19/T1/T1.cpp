#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

ll read(){
	ll x = 0,f = 1;char ch = getchar();
	while (ch < '0' || ch > '9'){if (ch == '-') f = -1; ch = getchar();}
	while (ch >= '0' && ch <= '9'){x = x*10 + ch - 48; ch = getchar();}
	return x * f;
}

const int N = 205;

int n, p;
ll f[N][N], ans;
double dp[N][N]; 

ll qp(ll x, ll idx){
	ll res = 1, jud = x;
	while(idx){
		if(idx & 1) res = res * jud % p;
		jud = jud * jud % p;
		idx >>= 1;
	}
	return res;
}

int main(){
	n = read(), p = read();
	f[1][1] = 1;
	dp[1][1] = 1;
	for(int i = 2; i <= n+1; i++){
		ll jud = qp(i-1, p-2);
		for(int j = 2; j <= n+1; j++){
			f[i][j] = f[i-1][j-1] * jud % p + f[i-1][j] * jud % p * (i-2) % p;
		}
	}
	for(int i = 1; i <= n; i++){
		ans = (ans + f[n][i] * (i-1) % p);
	}
	printf("%lld", ans);
	return 0;
}

