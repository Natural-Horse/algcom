#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long 
using namespace std;

const int Maxn = 2005;

struct Edge{
	int nxt, to, len;
}ed[Maxn * 2];

int n,k;
int head[Maxn], tot;
ll dp[Maxn][Maxn];
ll g[Maxn];
int siz[Maxn];
ll ans;

void add_edge(int u, int v, int w){
	ed[++tot].nxt = head[u];
	ed[tot].to = v;
	ed[tot].len = w;
	head[u] = tot;
}

void dfs(int u,int fa){
	siz[u] = 1;
	dp[u][0] = dp[u][1] = 0;
	for(int i = head[u]; i; i = ed[i].nxt){
		int v = ed[i].to;
		if(v == fa) continue;
		int w = ed[i].len;
		dfs(v, u);
		for(int j = 0; j <= siz[u]; j++) g[j] = dp[u][j];
		for(int j = 0; j <= min(k, siz[u]); j++){
			for(int s = 0; s <= min(k, siz[v]) && j + s <= k; s++){
//				if(dp[u][j] == -1 || dp[v][s] == -1) continue;
				ll val = (ll)w * ((ll)(k-s) * s + (ll)(siz[v]-s) * (n-k-siz[v]+s));
				dp[u][j+s] = max(dp[u][j+s], g[j] + dp[v][s] + val);
			}
		}
		siz[u] += siz[v];
	}
}

int main(){
	scanf("%d %d", &n, &k);
	for(int i = 1, u, v, w; i <= n - 1; i++){
		scanf("%d %d %d", &u, &v, &w);
		add_edge(u, v, w);
		add_edge(v, u, w);
	}
	memset(dp, -1, sizeof(dp));
	dfs(1, 0);
	printf("%lld", dp[1][k]);
	return 0;
}
