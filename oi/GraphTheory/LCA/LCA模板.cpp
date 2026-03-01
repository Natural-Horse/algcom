#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long 
using namespace std;

struct Edge{
	int nxt, to;
}ed[1000005];

int t, n, s;
int head[500005], tot;

void add_edge(int u, int v){
	ed[++tot].nxt = head[u];
	ed[tot].to = v;
	head[u] = tot;
}

int dep[500005],f[500005][25];
int lg[500005];

void dfs(int u, int fa){
	f[u][0] = fa;
	for(int i = 1; i <= lg[dep[u]]; i++){
		f[u][i] = f[f[u][i-1]][i-1];
	}
	for(int i = head[u]; i; i = ed[i].nxt){
		int v = ed[i].to;
		if(v == fa) continue;
		dep[v] = dep[u] + 1;	
		dfs(v, u);	
	}
}

int lca(int a, int b){
	if(dep[a] < dep[b]) swap(a,b);
	while(dep[a] > dep[b]){
		a = f[a][lg[dep[a]-dep[b]] - 1];
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
	scanf("%d", &t);
	for(int ii = 1; ii <= t; ii++){
		tot = 0;
		scanf("%d %d", &n, &s);
		for(int i = 1, u, v; i <= n-1; i++){
			scanf("%d %d", &u, &v);
			add_edge(u, v);
			add_edge(v, u);
		}
		dep[s] = 0;
		for(int i = 1; i <= n; i++){
			lg[i] = lg[i-1] + ((1 << lg[i-1]) == i);
		}
		dfs(s, 0);
		int u, v;
		scanf("%d %d", &u, &v);
		int ans = lca(u, v);
		printf("%d\n", ans);
	}
	return 0;
}
