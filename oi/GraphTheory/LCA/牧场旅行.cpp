#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

const int Maxn = 1005;

struct Edge{
	int nxt, to, len;
}ed[2 * Maxn];

int n, q;
int head[Maxn], tot;

void add_edge(int u, int v, int w){
	ed[++tot].nxt = head[u];
	ed[tot].to = v;
	ed[tot].len = w;
	head[u] = tot;
}

int f[Maxn][50];
int lg[Maxn]; 
ll diff[Maxn];
int dep[Maxn];
ll ans;

void pre_work(){
	for(int i = 1; i <= n; i++){
		lg[i] = lg[i-1] + ((1 << lg[i-1]) == i);
	}
}

void dfs(int u, int fa){
	f[u][0] = fa;
	for(int i = 1; i <= lg[dep[u]]; i++){
		f[u][i] = f[f[u][i-1]][i-1];
	}
	for(int i = head[u]; i; i = ed[i].nxt){
		int v = ed[i].to;
		if(v == fa) continue;
		ll w = ed[i].len;
		diff[v] = diff[u] + w;
		dep[v] = dep[u] + 1;
		dfs(v, u);
	}
}

int lca(int a, int b){
	if(dep[a] < dep[b]) swap(a, b);
	while(dep[a] > dep[b]){
		a = f[a][lg[dep[a]-dep[b]] - 1];
	}
	if(a == b) return a;
	for(int i = lg[dep[a]]; i >= 0; --i){
		if(f[a][i] != f[b][i]){
			a = f[a][i];
			b = f[b][i];
		}
	}
	return f[a][0];
}

int main(){
	scanf("%d %d", &n, &q);
	for(int i = 1; i < n; i++){
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		add_edge(u, v, w);
		add_edge(v, u, w);
	}
	pre_work();
	dfs(1, 0);
	for(int i = 1; i <= q; i++){
		int u, v;
		scanf("%d %d", &u, &v);
		int anc = lca(u, v);
		ans = diff[u] + diff[v] - 2 * diff[anc];
		printf("%lld\n", ans);
	}
	return 0;
} 
