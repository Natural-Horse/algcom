#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

ll read(){
	ll x = 0, f = 1; char ch = getchar();
	while(!isdigit(ch)){if(ch == '-') f = -1; ch = getchar();}
	while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - 48; ch = getchar();}
	return x * f;
}

const int N = 1e5;

struct{
	int l, r;
	ll siz, sum, add, mul;
}tr[N];
ll n, m, p, a[N];

void build(int u, int l, int r){
	tr[u].l = l, tr[u].r = r, tr[u].siz = r - l + 1, tr[u].mul = 1;
	if(l != r){
		int na = u << 1, nb = na | 1, mid = (l + r) >> 1;
		build(na, l, mid), build(nb, mid + 1, r);
		tr[u].sum = tr[na].sum + tr[nb].sum;
	}
	else tr[u].sum = a[l];
}

void push_down(int u){
	int l = tr[u].l, r = tr[u].r;
	if(l == r) return;
	int na = u << 1, nb = na | 1;
	tr[na].sum = tr[na].sum * tr[u].mul % p, tr[na].sum = (tr[na].sum + tr[u].add * tr[na].siz % p) % p;
	tr[nb].sum = tr[nb].sum * tr[u].mul % p, tr[nb].sum = (tr[nb].sum + tr[u].add * tr[nb].siz % p) % p;
	tr[na].mul = tr[na].mul * tr[u].mul % p, tr[na].add = tr[na].add * tr[u].mul % p, tr[na].add = (tr[na].add + tr[u].add) % p;
	tr[nb].mul = tr[nb].mul * tr[u].mul % p, tr[nb].add = tr[nb].add * tr[u].mul % p, tr[nb].add = (tr[nb].add + tr[u].add) % p;
	tr[u].add = 0, tr[u].mul = 1;
	tr[u].sum = (tr[na].sum + tr[nb].sum) % p;
}

void op_add(int u, int st, int re, ll val){
	int l = tr[u].l, r = tr[u].r;
	if(l > re || r < st) return;
	if(l >= st && r <= re){
		tr[u].sum = (tr[u].sum + tr[u].siz * val % p) % p;
		tr[u].add = (tr[u].add + val) % p;
		push_down(u);
		return;
	}
	push_down(u);
	op_add(u << 1, st, re, val);
	op_add((u << 1) | 1, st, re, val);
	push_down(u);
}

void op_mul(int u, int st, int re, ll val){
	int l = tr[u].l, r = tr[u].r;
	if(l > re || r < st) return;
	if(l >= st && r <= re){
		tr[u].sum = tr[u].sum * val % p;
		tr[u].mul = tr[u].mul * val % p, tr[u].add = tr[u].add * val % p;
		push_down(u);
		return;
	}
	push_down(u);
	op_mul(u << 1, st, re, val);
	op_mul((u << 1) | 1, st, re, val);
	push_down(u);
}

ll query_sum(int u, int st, int re){
	int l = tr[u].l, r = tr[u].r;
	if(l > re || r < st) return 0;
	if(l >= st && r <= re){
		push_down(u);
		return tr[u].sum;
	}
	push_down(u);
	return query_sum(u << 1, st, re) + query_sum((u << 1) | 1, st, re) % p;
}

int main(){
	n = read(), m = read(), p = read();
	for(int i = 1; i <= n; i++) a[i] = read();
	build(1, 1, n);
	for(int i = 1; i <= m; i++){
		int op = read(), x = read(), y = read();
		if(op == 3){
			ll ans = query_sum(1, x, y) % p;
			printf("%lld\n", ans);
		}
		else{
			ll k = read() % p;
			if(op == 1) op_mul(1, x, y, k);
			else op_add(1, x, y, k);
		}	
	}
	return 0;
}
