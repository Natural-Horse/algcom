#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
#define int long long
using namespace std;

inline int read(){
	int x = 0, f = 1; char ch = getchar();
	while(!isdigit(ch)){if(ch == '-') f = -1;ch = getchar();}
	while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - 48; ch = getchar();}
	return x * f;
}

const int N = 2e6 + 5;

struct Edge{
	int u, v, nxt;
}ed[N << 1]; 
int n, m, hd[N], tot;
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

signed main(){
	n = read(), m = read();
	for(int i = 1, u, w1, v, w2; i <= m; i++){
		u = read(), w1 = read(), v = read(), w2 = read();
//		if(u == v && w1 == w2) continue; 
		if(!w1 && w2) add_edge(u, v), add_edge(v+n, u+n);
		if(w1 && !w2) add_edge(u+n, v+n), add_edge(v, u);
		if(w1 && w2) add_edge(u+n, v), add_edge(v+n, u);
		if(!w1 && !w2) add_edge(u, v+n), add_edge(v, u+n);
	}
	for(int i = 1; i <= (n<<1); i++)
		if(!dfn[i]) tarjan(i);
	for(int i = 1; i <= n; i++){
		if(p[i] == p[i+n]){
			printf("IMPOSSIBLE\n");
			return 0;
		}
	}
	printf("POSSIBLE\n");
	for(int i = 1; i <= n; i++){
		if(p[i] > p[i+n])  printf("0 ");
		else printf("1 ");
	} 
	return 0;
}

