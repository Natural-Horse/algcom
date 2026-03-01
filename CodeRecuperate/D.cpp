#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

inline int read(){
	int x = 0, f = 1; char ch = getchar();
	while(!isdigit(ch)){if(ch == '-') f = -1; ch = getchar();}
	while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - 48; ch = getchar();}
	return x * f;
}

const int N = 2e5 + 5;

struct Edge{
	int u, v, nxt;
}ed[N << 1]; 
int n, m, hd[N], tot, a[N], b[N];
int st[N<<1], top, dfn[N<<1], low[N<<1], num, cnt, p[N<<1];
bool vis[N<<1];

void add_edge(int u, int v){
	ed[++tot].u = u, ed[tot].v = v;
	ed[tot].nxt = hd[u], hd[u] = tot;
}

void tarjan(int u){
	dfn[u] = low[u] = ++num;
	st[++top] = u, vis[u] = true;
	for(int i = hd[u]; i; i = ed[i].nxt){
		int v = ed[i].v;
		if(!dfn[v]) tarjan(v), low[u] = min(low[u], low[v]);
		else if(vis[v]) low[u] = min(low[u], dfn[v]);
	}
	if(dfn[u] == low[u]){
		cnt++;
		do{
			int y = st[top];
			p[y] = cnt, vis[y] = false;
		}while(st[top--] != u);
	}
}

int main(){
	n = read(), m = read();
	for(int i = 1; i <= m; i++) a[i] = read();
	for(int i = 1; i <= m; i++) b[i] = read();
	for(int i = 1; i <= m; i++){
		add_edge(a[i], b[i] + m), add_edge(a[i] + m, b[i]);
	}
	for(int i = 1; i <= (m<<1); i++)
		if(!dfn[i]) tarjan(i);
	for(int i = 1; i <= m; i++){
		if(p[i] == p[i+m]){
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");
	return 0;
}

