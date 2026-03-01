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

struct Edge{
	int nxt, to;
}ed[N << 1];
struct Tree{
	int l, r;
	ll mx, mn;
}tr[N << 2];
ll n, q, t;
ll a[N], head[N], tot, p[N], ans; 
ll top[N], son[N], siz[N], rk[N], id[N], fa[N], dep[N], num;

void add_edge(int u, int v){ed[++tot].nxt=head[u];ed[tot].to=v;head[u]=tot;}
void dfs1(int u, int father){
	siz[u] = 1;
	dep[u] = dep[father] + 1;
	fa[u] = father;
	for(int i = head[u]; i; i = ed[i].nxt){
		int v = ed[i].to;
		if(v == father) continue;
		dfs1(v, u);
		if(siz[v] > siz[son[u]]) son[u] = v;
		siz[u] += siz[v];
	}
}
void dfs2(int u, int Top){
	top[u] = Top;
	rk[u] = ++num;
	id[num] = u;
	if(!son[u]) return;
	dfs2(son[u], Top);
	for(int i = head[u]; i; i = ed[i].nxt){
		int v = ed[i].to;
		if(v == fa[u] || v == son[u]) continue;
		dfs2(v, v);
	}
}
void build(int u, int l, int r){
	tr[u].l = l, tr[u].r = r;
	if(l != r){
		int na = u << 1, nb = na | 1, mid = (l + r) >> 1;
		build(na, l, mid), build(nb, mid + 1, r);
		tr[u].mx = max(tr[na].mx, tr[nb].mx);
		tr[u].mn = min(tr[na].mn, tr[nb].mn);
		return;
	}
	else tr[u].mn = tr[u].mx = a[id[tr[u].l]];
}
ll query_abs(int u, int st, int re, ll val){
	int l = tr[u].l, r = tr[u].r;
	if(l > re || r < st) return inf;
	if(l >= st && r <= re){
		if(tr[u].mx <= val) return val-tr[u].mx;
		else if(tr[u].mn >= val) return tr[u].mn-val;
		else{
			ll juda = query_abs(u<<1, st, re, val);
			ll judb = query_abs(u<<1|1, st, re, val);
			return min(juda, judb);
		} 
	}
	if(l != r){
		ll juda = query_abs(u<<1, st, re, val);
		ll judb = query_abs(u<<1|1, st, re, val);
		return min(juda, judb);
	} else return inf;
}
int plc;
ll ask_abs(int u, int v, ll val){
	ll res = inf;
	while(top[u] != top[v]){
		if(dep[top[u]] >= dep[top[v]]){
			res = min(res, query_abs(1, rk[top[u]], rk[u], val));
			
			u = fa[top[u]];
		}
		if(dep[top[u]] < dep[top[v]]){
			res = min(res, query_abs(1, rk[top[v]], rk[v], val));
			v = fa[top[v]];
		}
	}
	if(dep[u] > dep[v]) swap(u, v);
	res = min(res, query_abs(1, rk[u], rk[v], val));
	plc = u;
	return res;
}

int main(){
	n = read(), q = read(), t = read();
	for(int i = 1; i <= n; i++) a[i] = read();
	for(int i = 1, u, v; i < n; i++){
		u = read(), v = read();
		add_edge(u, v), add_edge(v, u);
	}
	dfs1(1, 0);
	dfs2(1, 1);
	build(1, 1, num);
	ll lastans = 0; 
	for(int i = 1, r, k; i <= q; i++){
		lastans = ans;
		ans = inf;
		r = read(), k = read();
		for(int j = 1, x; j <= k; j++){
			x = read(); 
			p[j] = (x-1+lastans*t) % n + 1;
		}
		plc = p[1];
		ans = min(ans, ask_abs(plc, plc, r));
		for(int j = 2; j <= k; j++){
			ans = min(ans, ask_abs(p[j], plc, r));
		}
		printf("%lld\n", ans);
	}
	return 0;
}

