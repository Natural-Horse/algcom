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

const int N = 3e5 + 5;

struct Tree{
	int l,r;
	ll maxn;
}tr[N*4];

int n, k;
ll a[N], pre[N];
ll cnt;

void build(int u, int l, int r){
	tr[u].l = l, tr[u].r = r;
	if(l != r){
		int na = u << 1, nb = na | 1, mid = (l + r) >> 1;
		build(na, l, mid), build(nb, mid + 1, r);
		tr[u].maxn = max(tr[na].maxn, tr[nb].maxn);
	}
	else tr[u].maxn = a[l];
}
ll query_maxn(int u, int st, int re){
	int l = tr[u].l, r = tr[u].r;
	if(l > re || r < st) return 0;
	if(l >= st && r <= re) return tr[u].maxn;
	if(l != r) return max(query_maxn(u<<1,st,re), query_maxn(u<<1|1,st,re));
	else return 0;
}

ll bi_ser(ll x, int plc){
	int l = plc-1, r = n+1;
	while(l < r){
		int mid = (l + r) >> 1;
		if(pre[mid]-pre[plc-1]-query_maxn(1,plc,mid) < x) l = mid + 1;
		else r = mid;
	}
	return pre[l] - pre[plc-1] - query_maxn(1, plc, l);
}

int main(){
	n = read(), k = read();
	for(int i = 1; i <= n; i++) a[i] = read(), pre[i] = pre[i-1] + a[i];
	build(1, 1, n);
	for(int i = 1; i < n; i++){
		for(int j = k; j <= pre[n] - pre[i-1]; j += k){
			if(bi_ser(j, i) == j) cnt++;
		}
	}
	printf("%lld", cnt);
}
