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
}ed[N >> 1];
int n, m, head[N], tot, c[N];
bool b[N];

void add_edge(int u, int v){
	ed[++tot].nxt = head[u], ed[tot].to = v, head[u] = tot;
}

void dfs(int u, int dis, int lim){
	if(dis > lim) return; 
	b[c[u]] = true;
	for(int i = head[u]; i; i = ed[i].nxt){
		int v = ed[i].to;
		dfs(v, dis + 1, lim);
	}
}

int main(){
	n = read(), m = read();
	for(int i = 1; i <= n; i++) c[i] = read();
	for(int i = 2; i <= n; i++){
		int father = read();
		add_edge(father, i);
	}
	for(int i = 1; i <= m; i++){
		int u, d, ans = 0;
		u = read(), d = read();
		dfs(u, 0, d);
		for(int i = 1; i <= n; i++) 
			if(b[i]){
				ans++;
				b[i] = false;
			}
		printf("%d\n", ans);
	}
	return 0;
}

