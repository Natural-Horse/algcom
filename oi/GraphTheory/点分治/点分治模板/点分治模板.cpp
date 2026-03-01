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

const int N = 1e4 + 5;

struct Edge{
	int nxt, to, w;
	bool ps;
}ed[N*2];

int n, m;
int q[105],b[105];
int head[N], tot = 1;
int flag, plc;
int siz[N], dis[N], f[N], st[N], top;

void add_edge(int u, int v, int w){
	ed[++tot].nxt = head[u];
	ed[tot].to = v, ed[tot].w = w, head[u] = tot;
}

void dfs1(int u, int fa, int size){
	siz[u] = 1;
	int maxn = 0;
	for(int i = head[u]; i; i = ed[i].nxt){
		int v = ed[i].to, w = ed[i].w;
		if(v == fa && !ed[i].ps) {siz[u]++; continue;}
		else if(ed[i].ps) continue;		
		dfs1(v, u, size);
		siz[u] += siz[v];
		maxn = max(maxn, siz[v]);
	}
	maxn = max(maxn, size - siz[u]);
	if(maxn < flag) {flag = maxn, plc = u;}
}

void dfs2(int u, int fa, int rt){
	st[++top] = u, f[u] = rt;
	for(int i = head[u]; i; i = ed[i].nxt){
		int v = ed[i].to, w = ed[i].w;
		if(v == fa || ed[i].ps) continue;
		dis[v] = dis[u] + w;
		dfs2(v, u, rt);
	}
}

bool cmp(int x, int y){return dis[x] < dis[y];}

void get(int u, int fa){
	if(!siz[u]) siz[u] = n;
	plc = 0, flag = inf;
	top = 0;
	dfs1(u, fa, siz[u]);
	for(int i = head[plc]; i; i = ed[i].nxt){
		int v = ed[i].to, w = ed[i].w;
		if(ed[i].ps) continue;
		ed[i].ps = ed[i^1].ps = true;
		dis[v] = w;
		dfs2(v, plc, v);
	}
	sort(st + 1, st + 1 + top, cmp);
	for(int i = 1; i <= m; i++){
		if(b[i]) continue;
		int l = 0, r = top;
		while(l < r){
			if(dis[st[l]] + dis[st[r]] > q[i]) r--;
			else if(dis[st[l]] + dis[st[r]] < q[i]) l++;
			else if(f[st[l]] == f[st[r]])
				 	if(dis[st[r]] == dis[st[r-1]]) r--;
				 	else l++;
			else {b[i]++; break;}
		}
	}
	for(int i = head[u]; i; i = ed[i].nxt){
		int v = ed[i].to;
		if(v == fa) continue;
		get(v, u);
	}
}

int main(){
//	freopen("P3806_1.in", "r", stdin);
//	freopen("1", "w", stdout);
	n = read(), m = read();
	for(int i = 1, u, v, w; i < n; i++){
		u = read(), v = read(), w = read();
		add_edge(u, v, w), add_edge(v, u, w);
	}		
	for(int i = 1; i <= m; i++) q[i] = read();
	get(1, 0);
	for(int i = 1; i <= m; i++)
		if(b[i]) printf("AYE\n");
		else printf("NAY\n");
	return 0;
}

