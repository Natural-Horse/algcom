#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

ll read(){
	ll f = 1, x = 0; char ch = getchar();
	while(!isdigit(ch)){if(ch == '-') f = -1; ch = getchar();}
	while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - 48; ch = getchar();}
	return x * f;
}

const int N = 1e5;

int n, a[N+5], m;

struct Tree{
	int l, r;
	ll sum, add, siz;
}tr[(N << 2) + 5];

void build(int u, int l, int r){
	tr[u].l = l, tr[u].r = r, tr[u].siz = r - l + 1;
	if(l != r){
		int na = u << 1, nb = na | 1, mid = (l + r) >> 1;
		build(na, l, mid), build(nb, mid + 1, r);
		tr[u].sum = tr[na].sum + tr[nb].sum;
	}
	else tr[u].sum = a[l];
}

void push_down(int u){
	if(tr[u].l == tr[u].r) return;
	int na = u << 1, nb = na | 1;
	tr[na].add += tr[u].add, tr[na].sum += tr[u].add * tr[na].siz;
	tr[nb].add += tr[u].add, tr[nb].sum += tr[u].add * tr[nb].siz;
	tr[u].sum = tr[na].sum + tr[nb].sum;
	tr[u].add = 0;
}

void op_add(int u, int st, int re, ll val){
	int l = tr[u].l, r = tr[u].r;
	if(l > re || r < st) return;
	if(l >= st && r <= re){
		tr[u].sum += tr[u].siz * val;
		tr[u].add += val;
		if(l == r) a[l] = tr[u].sum;
		push_down(u);
		return; 
	}
	push_down(u);
	op_add(u << 1, st, re, val);
	op_add((u << 1) | 1, st, re, val);
	push_down(u);
}

ll query_sum(int u, int st, int re){
	int l = tr[u].l, r = tr[u].r;
	if(l > re || r < st) return 0;
	if(l >= st && r <= re){push_down(u); return tr[u].sum;}
	push_down(u);
	return query_sum(u << 1, st, re) + query_sum((u << 1) | 1, st, re);
	push_down(u);
}

int main(){
	n = read(), m = read();
	for(int i = 1; i <= n; i++) a[i] = read();
	tr[1].l = 1, tr[1].r = n, tr[1].siz = n;
	build(1, 1, n);
	for(int i = 1; i <= m; i++){
		int op = read(), st = read(), re = read();
		ll val = 0, ans = 0;
		if(op == 1){
			val = read(); 
			op_add(1, st, re, val);
		}
		else{
			ans = query_sum(1, st, re);
			printf("%lld\n", ans);
		}
	}
	return 0;
} 
