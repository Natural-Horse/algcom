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
}ed[(N*N) << 1];

int n, m, d, head[N], tot;
bool f[25][N][1 << 12], g[25][N][1 << 12];

void add_edge(int u, int v, int c){
	ed[++tot].nxt = head[u], ed[tot].to = v, ed[tot].c = c, head[u] = tot;
}

int main(){
	n = read(), m = read(), d = read();
	for(int i = 1; i <= m; i++){
		int u, v, c;
		u = read(), v = read(), c = read();
		add_edge(u, v, c), add_edge(v, u, c);
	}
	f[0][1][0] = true;
	for(int i = 1; i <= n; i++) g[0][i][0] = true;
	for(int dis = 0; dis < (d>>1); dis++){
		int sta = 1 << dis;
		for(int j = 0; j <= sta; j++){
			for(int u = 1; u <= n; u++){
				for(int i = head[u]; i; i = ed[i].nxt){
					int v = ed[i].to;
					f[dis+1][v][j<<1|ed[i].c] |= f[dis][u][j];
				}
			}
		}
	}
	for(int dis = 0; dis < d-(d>>1); dis++){
		int sta = 1 << dis;
		for(int j = 0; j < sta; j++){
			for(int u = 1; u <= n; u++){
				for(int i = head[u]; i; i = ed[i].nxt){
					int v = ed[i].to;
					g[dis+1][v][j<<1|ed[i].c] |= g[dis][u][j];
				}
			}
		}
	}
	ll ans = 0;
	for(int i = 0; i <= (1 << d) - 1; i++){
		for(int j = 1; j <= n; j++){
			if(f[d>>1][j][i>>(d-(d>>1))] && g[d-(d>>1)][j][i&((1<<(d-(d>>1)))-1)]){
				ans++;
				break;
			}
		}
	}
	printf("%lld", ans);
	return 0;
}

