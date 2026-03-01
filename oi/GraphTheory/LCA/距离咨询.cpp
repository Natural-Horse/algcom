#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

const int Maxn = 4e5;

struct Edge{
	int nxt, to, len;
}ed[2 * Maxn + 5];

int n, m, k;
int head[Maxn + 5], tot;

void add_edge(int u, int v, int w){
	ed[++tot].nxt = head[u];
	ed[tot].to= v;
	ed[tot].len = w;
	head[u] = tot;
}

int diff[Maxn + 5];
int dep[Maxn + 5];
int f[Maxn + 5][50]; 
int lg[Maxn + 5];

void dfs(int u, int fa){
	f[u][0] = fa;
	for(int i = 1; i <= lg[dep[u]]; i++){
		f[u][i] = f[f[u][i - 1]][i - 1];
	}
	for(int i = head[u]; i; i = ed[i].nxt){
		int v = ed[i].to;
		if(v == fa) continue;
		int w = ed[i].len;
		diff[v] = diff[u] + w;
		dep[v] = dep[u] + 1;
		dfs(v, u);
	}
}

int lca(int a, int b){
	if(dep[a] < dep[b]) swap(a, b);
	while(dep[a] > dep[b]){
		a = f[a][lg[dep[a] - dep[b]] - 1];
	}
	if(a == b) return a;
	for(int i = lg[dep[a]] - 1; i >= 0; --i){
		if(f[a][i] != f[b][i]){
			a = f[a][i];
			b = f[b][i];
		}
	}
	return f[a][0];
}

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 1, u, v, w; i <= m; i++){
		char d;
		scanf("\n%d %d %d %c", &u, &v, &w, &d);
		add_edge(u, v, w);
		add_edge(v, u, w);
	}
	for(int i = 1; i <= n; i++){
		lg[i] = lg[i-1] + ((1 << lg[i-1]) == i);
	}
	dep[1] = 1;
	dfs(1, 0);
	scanf("%d", &k);	
	for(int i = 1; i <= k; i++){
		int u, v;
		scanf("%d %d", &u, &v);
		int anc = lca(u, v);
		int ans = diff[u] + diff[v] - 2 * diff[anc];
		printf("%d\n", ans);
	}
	return 0;
}
