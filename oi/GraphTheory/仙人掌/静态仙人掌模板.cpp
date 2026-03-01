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

const int N = 1e5 + 5, M = 2e4 + 5;

struct Edge{
	int nxt, to;
	ll w;
}ed[M * 2], ed_[M * 2];

int n, m, q;
int head[N], tot, head_[N], tot_;
int dfn[N], low[N], num, sqr;
ll sum[N], res[N];
int fa[N], f[N*2][20], d[N*2];
ll dis[N*2];
int lg[N*2];
int prex, prey;

void add_edge(int u, int v, int w){
	ed[++tot].nxt = head[u];
	ed[tot].to = v, ed[tot].w = w;
	head[u] = tot;
}

void add_edge_(int u, int v, int w){
	ed_[++tot_].nxt = head_[u];
	ed_[tot_].to = v, ed_[tot_].w = w;
	head_[u] = tot_;
}

void build(int u, int v, int val){
	sqr++;
	int i = v;
	sum[i] = val;
	while(i != u) sum[fa[i]] = sum[i] + res[i], i = fa[i];
	sum[sqr+n] = sum[u];
	i = v;
	while(i != fa[u]){
		int w = min(sum[i], sum[sqr+n] - sum[i]);
		add_edge_(sqr + n, i, w), add_edge_(i, sqr + n, w);
		i = fa[i];
	}
}

void tarjan(int u, int father){
	dfn[u] = low[u] = ++num;
	for(int i = head[u]; i; i = ed[i].nxt){
		int v = ed[i].to, w = ed[i].w;
		if(v == father) continue;
		if(!dfn[v]){
			res[v] = w;
			fa[v] = u;
			tarjan(v, u);
			low[u] = min(low[u], low[v]);
		}
		else low[u] = min(low[u], dfn[v]);
		if(dfn[u] < low[v]) add_edge_(u, v, w), add_edge_(v, u, w);
	}
	for(int i = head[u]; i; i = ed[i].nxt){
		int v = ed[i].to;
		ll w = ed[i].w;
		if(fa[v] == u || dfn[v] <= dfn[u]) continue;
		build(u, v, w);
	}
}

void L(){
	for(int i = 1; i <= n*2; i++){
		lg[i] = lg[i-1] + (i % (1 << lg[i-1]) == 0);
	}
}

void dfs(int u, int father){
	f[u][0] = father;
	d[u] = d[father] + 1;
	for(int i = 1; i <= lg[d[u]]; i++) f[u][i] = f[f[u][i-1]][i-1];
	for(int i = head_[u]; i; i = ed_[i].nxt){
		int v = ed_[i].to;
		ll w = ed_[i].w;
		if(v == father) continue;
		dis[v] = dis[u] + w;
		dfs(v, u);
	}
}

int lca(int x, int y){
	if(d[x] < d[y]) swap(x, y);
	while(d[x] > d[y]){
		x = f[x][lg[d[x]-d[y]] - 1];
	}
	if(x == y) return x;
	for(int i = lg[d[x]] - 1; i >= 0; --i){
		if(f[x][i] != f[y][i]){
			x = f[x][i], y = f[y][i];
		}
	}
	prex = x, prey = y;
	return f[x][0];
}

ll get(int u, int v){
	int anc = lca(u, v);
	if(anc <= n) return dis[u] + dis[v] - 2 * dis[anc];
	else
	  return dis[u]+dis[v]-dis[prex]-dis[prey]+min(abs(sum[prex]-sum[prey]), sum[anc]-abs(sum[prex]-sum[prey]));
}

int main(){
//	freopen("P5236_1.in", "r", stdin);
//	freopen("1", "w", stdout);
	n = read(), m = read(), q = read();
	for(int i = 1, u, v, w; i <= m; i++){
		u = read(), v = read(), w = read();
		add_edge(u, v, w), add_edge(v, u, w);
	}
	tarjan(1, 0);
	L();
	dfs(1, 0);
	for(int i = 1, u, v; i <= q; i++){
		u = read(), v = read();
		printf("%lld\n", get(u, v));
	}
	return 0;
}
