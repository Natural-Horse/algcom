#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

const int Maxn = 1e5 + 5;

struct Edge{
	int nxt, to;	
}ed[2 * Maxn], ed_[Maxn * 2];

int n, m;
int head[Maxn], tot = 1, head_[Maxn * 2], tot_;

void add_edge(int u, int v){
	ed[++tot].nxt = head[u];
	ed[tot].to = v;
	head[u] = tot;
}

void add_edge_(int u, int v){
	ed_[++tot_].nxt = head_[u];
	ed_[tot_].to = v;
	head_[u] = tot_;
}

int st[Maxn], top, root;
int dfn[Maxn], low[Maxn], num, cnt;
int w[Maxn];
int p[Maxn];
int ecc[Maxn * 2];
bool b[Maxn];
int son[Maxn];

void tarjan(int u, int ine){
	if(p[u] == 0) p[u] = 1;
	dfn[u] = low[u] = ++num;
	st[++top] = u;
	for(int i = head[u]; i; i = ed[i].nxt){
		int v = ed[i].to;
		son[u]++;
		if(!dfn[v]){
			tarjan(v, i);
			low[u] = min(low[u], low[v]);
			if(low[v] > dfn[u]){
				ecc[i] = ecc[i^1] = 1;
				cnt++;
				do{
					int y = st[top];
					w[cnt]++;
					p[y] = cnt;
				}while(st[top--] != v);
			}
		}
		else if(i != (ine^1)) low[u] = min(low[u], low[v]);
	}
}

void build(){
	for(int i = 2; i <= tot; i++){
		if(ecc[i]){
			int u = ed[i^1].to;
			int v = ed[i].to;
			b[u] = b[v] = true;
			add_edge_(p[u], p[v]);
		}
	}
}

int f[Maxn];
bool check[Maxn];
ll dp[Maxn];

void dfs(int u, int fa){
	for(int i = head_[u]; i; i = ed_[i].nxt){
		int v = ed_[i].to;
		if(v == fa) continue;
		check[u] = true;		
		dfs(v, u);		
	}
}

ll ans;

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 1, u, v; i <= m; i++){
		scanf("%d %d", &u, &v);
		add_edge(u, v);
		add_edge(v, u);
	}
	root = 1;
	tarjan(1, 0);
	build();
	dfs(1, 0);
	for(int i = 1; i <= n; i++){
		if(b[i] && check[p[i]]) ans += (ll)son[i] * (ll)(son[i] - 1) / 2;
	}
	printf("%lld", ans);
	return 0;
}
