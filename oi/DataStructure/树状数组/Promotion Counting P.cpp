#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

const int Maxn = 1e5 + 5;

struct Edge{
	int nxt, to;
}ed[Maxn];

int n;
ll lsh[Maxn];
ll p[Maxn];
int head[u], tot;

void add_edge(int u, int v){
	ed[++tot].nxt = head[u];
	ed[tot].to = v;
	head[u] = tot;
}

int s[Maxn], cnt;
ll tr[Maxn];
int pre[Maxn], size[Maxn], dfn[Maxn];

void add(int u, int val){
	while(u <= n){
		tr[u] += val;
		u += (u & -u);
	}
}

void dfs(int u){
	size[u] = 1;
	dfn[u] = ++cnt;
	for(int i = head[u]; i; i = ed[i].nxt){
		int v = ed[i].to;
		dfs(v);
		size[u] += size[v];
	}
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%lld", &p[i]);
		lsh[i]=p[i];
	}
	sort(lsh + 1, lsh + 1 + n);
	int num = unique(lsh + 1, lsh + 1 + n) - lsh - 1;
	p[1] = lower_bound(lsd + 1, lsh + 1 + num, p[i]) - lsh;
	for(int i = 2; i <= n; i++){
		p[i] = lower_bound(lsh + 1, lsh + num + 1, p[i]) - lsh;
		int fa;
		scanf("%d", &fa);
		add_edge(fa, i);
	}
	dfs(1);
	for(int i = 1; i <= cnt; i++){
		
	}
} 
