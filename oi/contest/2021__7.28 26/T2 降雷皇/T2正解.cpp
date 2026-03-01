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
ll a[N], maxn, ans, mx;
pair<ll,ll> f[N], val[N];

int lowbit(int x){return x & -x;}

void op_update(int u, pair<ll,ll> v){
	for(int i = u; i <= mx; i += lowbit(i))
		if(v.first > val[i].first) val[i] = v;
		else if(val[i].first == v.first)val[i].second = (val[i].second + v.second) % mod;
}

pair<ll,ll> query_mx(int u){
	pair<int,ll> res = make_pair(0, 1);
	for(int i = u; i; i -= lowbit(i))
		if(val[i].first > res.first) res = val[i];
		else if(val[i].first == res.first) res.second = (res.second + val[i].second) % mod;
	return res;
}

int main(){
	n = read(), type = read();
	for(int i = 1; i <= n; i++) a[i] = read(), mx = max(mx, a[i]);
	for(int i = 1; i <= n; i++){
		pair<ll,ll> fab = query_mx(a[i]-1);
		f[i] = make_pair(fab.first+1, fab.second);
		maxn = max(maxn, f[i].first);
		op_update(a[i], f[i]);
	}
	for(int i = 1; i <= n; i++){
		if(f[i].first == maxn) ans = (ans + f[i].second) % mod;
	}
	printf("%lld", maxn);
	if(type == 1) printf("\n%lld", ans % mod);

	return 0;
}

