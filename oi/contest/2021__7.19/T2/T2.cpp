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

const int N = 105;

struct Edge{
	int nxt, to, c;
}ed[(N*N)<<1];

int n, m, d;
int head[N], tot;
bool b[1100000];
ll ans;

void add_edge(int u, int v, int c){
	ed[++tot].nxt = head[u]; ed[tot].to = v, ed[tot].c = c; head[u] = tot;
}

void dfs(int u, int fa, ll sta, int len){
	if(len > d) return;
	b[sta] = true;
	for(int i = head[u]; i; i = ed[i].nxt){
		int v = ed[i].to;
		dfs(v, u, sta<<1|ed[i].c, len+1);
	}
}

int main(){
	n = read(), m = read(), d = read();
	for(int i = 1, u, v, c; i <= m; i++){
		u = read(), v = read(), c = read();
		add_edge(u, v, c);
		add_edge(v, u, c);
	}
	dfs(1, 0, 1, 0);
	for(int i = (1 << d); i <= (1<<(d+1))-1; i++){
		if(b[i]) ans++;
	}
	printf("%lld", ans);
}

