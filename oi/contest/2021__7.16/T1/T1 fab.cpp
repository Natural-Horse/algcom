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

const int N = 6e4 + 5, M = 1e5 + 5;

struct Edge{
	int nxt, to;
}ed[M];
int n, m, head[N], tot, pre[N], ans, dev, mid;
bool vis[N];
bitset<N / 2> f[N];
queue<int> q;

void add_edge(int u, int v){
	ed[++tot].nxt=head[u];
	ed[tot].to=v;
	head[u]=tot;
}

void dfs(int u){
	vis[u] = true;
	if(!dev){
		if(u <= mid) f[u].set(u);
	}
	else{
		if(u > mid) f[u].set(u-mid);
	}
	for(int i = head[u]; i; i = ed[i].nxt){
		int v = ed[i].to;
		if(!vis[v]) dfs(v);
		f[u] |= f[v];
	}		
	return;
}

int main(){
//	freopen("worldline2.in", "r", stdin);
	n = read(), m = read();
	mid = n / 2;
	for(int i = 1, u, v; i <= m; i++){
		u = read(), v = read();	
		add_edge(u, v), pre[v]++;
	}
	dev = 0;
	for(int i = 1; i <= n; i++){
		if(!pre[i]) dfs(i);
	}
	for(int i = 1; i <= n; i++){
		ans += f[i].count();
		f[i].reset();
	}
	memset(vis, false, sizeof(vis));
	dev = 1;
	for(int i = 1; i <= n; i++){
		if(!pre[i]) dfs(i);
	}
	for(int i = 1; i <= n; i++) ans += f[i].count();
	ans -= n + m;		
	printf("%d", ans);
}

