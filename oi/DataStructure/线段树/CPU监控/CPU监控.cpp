#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll read(){
	ll x = 0,f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') {if (ch == '-') f = -1; ch = getchar();}
	while (ch >= '0' && ch <= '9') {x = x*10 + ch - 48; ch = getchar();}
	return x * f;
}

const int Maxn = 1e5 + 5;
const int inf = (1 << 31) - 1;

struct Tree{
	int l, r;
	ll maxh, maxn;
	ll add, dev;
	ll add_, dev_;
	bool check;
}tr[Maxn * 4];

int n, m;
ll a[Maxn];
ll ans;

void build(int u, int l, int r){
	tr[u].l = l, tr[u].r = r;
	tr[u].dev = tr[u].dev_ = -inf;
	tr[u].check = false;
	if(l != r){
		int na = u << 1, nb = na | 1, mid = (l + r) >> 1;
		build(na, l, mid);
		build(nb, mid + 1, r);
		tr[u].maxn = tr[u].maxh = max(tr[na].maxn, tr[nb].maxn);
	}
	else{
		tr[u].maxh = tr[u].maxn = a[l];
		return;
	}
}

void update(int u){
	int fa = u >> 1;	
	if(!tr[u].check){
		tr[u].add_ = max(tr[u].add_, tr[u].add_ + tr[fa].add_);
		tr[u].maxh = max(tr[u].maxh, tr[u].maxn + tr[fa].add_);	
		if(tr[fa].dev_ != -inf){
			tr[u].dev_ = tr[fa].dev_;
			tr[u].maxh = max(tr[u].maxh, tr[fa].dev_);
			tr[u].check = true;
		}
	}
	else{
		tr[u].maxh = max(tr[u].maxh, tr[u].maxn + tr[fa].add_);
		if(tr[fa].dev_ != -inf){
			tr[u].maxh = max(tr[u].maxh, tr[fa].dev_);
			tr[u].dev_ = max(tr[u].dev_, tr[fa].dev_);
		}
		else{
			if(tr[u].dev_ == -inf) tr[u].dev_ = tr[u].maxn + tr[fa].add_;
			else tr[u].dev_ = max(tr[u].dev_, tr[u].dev_ + tr[fa].add_);
		}
	}
	if(tr[fa].dev != -inf){	
		tr[u].maxn = tr[fa].dev;
		tr[u].add = 0; 
		tr[u].dev = tr[fa].dev;
	}
	tr[u].maxn += tr[fa].add;
	tr[u].add += tr[fa].add;	
}

void push_down(int u){
	update(u << 1);
	update((u << 1) | 1);
	tr[u].add = tr[u].add_ = 0;
	tr[u].dev = tr[u].dev_ = -inf;
}

void push_back(int u){
	int na = u << 1, nb = na | 1;
	tr[u].maxn = max(tr[na].maxn, tr[nb].maxn);
	tr[u].maxh = max(tr[u].maxh, max(tr[na].maxh, tr[nb].maxh));
}

void dev(int u, int st, int re, ll val){
	int l = tr[u].l, r = tr[u].r;
	if(l > re || r < st) return;
	if(l >= st && r <= re){
		tr[u].add = 0;
		tr[u].dev = val;
		tr[u].maxn = val;
		tr[u].dev_ = max(tr[u].dev_, val);		
		tr[u].maxh = max(tr[u].maxh, tr[u].maxn);
		tr[u].check = true;
		return;
	}
	if(l != r) push_down(u);
	dev((u << 1), st, re, val);
	dev(((u << 1) | 1), st, re, val);
	if(l != r) push_back(u);
}

void add(int u, int st, int re, ll val){
	int l = tr[u].l, r = tr[u].r;	
	if(l > re || r < st) return;	
	if(l >= st && r <= re){
		tr[u].add += val;
		tr[u].maxn += val;
		if(tr[u].check){
			tr[u].dev_ = max(tr[u].dev_, tr[u].maxn);		
		}
		else{
			tr[u].add_ = max(tr[u].add_, tr[u].add);			
		}
		tr[u].maxh = max(tr[u].maxh, tr[u].maxn);
		return;
	}
	if(l != r) push_down(u);
	add((u << 1), st, re, val);
	add(((u << 1) | 1), st, re, val);
	if(l != r) push_back(u);
}

ll query_maxn(int u, int st, int re){
	int l = tr[u].l, r = tr[u].r;
	if(l > re || r < st) return -inf;
	if(l >= st && r <= re){
		return tr[u].maxn;
	}
	if(l != r) push_down(u);
	ll juda = query_maxn((u << 1), st, re);
	ll judb = query_maxn(((u << 1) | 1), st, re);
	return max(juda, judb);
}

ll query_maxh(int u, int st, int re){
	int l = tr[u].l, r = tr[u].r;
	if(l > re || r < st) return -inf;
	if(l >= st && r <= re){
		return tr[u].maxh;
	}
	if(l != r) push_down(u);
	ll juda = query_maxh((u << 1), st, re);
	ll judb = query_maxh(((u << 1) | 1), st, re);
	return max(juda, judb);
}

int main(){
//	freopen("sample.in", "r", stdin);
//	freopen("out.out", "w", stdout);
	n = read();
	for(int i = 1; i <= n; i++) a[i] = read();
	build(1, 1, n);
	m = read();
	for(int i = 1; i <= m; i++){
		char op;
		op = getchar();
		int st, re;
		ll val;
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
/*16
1 -4 2 -7 -5 2 9 -7 7 8 -5 4 8 -5 6 -5 
8
C 1 11 9
C 11 14 51
A 12 13
P 1 2 13
P 14 15 1
C 1 3 1
A 6 9
P 1 4 97
*/

/*16
4 -5 1 -9 12 -5 7 -8 8 1 -3 10 -10 8 12 12 
11
C 3 9 87
C 9 15 81
A 1 9
C 3 9 16
P 1 7 86
Q 7 9
A 3 5
C 1 1 40
A 1 12
P 10 16 33
P 4 13 6
*/

/*
16
1 -4 2 -7 -5 2 9 -7 7 8 -5 4 8 -5 6 -5 
8
C 1 11 9
C 11 14 51
A 12 13
P 1 2 13
P 14 15 1
C 1 3 1
A 6 9
P 1 4 97
*/
