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

struct Edge{
	int nxt, to;
}ed[N << 1];
int n, c, p[N], head[N], tot;

void add_edge(int u, int v){
	ed[++tot].nxt = head[u], ed[tot].to = v, head[u] = tot;
}

int f[N][105][2], g[105][2], sum[N], ans;

void dfs(int u, int fa, int dif, bool ch){
	int jud = sum[u], res = sum[u];
	for(int i = head[u]; i; i = ed[i].nxt){
		int v = ed[i].to;
		jud += sum[v];
	}
	if(ch) jud -= sum[fa];
	ans = max(ans, dif + jud - sum[u]);
	sum[u] = jud;
	for(int i = head[u]; i; i = ed[i].nxt){
		int v = ed[i].to;
		if(v == fa) continue;
		int fab = sum[v];
		sum[v] = 0;
		dfs(v, u, dif+sum[u]-res, true);
		sum[v] = fab;
	}
	sum[u] = res;
	ans = max(ans, dif - sum[u]);
	for(int i = head[u]; i; i = ed[i].nxt){
		int v = ed[i].to;
		if(v == fa) continue;
		dfs(v, u, dif-sum[u], false);
	}
	return;
}

int main(){
	n = read(), c = read();
	for(int i = 1; i <= n; i++) p[i] = read(), sum[i] = p[i];
	for(int i = 1, u, v; i < n; i++){
		u = read(), v = read();
		add_edge(u, v), add_edge(v, u);
//		cap[u] += p[v], cap[v] += p[u];
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++) sum[j] = p[j];
		dfs(i, 0, 0, false);
	}
	printf("%d", ans);
	return 0;
}

