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

const int N = 2e6 + 5;
struct Edge{int nxt, to, w;bool fab;}ed[N<<1];
int n, a, b;
int head[N], tot=1, dfn[N], low[N], num, st[N], top, res[N];
vector<int> s;
int f[N][2], g[N][2], ans = inf;

void add_edge(int u, int v, int w){
	ed[++tot].nxt = head[u];
	ed[tot].to = v, ed[tot].w = w;
	head[u] = tot;
}

void tarjan(int u, int ine){
	dfn[u] = low[u] = ++num;
	st[++top] = u;
	for(int i = head[u]; i; i = ed[i].nxt){
		int v = ed[i].to;
		res[v] = i;
		if(!dfn[v]){
			tarjan(v, i);
			if(low[v] > dfn[u]){
				int y = 0;
				do{
					y = st[top];
					s.push_back(res[y]);
				}while(st[top--] != v);
			}
		}
		else if(i != 1 ^ ine) low[u] = min(low[u], dfn[v]);
	}
}

void dfs(int u, int fa, int ine){
	int plc = 0, flag = inf;
	if(u > n) g[u][0] = 0, g[u][1] = ed[ine].w;
	else f[u][0] = 0, f[u][1] = 0;
	for(int i = head[u]; i; i = ed[i].to){
		int v = ed[i].to, w = ed[i].w;
		if(ed[i].fab && u > n) g[u][1] += ed[i].w;
		if(v == fa || ed[i].fab) continue;
		dfs(v, u, i);
		if(u > n){
			g[u][1] += w + min(f[v][0], f[v][1]);
			g[u][0] += f[v][1];
		}
		else{
			f[u][0] += g[v][0];
			if(g[v][1] - g[v][0] < inf) plc = v, flag = g[v][1] - g[v][0];
		}
	}
	if(u <= n){
		for(int i = head[u]; i; i = ed[i].nxt){
			int v = ed[i].to;
			if(v == fa || ed[i].fab) continue;
			if(v == plc) f[u][1] += g[v][1];
			else f[u][1] += min(g[v][0], g[v][1]);
		}
	}
}

int main(){
	n = read(), a = read(), b = read();
	for(int i = 1, u1, u2; i <= n; i++){
		u1 = read(), u2 = read();
		add_edge(i, u1+n, a), add_edge(u1+n, i, a);
		add_edge(i, u2+n, b), add_edge(u2+n, i, b);
	}
	tarjan(1, 0);
	for(int i = 0; i < s.size(); i++){
		ed[s[i]].fab = ed[s[i]^1].fab = true;
		dfs(1, 0, 0);
		ans = min(ans, min(f[1][0], f[1][1]));
		ed[s[i]].fab = ed[s[i]^1].fab = false;
	}
	printf("%d", ans);
}
