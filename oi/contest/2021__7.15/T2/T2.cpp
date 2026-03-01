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

const int N = 1e5 + 5;

struct Tree{
	int l, r, siz;
	ll maxn, add;
}tr[N << 2];

int n;
int w[N], p[N], c[N], r[N];

void build(int u, int l, int r){
	tr[u].l = l, tr[u].r = r, tr[u].siz = r - l + 1;
	if(l != r){
		int na = u << 1, nb = na | 1, mid = (l + r) >> 1;
		build(na, l, mid), build(nb, mid + 1, r);
	}
}

void push_down(int u){
	int na = u << 1, nb = na | 1;
	tr[na].maxn += tr[u].add, tr[nb].maxn += tr[u].add;
	tr[na].add += tr[u].add, tr[nb].add += tr[u].add;
	tr[u].add = 0;
}

void push_back(int u){
	int na = u << 1, nb = na | 1;
	tr[u].maxn = max(tr[na].maxn, tr[nb].maxn);
}

void op_add(int u, int st, int re, ll val){
	int l = tr[u].l, r = tr[u].r;
	if(l > re || r < st) return;
	if(l >= st && r <= re){
		tr[u].add += val;
		tr[u].maxn += val;
		return;
	}
	if(l != r){
		push_down(u);
		op_add(u << 1, st, re, val), op_add(u << 1 | 1, st, re, val);
		push_back(u);
	}
}

ll query_val(int u, int st, int re){
	int l = tr[u].l, r = tr[u].r;
	if(l > re || r < st) return 0;
	if(l >= st && r <= re) return tr[u].maxn;
	if(l != r){
		push_down(u);
		return query_val(u<<1, st, re) + query_val(u<<1|1, st, re);
	}
	return 0;
}

ll op_update(int u, int plc, int val){
	
}

int main(){
	n = read();
	build(1, 1, n);
	for(int i = 1; i <= n; i++) p[i] = read(), r[p[i]] = i;
	for(int i = 1; i <= n; i++) w[i] = read();
	int con = 0;
	for(int i = 1; i <= n; i++){
		if(p[i] < i){
			op_add(1, i-1, i-1, w[i]);
		}
		if(p[i] > i){
			if(p[i] > con) op_add(1, con+1, p[i], w[i]);
		}
		con = max(con, p[i]);
	}
	ll ans = query_val(1, n, n);
	printf("%lld", ans);
	return 0;
}

