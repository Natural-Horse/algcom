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

const int Maxn = 1e5 + 5;

struct Tree{
	int l, r, siz;
	int cnt, dev;
}tr[Maxn * 4];

int n, m, q;
int a[Maxn];
int op[Maxn], st_[Maxn], re_[Maxn];

void build(int u, int l, int r, int val){
	tr[u].l = l, tr[u].r = r, tr[u].siz = r - l + 1;
	tr[u].dev = -inf;
	if(l != r){		
		int na = u << 1, nb = na | 1, mid = (l + r) >> 1;
		build(na, l, mid, val);
		build(nb, mid + 1, r, val);
		tr[u].cnt = tr[na].cnt + tr[nb].cnt;
	}
	else{
		tr[u].cnt = a[l] >= val;
	}
}

void push_down(int u){
	if(tr[u].l == tr[u].r) return;
	int na = u << 1, nb = na | 1;
	if(tr[u].dev == 0){
		tr[na].dev = tr[nb].dev = 0;
		tr[na].cnt = tr[nb].cnt = 0;
	}
	if(tr[u].dev == 1){
		tr[na].dev = tr[nb].dev = 1;
		tr[na].cnt = tr[na].siz, tr[nb].cnt = tr[nb].siz;
	}
	tr[u].dev = -inf;
}

void push_back(int u){
	int na = u << 1, nb = na | 1;
	tr[u].cnt = tr[na].cnt + tr[nb].cnt;
}

void dev(int u, int st, int re, int val){
	int l = tr[u].l, r = tr[u].r;
	if(l > re || r < st) return;
	if(l >= st && r <= re){
		if(val == 0) tr[u].cnt = 0, tr[u].dev = 0;
		else tr[u].cnt = tr[u].siz, tr[u].dev = 1;
		return;
	}
	if(l != r){
		push_down(u);		
		dev(u << 1, st, re, val);
		dev(u << 1 | 1, st, re, val);
		push_back(u);
	} 	
}

int query_add(int u, int st, int re){
	int l = tr[u].l, r = tr[u].r;
	if(l > re || r < st) return 0;
	if(l >= st && r <= re) return tr[u].cnt;	
	if(l != r){
		push_down(u);
		return query_add((u << 1), st, re) + query_add(((u << 1) | 1), st, re);
	} 
}

int query_find(int u, int st, int re){
	int l = tr[u].l, r = tr[u].r;
	if(l > re || r < st) return 0;
	if(l >= st && r <= re){
		if(tr[u].cnt == 1) return 1;
		else return 0;
	}	
	if(l != r){
		push_down(u);
		int c = query_find(u << 1, st, re);
		int cc = query_find(u << 1 | 1, st, re);
		return c | cc;	
	} 
}

bool check(int x){
	build(1, 1, n, x);
	for(int i = 1; i <= m; i++){
		int range = query_add(1, st_[i], re_[i]);
		if(op[i] == 0){			
			dev(1, st_[i], re_[i] - range, 0);
			dev(1, re_[i] - range + 1, re_[i], 1);
		}
		else{
			dev(1, st_[i], st_[i] + range - 1, 1);
			dev(1, st_[i] + range, re_[i], 0);
		}
	}
	return query_find(1, q, q);
}

int main(){
	n = read(), m = read();
	for(int i = 1; i <= n; i++) a[i] = read();	
	for(int i = 1; i <= m; i++){
		op[i] = read(), st_[i] = read(), re_[i] = read();
	}
	q = read();
	int l = 0, r = n + 1;
	while(l < r){
		int mid = (l + r + 1) >> 1;
		if(check(mid)) l = mid;
		else r = mid - 1;
	}
	printf("%d", l);
	return 0;
}
