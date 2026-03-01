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

const int N = 1e5 + 5;

ll n, m, p[N], sum[N], ans;
vector<int> to[N];
ll f[N][105], g[N][105];

void dfs1(int u, int fa){
//	f[u][0] = -p[u];g[u][0] = -p[fa];
	for(int i = 1; i <= m; i++) f[u][i] = sum[u], g[u][i] = sum[u] - p[fa];
	int len = to[u].size();
	for(int i = 0; i < len; i++){
		int v = to[u][i];
		if(v == fa) continue;
		dfs1(v, u);
		for(int j = 0; j <= m; j++){
			ans = max(ans, f[u][j] + g[v][m-j]);
			if(!j) continue;
			f[u][j] = max(f[u][j], max(f[v][j], f[v][j-1] + sum[u] - p[v]));
			g[u][j] = max(g[u][j], max(g[v][j], g[v][j-1] + sum[u] - p[fa]));			
		}
	}
}

void dfs2(int u, int fa){
//	f[u][0] = -p[u];g[u][0] = -p[fa];
	for(int i = 1; i <= m; i++) f[u][i] = sum[u], g[u][i] = sum[u] - p[fa];
	int len = to[u].size();
	for(int i = len-1; i >= 0; --i){
		int v = to[u][i];
		if(v == fa) continue;
		dfs2(v, u);
		for(int j = 0; j <= m; j++){
			ans = max(ans, f[u][j] + g[v][m-j]);
			if(!j) continue;
			f[u][j] = max(f[u][j], max(f[v][j], f[v][j-1] + sum[u] - p[v]));
			g[u][j] = max(g[u][j], max(g[v][j], g[v][j-1] + sum[u] - p[fa]));	
		}
	}
}

int main(){
	n = read(), m = read();
	for(int i = 1; i <= n; i++) p[i] = read();
	for(int i = 1, u, v; i < n; i++){
		u = read(), v = read();
		to[u].push_back(v), to[v].push_back(u);
		sum[u] += p[v], sum[v] += p[u];
	}
	dfs1(1, 0);
	memset(f, 0, sizeof(f));
	memset(g, 0, sizeof(g));
	dfs2(1, 0);
	printf("%lld", ans);
	return 0;
}
