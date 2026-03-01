#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

const int Maxn = 2e5+5;
const int Maxm = 5e4+5;

struct Edge{
	int nxt, to;
}ed[Maxn*2];

int n, m, c, q;
int p[Maxn], w[Maxn];
int cntc = 1;
int head[Maxn], tot;

void add_edge(int u, int v){
	ed[++tot].nxt = head[u];
	ed[tot].to = v;
	head[u] = tot;
}

int f[Maxn][35];
int dep[Maxn];
int lg[Maxn];

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

int lca(int x, int y){
	if(dep[x] < dep[y]) swap(x, y);
	while(dep[x] > dep[y]) x = f[x][lg[dep[x]-dep[y]]-1];
	if(x == y) return x;
	for(int i = lg[dep[x]]; i >= 0; --i){
		if(f[x][i] != f[y][i]){
			x = f[x][i];
			y = f[y][i];
		}
	}
	return f[x][0];
}

int s, t, anc;
int fir[Maxn], las[Maxn];
int cnta, cntb;
bool chea, cheb;
int ans;

void dfs2(int u, int fa){
	for(int i = head[u]; i; i = ed[i].nxt){
		if(u == anc){
			if(chea == true) chea = false;				
			if(cheb == true) cheb = false;
		}
		else{
			if(chea == true){
				fir[++cnta] = w[u];
				return;
			}
			if(cheb == true){
				las[++cntb] = w[u];
				return;
			}
			if(u == s){
				chea = true;
				fir[++cnta] = w[u];
				return;
			}
			if(u == t){
				cheb = true;
				las[++cntb] = w[u];
				return;
			}
		}		
		int v = ed[i].to;
		if(v == fa) continue;
		dfs2(v, u);
	}
}

int main(){
//	freopen("gem.in", "r", stdin);
//	freopen("gem.out", "w", stdout);
	scanf("%d %d %d", &n, &m, &c);
	for(int i = 1; i <= c; i++){
		scanf("%d", &p[i]);
	}
	for(int i = 1; i <= n; i++){
		scanf("%d", &w[i]);
	}
	for(int i = 1, u, v; i < n; i++){
		scanf("%d %d", &u, &v);
		add_edge(u, v);
		add_edge(v, u);
	}
	for(int i = 1; i <= n; i++){
		lg[i] = lg[i-1] + (lg[i/2] == lg[i-1]);
	}
	dep[1] = 1;
	dfs(1, 0);
	scanf("%d", &q);
	for(int i = 1; i <= q; i++){
		scanf("%d %d", &s, &t);
		anc = lca(s, t);
		chea = cheb = false;
		cnta = cntb = ans = 0;
		dfs2(anc, 0);
		fir[++cnta] = w[anc];
		cntc = 1;
		for(int j = 1; j <= cnta; j++){
			if(cntc > c) break;
			if(fir[j] == p[cntc]){
				ans++;
				cntc++;
			}
		}
		for(int j = cntb; j >= 1; --j){
			if(cntc > c) break;
			if(las[j] == p[cntc]){
				ans++;
				cntc++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
} 
