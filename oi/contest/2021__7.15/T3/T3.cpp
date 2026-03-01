#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define LL long long
using namespace std;

LL read(){
	LL x = 0,f = 1;char ch = getchar();
	while (ch < '0' || ch > '9'){if (ch == '-') f = -1; ch = getchar();}
	while (ch >= '0' && ch <= '9'){x = x*10 + ch - 48; ch = getchar();}
	return x * f;
}

const int N = 1e5 + 5;

struct Edge{
	int nxt, to;
}ed[N];
int n;
int head[N], tot, dep[N], fa[N];
long long w[N];
double ans[N];

void add_edge(int u, int v){
	ed[++tot].nxt = head[u], ed[tot].to = v, head[u] = tot;
}

void dfs(int u){
	int plc = u;
	double minn = inf;
	ans[u] = inf;
	while(fa[plc]){
		plc = fa[plc];
		minn = min(minn, (double)(w[plc]-w[u]) / (double)(dep[u]-dep[plc]));
	}
	ans[u] = minn;
	for(int i = head[u]; i; i = ed[i].nxt){
		int v = ed[i].to;
		dep[v] = dep[u] + 1;
		dfs(v);
	} 
}

int main(){
	n = read();
	for(int i = 1; i <= n; i++) w[i] = read();
	for(int i = 2; i <= n; i++){
		fa[i] = read();
		add_edge(fa[i], i);
	}
	dfs(1);
	for(int i = 2; i <= n; i++){
		printf("%.10lf\n", ans[i]);
	}	
	return 0;
}
