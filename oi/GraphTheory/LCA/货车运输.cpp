#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

const int Maxn = 1e4+5, Maxm = 5e4;

struct Edge{
	int nxt, to, len;
	int b; 
}ed[Maxm * 2 + 5];

struct MT{
	int u, v, w;
	int num;
}ed_[Maxm * 2 + 5];

int n, m, q;
int head[Maxn], tot = 1;
int fa[Maxn], maxn;
bool vis[Maxn];
int dep[Maxn], f[Maxn][50];
int lg[Maxn];
int ans[Maxn][50]; 
int ansl;

void add_edge(int u, int v, int w){
	ed[++tot].nxt = head[u];
	ed[tot].to = v;
	ed[tot].len = w;
	head[u] = tot;
	ed_[tot].u = u, ed_[tot].v = v, ed_[tot].w = w;
	ed_[tot].num = tot;
}

bool cmp(MT a, MT b){
	return a.w > b.w;
}

int find(int x){
	if(x == fa[x]) return x;
	else return fa[x] = find(fa[x]);
}

void merge(int x, int y){
	fa[find(x)] = find(y);
}

void dfs(int u, int far){
	f[u][0] = far;
	vis[u] = true;
	for(int i = 1; i <= lg[dep[u]]; i++){
		f[u][i] = f[f[u][i-1]][i-1];
		ans[u][i] = min(ans[u][i-1], ans[f[u][i-1]][i-1]);
	}
	for(int i = head[u]; i; i = ed[i].nxt){
		int v = ed[i].to;
		int w = ed[i].len;
		if(!ed[i].b || v == far) continue;
		ans[v][0] = w;
		dep[v] = dep[u] + 1;
		dfs(v, u);
	}
}

int lca(int x, int y){
	if(dep[x] < dep[y]) swap(x, y);
	while(dep[x] > dep[y]){
		ansl = min(ansl, ans[x][lg[dep[x]-dep[y]] - 1]);
		x = f[x][lg[dep[x]-dep[y]] - 1];
	}
	if(x == y) return x;
	for(int i = lg[dep[x]] - 1; i >= 0; --i){
		if(f[x][i] != f[y][i]){
			ansl = min(ansl, ans[x][i]);
			ansl = min(ansl, ans[y][i]);
			x = f[x][i];
			y = f[y][i];			
		}
	}
	ansl = min(ansl, ans[x][0]);
	ansl = min(ansl, ans[y][0]);
	return f[x][0];
}

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++){
		fa[i] = i;
	}
	maxn = n;
	for(int i = 1; i <= m; i++){
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		add_edge(u, v, w);
		add_edge(v, u, w);
	}
	sort(ed_ + 2, ed_ + 2 + tot, cmp);
	int k = 2;
	while(maxn > 1 && k <= tot + 1){
		int u = ed_[k].u, v = ed_[k].v, w = ed_[k].w;
		if(find(u) != find(v)){
			merge(u, v);
			ed[ed_[k].num].b = 1;
			ed[ed_[k].num ^ 1].b = 1;
			maxn--;
		}
		k++;
	}
	for(int i = 1; i <= n; i++){
		lg[i] = lg[i-1] + ((1 << lg[i-1]) == i);
	}
	for(int i = 1; i <= n; i++){
		if(!vis[i]){
			ans[i][0] = inf;
			dfs(i, 0);
//			printf("%d\n", i);
		}
	}
	scanf("%d", &q);
	for(int i = 1; i <= q; i++){
		int u, v;
		ansl = inf;
		scanf("%d %d", &u, &v);
		int anc = lca(u, v);
		if(!anc) printf("-1\n");
		else printf("%d\n", ansl);
	}
	return 0;
}
