#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

const int Maxn = 1e5 + 5;

int read(){
	int x = 0,f = 1;char ch = getchar();
	while (ch < '0' || ch > '9') {if (ch == '-') f = -1; ch = getchar();}
	while (ch >= '0' && ch <= '9') {x = x*10 + ch - 48; ch = getchar();}
	return x * f;
}

struct Tree{
	int l, r, siz;
	ll maxn, maxh;
	ll add, addh;
}tr[Maxn * 4];

int n, m;
int a[Maxn];

ll max_(ll x1, ll x2){
	return x1 >= x2? x1: x2;
}

void push_up(int u){
	int na = u << 1, nb = na | 1;
	tr[u].maxn = max(tr[u].maxn, max(tr[na].maxn, tr[nb].maxn));
	tr[u].maxh = max(tr[u].maxh, max(tr[na].maxh, tr[nb].maxh));
}

void build(int u, int l, int r){
	tr[u].l = l, tr[u].r = r, tr[u].siz = r - l + 1;
	if(l != r){
		int na = u << 1, nb = na | 1, mid = (l + r) >> 1;
		build(na, l, mid);
		build(nb, mid + 1, r);
		tr[u].maxn = max(tr[na].maxn, tr[nb].maxn);
		push_up(u);
	}
	else{
		tr[u].maxn = a[l];
		tr[u].maxh = a[l];
		return;
	}
}
// 最大值加的数，历史最值加的数
void update(int u, int x1, int x2){
	tr[u].maxh = max(tr[u].maxh, tr[u].maxn + x2);
	tr[u].addh = max(tr[u].addh, tr[u].add + x2); 
	tr[u].maxn += x1;
	tr[u].add += x1;
}

void push_down(int u){
	int na = u << 1, nb = na | 1;
	ll maxn = max(tr[na].maxn, tr[nb].maxn);
	update(na, tr[u].add, tr[u].addh);
	tr[u].add = tr[u].addh = 0;
}

void dev(int u, int st, int re, ll val){
	int l = tr[u].l, r = tr[u].r;
	int na = (u << 1), nb = na | 1;
	if(l > re || r < st) return;
	if(l >= st && r <= re){
		tr[u].add = 0;
		tr[u].maxn = val;
		tr[u].maxh = max(tr[u].maxn, tr[u].maxh + tr[u].addh);
		tr[u].addh = 0;
		return;
	}
	push_down(u);
	if(l <= re) dev(na, st, re, val);
	if(r >= st) dev(nb, st, re, val);
	push_up(u);
}

void add(int u, int st, int re, ll val){
	int l = tr[u].l, r = tr[u].r;
	if(l > re || r < st) return;
	if(l >= st && r <= re){
		update(u, val, val);
		return;
	}
	push_down(u);
	if(l <= re) add((u << 1), st, re, val);
	if(r >= st) add(((u << 1) | 1), st, re, val);
	push_up(u);
}

ll query_maxn(int u, int st, int re){
	int l = tr[u].l, r = tr[u].r;
	if(l > re || r < st) return -inf;
	if(l >= st && r <= re){
		return tr[u].maxn;
	}
	push_down(u);
	ll juda = -inf, judb = -inf;
	if(l <= re) juda = query_maxn((u << 1), st, re);
	if(r >= st) judb = query_maxn(((u << 1) | 1), st, re);
	return max_(juda, judb);
}

ll query_maxh(int u, int st, int re){
	int l = tr[u].l, r = tr[u].r;
	if(l > re || r < st) return -inf;
	if(l >= st && r <= re){
		return tr[u].maxh;
	}
	push_down(u);
	ll juda = -inf, judb = -inf;
	if(l <= re) juda = query_maxh((u << 1), st, re);
	if(r >= st) judb = query_maxh(((u << 1) | 1), st, re);
	return max_(juda, judb);
}

int main(){
	n = read();
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	m = read();
	build(1, 1, n);
	for(int i = 1; i <= m; i++){
		char op;
		scanf("%c", &op);
		int st, re;
		ll val, ans;
		st = read(), re = read();
		if(op == 'Q'){
			ans = query_maxn(1, st, re);
			printf("%lld\n", ans);
		}
		if(op == 'A'){
			ans = query_maxh(1, st, re);
			printf("%lld\n", ans);
		}
		if(op == 'P'){
			val = read();
			add(1, st, re, val);
		}
		if(op == 'C'){
			val = read();
			dev(1, st, re, val);
		}
	}
	return 0;
}
