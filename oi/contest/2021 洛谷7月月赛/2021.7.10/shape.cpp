#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

int read(){
	int x = 0,f = 1;char ch = getchar();
	while (ch < '0' || ch > '9'){if (ch == '-') f = -1; ch = getchar();}
	while (ch >= '0' && ch <= '9'){x = x*10 + ch - 48; ch = getchar();}
	return x * f;
}

const int N = 2e3 + 5;
const int mod = 1e9 + 7;

int n, m;
int a[N][N];
int l[N][N], r[N][N], h[N][N], d[N][N], c[N][N];
ll val[N], val_[N];

int lowbit(int x){return x & -x;}

void add(int v, int rt){
	while(rt <= n){
		val[rt] = (val[rt] + v) % mod;
		rt += lowbit(rt);
	}
}

void add_(int v, int rt){
	while(rt <= n){
		val_[rt] = (val_[rt] + v) % mod;
		rt += lowbit(rt);
	}
}

ll query_pre(int plc){
	ll ans = 0;
	while(plc > 0){ans = (ans + val[plc]) % mod, plc -= lowbit(plc);}
	return ans;
}

ll query_sum(int st, int re){
	return query_pre(re) % mod;
}

ll query_pre_(int plc){
	ll ans = 0;
	while(plc > 0){ans = (ans + val_[plc]) % mod, plc -= lowbit(plc);}
	return ans;
}

ll query_sum_(int st, int re){
	return query_pre_(re) % mod;
}

int main(){
	n = read(), m = read();
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			a[i][j] = 1 - read();
			l[i][j] = r[i][j] = i;
			if(a[i-1][j] && a[i][j]) h[i][j] = h[i-1][j] + 1;
		}
	}
	for(int i = n; i >= 1; --i){
		for(int j = m; j >= 1; --j){
			if(a[i][j] && a[i+1][j]) d[i][j] = d[i+1][j] + 1;
			c[i][j] = min(h[i][j], d[i][j]);
		}
	}
	ll ans = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			int maxn = 0;
			if(a[i][j] && c[i][j]){
				maxn = max(maxn, c[i][j]);
				ans = (ans + query_sum_(1, c[i][j]) + query_sum(c[i][j]+1, maxn) * c[i][j]) % mod;								
				add(1, c[i][j]), add_(c[i][j], c[i][j]);
			}
			else if(!a[i][j]){
				maxn = 0;
				memset(val, 0, sizeof(val)), memset(val_, 0, sizeof(val_));
			}
		}
	}
	printf("%lld", ans % mod);
}

