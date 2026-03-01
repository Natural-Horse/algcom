#include<bits/stdc++.h>
#define inf 0x3f3f3f3f3f3f3f3f
#define ll long long
using namespace std;

const int Maxn = 1e5 + 5;
const int mod = 1e9 + 7;

//struct Edge{
//	int nxt, to;
//}ed[Maxn * 2];

int n, m;
//int head[Maxn], tot;
vector<int> ed[Maxn];

//void add_edge(int u, int v){
//	ed[++tot].nxt = head[u];
//	ed[tot].to = v;
//	head[u] = tot;
//}

int f[Maxn][105][2][2]; // 节点编号，放了几个，自己是否放，是否被儿子管 
int g[105][2][2];     // (辅助数组) 放了几个，自己是否放，是否被儿子管 
int size[Maxn];

void dfs(int u, int fa){
	size[u] = 1;	
	f[u][0][0][0] = 1;
	f[u][1][1][0] = 1;	
	for(int v : ed[u]){
		if(v == fa) continue;
		dfs(v, u);
		for(int j = 0; j <= min(m, size[u]); j++){
			g[j][0][0] = f[u][j][0][0], f[u][j][0][0] = 0;
			g[j][1][0] = f[u][j][1][0], f[u][j][1][0] = 0;
			g[j][0][1] = f[u][j][0][1], f[u][j][0][1] = 0;
			g[j][1][1] = f[u][j][1][1], f[u][j][1][1] = 0;
		}
		for(int j = 0; j <= min(m, size[u]); j++){
			for(int k = 0; k <= min(m - j, size[v]); k++){
				f[u][j+k][0][0] = (f[u][j+k][0][0] + (ll)g[j][0][0] * f[v][k][0][1]) % mod;
				f[u][j+k][0][1] = (f[u][j+k][0][1] + (ll)g[j][0][1] * (((ll)f[v][k][1][1] + f[v][k][0][1]) % mod) % mod + (ll)g[j][0][0] * f[v][k][1][1] % mod) % mod;
				f[u][j+k][1][0] = (f[u][j+k][1][0] + (ll)g[j][1][0] * (((ll)f[v][k][0][1] + f[v][k][0][0]) % mod)) % mod;
				f[u][j+k][1][1] = (f[u][j+k][1][1] + (ll)g[j][1][1] * (((ll)f[v][k][0][0] + f[v][k][0][1] + f[v][k][1][0] + f[v][k][1][1]) % mod) % mod + (ll)g[j][1][0] * (((ll)f[v][k][1][0] + f[v][k][1][1]) % mod) % mod) % mod;				
			}
		}
		size[u] += size[v];
	}
} // 节点编号，放了几个，自己是否放，是否被儿子管 

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 1, u, v; i < n; i++){
		scanf("%d %d", &u, &v);
		ed[u].push_back(v);
		ed[v].push_back(u);
	}
	dfs(1, 0);
	ll ans = f[1][m][0][1] + f[1][m][1][1];
	printf("%lld", ans);
	return 0;
}
