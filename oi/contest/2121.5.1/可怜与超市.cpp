#include<bits/stdc++.h>
#define inf 0x3f3f3f3f3f3f3f3f
#define ll long long
#define rl register int
using namespace std;

const int Maxn = 5e3 + 5;

struct Edge{
	int nxt, to;
}ed[Maxn * 2];

int n, b;
int d[Maxn], w[Maxn];
int head[Maxn], tot;

void add_edge(int u, int v){
	ed[++tot].nxt = head[u];
	ed[tot].to = v;
	head[u] = tot;
}

int size[Maxn];
ll f[Maxn][Maxn][2];
ll g[Maxn];

void dfs(int u){
	size[u] = 1;
	f[u][1][1] = w[u] - d[u], f[u][1][0] = w[u], f[u][0][0] = 0; 
	for(int i = head[u]; i; i = ed[i].nxt){
		int v = ed[i].to;
		dfs(v);			
		for(rl j = size[u]; j >= 0 ; --j){
			for(rl k = size[v]; k >= 0; --k){
				f[u][j+k][0] = min(f[u][j+k][0], f[v][k][0] + f[u][j][0]);
				f[u][j+k][1] = min(f[u][j+k][1], min(f[v][k][1], f[v][k][0]) + f[u][j][1]);
			}
		}
		size[u] += size[v];
	}		
}


int main(){
	scanf("%d %d", &n, &b);
	for(int i = 1; i <= n; i++){
		scanf("%d %d", &w[i], &d[i]);
		if(i > 1){
			int fa;
			scanf("%d", &fa);
			add_edge(fa, i);
		}
	}
	memset(f, inf, sizeof(f));
	dfs(1);
	int ans = 0;
	for(int i = 1; i <= n; i++){
		if(f[1][i][0] <= b || f[1][i][1] <= b){
			ans = i;
		}
	}
	printf("%d", ans);
	return 0;
}
