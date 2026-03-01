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

const int N = 2e5 + 5, M = 2e5 + 5;

struct Edge{
	int nxt, to;
}ed[M * 2];

struct Tree{
	int l, r, siz;
	int add, sum;
}tr[N * 4];

int n, m, r, p;
int a[N];
int head[N], tot;
int fa[N], top[N], d[N], s[N], size[N];
int id[N], rk[N], num;

void add_edge(int u, int v){
	ed[++tot].nxt = head[u];
	ed[tot].to = v;
	head[u] = tot;
}

void dfs1(int u, int father){
	fa[u] = father;
	d[u] = d[father] + 1;
	size[u] = 1;
	for(int i = head[u]; i; i = ed[i].nxt){
		int v = ed[i].to;
		if(v == father) continue;
		dfs1(v, u);
		size[u] += size[v];
		if(size[v] > size[s[u]]) s[u] = v;
	}
}

void dfs2(int u, int Top){
	top[u] = Top;
	id[u] = ++num;
	rk[num] = u;
	if(!s[u]) return;
	dfs2(s[u], Top);
	for(int i = head[u]; i; i = ed[i].nxt){
		int v = ed[i].to;
		if(v == fa[u] || v == s[u]) continue;
		dfs2(v, v);
	}
}

void build(int u, int l, int r){
	tr[u].l = l, tr[u].r = r, tr[u].siz = r - l + 1;
	if(l != r){
		int na = u << 1, nb = na | 1, mid = (l + r) >> 1;
		build(na, l, mid), build(nb, mid + 1, r);
		tr[u].sum = tr[na].sum + tr[nb].sum;
		return;
	}
	else tr[u].sum = a[rk[l]];
}

void push_down(int u){
	int na = u << 1, nb = na | 1;
	tr[na].sum = ((ll)tr[na].siz * tr[u].add % p + tr[na].sum) % p;
	tr[nb].sum = ((ll)tr[nb].siz * tr[u].add % p + tr[nb].sum) % p;
	tr[na].add = (tr[na].add + tr[u].add) % p;
	tr[nb].add = (tr[nb].add + tr[u].add) % p;
	tr[u].add = 0;
}

void push_back(int u){
	tr[u].sum = (tr[u<<1].sum + tr[u<<1|1].sum) % p;
}

void add(int u, int st, int re, int val){
	int l = tr[u].l, r = tr[u].r;
	if(l > re || r < st) return;
	if(l >= st && r <= re){
		tr[u].sum = (tr[u].sum + (ll)tr[u].siz * val % p) % p;
		tr[u].add = (tr[u].add + val) % p;
		return;
	} 
	if(l != r){
		push_down(u);
		add(u << 1, st, re, val), add(u << 1 | 1, st, re, val);
		push_back(u);
	}
}

int query_sum(int u, int st, int re){
	int l = tr[u].l, r = tr[u].r;
	if(l > re || r < st) return 0;
	if(l >= st && r <= re) return tr[u].sum;
	if(l != r){
		push_down(u);
		return query_sum(u<<1, st, re) + query_sum(u<<1|1, st, re);
	}
	else return 0;
}

void tr_add(int x, int y, int val){
	while(top[x] != top[y]){
		if(d[top[x]] > d[top[y]])
			add(1, id[top[x]], id[x], val), x = fa[top[x]];		
		else
			add(1, id[top[y]], id[y], val), y = fa[top[y]];	
	}
	if(id[x] > id[y]) swap(x, y);
	add(1, id[x], id[y], val);
}

void tr_add_(int rt, int val){
	add(1, id[rt], id[rt] + size[rt] - 1, val);
}

int tr_query_sum(int x, int y){
	int ansa = 0;
	while(top[x] != top[y]){
		if(d[top[x]] > d[top[y]])
			ansa = (ansa + query_sum(1, id[top[x]], id[x])) % p, x = fa[top[x]];		
		else
			ansa = (ansa + query_sum(1, id[top[y]], id[y])) % p, y = fa[top[y]];		
	}
	if(id[x] > id[y]) swap(x, y);
	ansa = (ansa + query_sum(1, id[x], id[y])) % p;
	return ansa;
}

int tr_query_sum_(int rt){
	return query_sum(1, id[rt], id[rt] + size[rt] - 1);
}

int main(){
	n = read(), m = read(), r = read(), p = read();
	for(int i = 1; i <= n; i++) a[i] = read();
	for(int i = 1, u, v; i < n; i++) u = read(), v = read(), add_edge(u, v), add_edge(v, u);
	dfs1(r, 0);
	dfs2(r, r);
	build(1, 1, num);
	for(int i = 1, op; i <= m; i++){
		op = read();
		if(op == 1){
			int u = read(), v = read(), val = read();
			tr_add(u, v, val);
		}
		if(op == 2){
			int u = read(), v = read();
			printf("%d\n", tr_query_sum(u, v) % p);
		}
		if(op == 3){
			int rt = read(), val = read();
			tr_add_(rt, val);
		}
		if(op == 4){
			int rt = read();
			printf("%d\n", tr_query_sum_(rt) % p);
		}
	}
	return 0;
}
