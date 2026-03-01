#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
#define mod 123456789
using namespace std;

int read(){
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9'){if(ch == '-') f = -1; ch = getchar();}
	while (ch >= '0' && ch <= '9'){x = x*10 + ch - 48; ch = getchar();}
	return x * f;
}

const int N = 1e6 + 5;

int n, type;
ll f[N], g[N], a[N], maxn, ans, mx;
ll val[N], cnt[N];

int lowbit(int x){return x & -x;}
void op_update(int u, ll v){for(int i=u;i<=mx;i+=lowbit(i))val[i]=max(val[i],v);}
//void op_update_(int u, ll v){for(int i=u;i<=N;i+=lowbit(i))cnt[i]+=v;}
ll query_mx(int u){ll res=0;for(int i=u;i;i-=lowbit(i))res=max(res,val[i]);return res;}
//ll query_cnt(int u){ll res=0;for(int)}

int main(){
//	freopen("sample.in", "r", stdin);
//	freopen("answer.out", "w", stdout);
	n = read(), type = read();
	for(int i = 1; i <= n; i++) a[i] = read(), mx = max(mx, a[i]);
//	if(n <= 1000){
//		for(int i = 1; i <= n; i++){
//			f[i] = 1, g[i] = 1;
//			for(int j = 1; j < i; j++){
//				if(a[j] < a[i]){
//					if(f[j]+1 > f[i]) f[i] = f[j]+1, g[i] = g[j];
//					else if(f[j]+1 == f[i]) g[i] = (g[i] + g[j]) % mod;
//					maxn = max(maxn, f[i]);
//				}
//			}
//		}
//		for(int i = 1; i <= n; i++){
//			if(f[i] == maxn) ans = (ans + g[i]) % mod;
//		}
//		printf("%lld", maxn);
//		if(type == 1) printf("\n%lld", ans % mod);
//	}
//	else if(!type){
		for(int i = 1; i <= n; i++){
			int fab = query_mx(a[i]-1);
			f[i] = fab + 1, maxn = max(maxn, f[i]);
			g[i] = 1;
			g[i] = max(g[i], cnt[fab]);
			op_update(a[i], f[i]);
			cnt[f[i]] = (cnt[f[i]] + g[i]) % mod;
		}
		for(int i = 1; i <= n; i++){
			if(f[i] == maxn) ans = (ans + g[i]) % mod;
		}
		printf("%lld", maxn);
		if(type == 1) printf("\n%lld", ans % mod);
//	}
	return 0;
}

