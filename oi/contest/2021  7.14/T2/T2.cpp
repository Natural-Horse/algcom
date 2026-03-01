#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

ll read(){
	ll x = 0,f = 1;char ch = getchar();
	while (ch < '0' || ch > '9'){if (ch == '-') f = -1; ch = getchar();}
	while (ch >= '0' && ch <= '9'){x = x*10 + ch - 48; ch = getchar();}
	return x * f;
}
const int N = 1e5 + 5;
struct Edge{
	int nxt, to;
	ll w;
}ed[N<<1];
int T, n;
ll w[N], ans, dis[N][2];
int head[N], tot;

void add_edge(int u, int v, int w){
	ed[++tot].nxt = head[u];
	ed[tot].to = v, ed[tot].w = w;
	head[u] = tot;
}
void dfs(int u, int fa, ll lim, int ine){
	dis[u][1] = dis[u][0] = 0;
	for(int i = head[u]; i; i = ed[i].nxt){
		int v = ed[i].to;
		if(v == fa || w[v] < lim) continue;
		dfs(v, u, lim, i);
		if(dis[v][1] > dis[u][1]){
			dis[u][2] = dis[u][1];dis[u][1] = dis[v][1];
		}
		if(dis[v][1] <= dis[u][1] && dis[v][1] > dis[u][2]){
			dis[u][2] = dis[v][1];
		}
	}
	dis[u][1] += ed[ine].w;
}

int main(){
	T = read();
	for(int ii = 1; ii <= T; ii++){
		ans = 0, tot = 0;
		memset(head, 0, sizeof(head));
		n = read();
		for(int i = 1; i <= n; i++) w[i] = read();
		for(int i = 1, u, v, w; i < n; i++){
			u = read(), v = read(), w = read();
			add_edge(u, v, w), add_edge(v, u, w);
		}
		for(int i = 1; i <= n; i++){
			dfs(i, 0, w[i], 0);
			ans = max(ans, (dis[i][1] + dis[i][2]) * w[i]);
		}
		printf("%lld\n", ans);
	}
	return 0;
}

