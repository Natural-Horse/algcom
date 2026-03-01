#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
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
ll val[N];

int lowbit(int x){return x & -x;}

void op_update(int u, ll v){
	for(int i = u; i <= mx; i += lowbit(i)){
		val[i] = max(val[i], v);
//		printf("chg %d %d %d\n", i, val[i], v);
	}		
}

ll query_mx(int u){
	ll res = 0;
	for(int i = u; i; i -= lowbit(i)){
		res=max(res, val[i]);
//		printf("ask %d %d\n", i, val[i]);
	}
	return res;
}

int main(){
	freopen("sample.in", "r", stdin);
	freopen("output.out", "w", stdout);
	n = read(), type = read();
	for(int i = 1; i <= n; i++) a[i] = read(), mx = max(mx, a[i]);
	for(int i = 1; i <= n; i++){
		f[i] = query_mx(a[i]-1)+1, maxn = max(maxn, f[i]);
		op_update(a[i], f[i]);
	}
	printf("%lld", maxn);
	return 0;
}

