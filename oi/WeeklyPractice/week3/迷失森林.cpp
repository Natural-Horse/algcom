#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

const int Maxn = 1e6 + 5;

struct Edge{
	int nxt, to;
}ed[Maxn * 2];

int n;
int head[Maxn], tot;

void add_edge(int u, int v){
	ed[++tot].nxt = head[u];
	ed[tot].to = v;
	head[u] = tot;
}

ll f[Maxn], d[Maxn], dmax;
ll r[Maxn][3];
int son[Maxn];
ll ans;

void dfs1(int u, int fa){
	d[u] = d[fa] + 1;
	dmax = max(dmax, d[u]);
	for(int i = head[u]; i; i = ed[i].nxt){
		int v = ed[i].to;
		if(v == fa) continue;
		son[u]++;
		dfs1(v, u);
	}	
}

void dfs2(int u, int fa){
	for(int i = head[u]; i; i = ed[i].nxt){
		int v = ed[i].to;
		if(v == fa) continue;
		dfs2(v, u);
		ll len = f[v];
		if(len > r[u][1]){
			r[u][2] = r[u][1];
			r[u][1] = len;
		} 
		else if(len > r[u][2]){
			r[u][2] = len;
		} 
		f[u] = max(f[u], r[u][1] + d[u]);
	}
	if(!son[u]){
		f[u] = dmax;
	} 
	ans = max(ans, r[u][1] + r[u][2] + 1);	
	
}

int main(){
	scanf("%d", &n);
	for(int i = 1, u, v; i < n; i++){
		scanf("%d %d", &u, &v);
		add_edge(u, v);
		add_edge(v, u);
	}
	dfs1(1, 0);
	dfs2(1, 0);
	printf("%lld", max(ans, f[1] + dmax - 1));
	return 0;
}
