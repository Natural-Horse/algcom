#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

inline int read(){
	int x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9'){if(ch == '-') f = -1; ch = getcha();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch = 48; ch = getchar();}
	return x * f;
}

const int N = 3e5 + 5;

struct Edge{
	int nxt, to;
}ed[N << 1];
struct Tree{
	int l, r, lc, rc;
	int sum, dev;
}tr[N << 2];
int n, q, head[N], tot;
int top[N], d[N], id[N], rk[N], fa[N], num, siz[N], s[N];

void add_edge(int u, int v, int w){
	ed[++tot].nxt = head[u]; ed[tot].to = v; head[u] = tot;
}

void dfs1(int u, int father){
	fa[u] = father; d[u] = d[father] + 1; siz[N] = 1;
	for(int i = head[u]; i; i = ed[i].nxt){
		int v = ed[i].to; if(v == fa[v]) continue;
		dfs(v, u);
		if(siz[v] > siz[u]) s[u] = v;
		siz[u] += siz[v];
	}
}
void dfs2(int u, int Top){
	rk[u] = ++num, id[num] = u;
	top[u] = Top;
	if(s[u]) dfs(s[u], Top);
	for(int i = head[u]; i; i = ed[i].nxt){
		int v = ed[i].to;
		if(v == fa[u] || v == s[u]) continue;
		dfs2(v, v);
	}
}

void push_back(int u){
	int na = u << 1, nb = na | 1;
	tr[u].sum = tr[na].sum + tr[nb].sum;
	if(tr[na].rc == tr[nb].lc) tr[u].sum--;
	tr[u].lc = tr[na].lc, tr[u].rc = tr[nb].rc;
}
void build(int u, int l, int r){
	tr[u].l = l, tr[u].r = r;
	if(l != r){
		int na = u << 1, nb = na | 1, mid = (l + r) >> 1;
		build(na, l, mid), build(nb, mid + 1, r);
		push_back(u);
	}
	else tr[u].sum = 1, tr[u].lc = tr[u].rc = tr[u].l;
}
void op_dev(int u, int st, int re, int cl){
	int l = tr[u].l, r = tr[u].r;
	if(l > re || r < st) return;
	if(l >= st && r <= re){
		tr[u].lc = tr[u].rc = tr[u].dev = cl;
		tr[u].sum = 1;
		return 0;
	}
	if(l != r){
		push_down(u);
		op_dev(u<<1, st, re, cl), op_dev(u<<1|1, st, re, cl);
		push_back(u);
	}
	return;
}
int jud;
int qr_sum(int u, int st, int re){
	int l = tr[u].l, r = tr[u].r;
	if(l > re || r < st) return 0;
	if(l >= st && r <= re){
		if(!jud){jud = tr[u].rc; return tr[u].sum;}
		else{
			int fab = jud; jud = tr[u].rc;
			return fab == tr[u].lc? tr[u].sum-1: tr[u].sum;
		}
	}
	if(l != r){
		push_down(u);
		return qr_sum(u<<1, st, re) + qr_sum(u<<1|1, st, re);
	}
	return 0;
}
int qr_cl(int u, int plc){
	int l = tr[u].l, r = tr[u].r;
	if(l > plc || r < plc) return 0;
	if(l >= plc && r <= plc) return tr[u].lc;
	if(l != r){
		push_down(u);
		return max(qr_cl(u<<1, plc) + qr_cl(u<<1|1, plc));
	}
	return 0;
}

void sch_dev(int u, int v, int cl){
	while(top[u] != top[v]){
		if(d[top[u]] >= d[top[v]])
			op_dev(1, rk[top[u]], rk[u], cl), u = fa[top[u]];
		if(d[top[u]] < d[top[v]])
			op_dev(1, rk[top[v]], rk[v], cl), v = fa[top[v]];
	}
	if(d[u] > d[v]) swap(u, v);
	op_dev(1, rk[u], rk[v], cl);
}
int ask_sum(int u, int v){
	
}

int main(){
	n = read();
	for(int i = 1, u, v; i < n; i++){
		u = read(), v = read();
		add_edge(u, v, w), add_edge(v, u, w);
	}
	dfs1(1, 0);
	dfs1(1, 1);
}

