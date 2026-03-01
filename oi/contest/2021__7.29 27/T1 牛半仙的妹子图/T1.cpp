#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

int read(){
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9'){if(ch == '-') f = -1; ch = getchar();}
	while (ch >= '0' && ch <= '9'){x = x*10 + ch - 48; ch = getchar();}
	return x * f;
}

const int N = 5e5 + 5;

struct Edge{
	int nxt, to, w;
}ed[N << 1];

int n, m, q, x, op, las, ans, maxn, minn = inf;
ll M;
int c[N], head[N], tot, l[N], r[N], f[N], b[1005];

void add_edge(int u, int v, int w){
	ed[++tot].nxt = head[u]; ed[tot].to = v, ed[tot].w = w;head[u] = tot;
}

void dfs(int u, int fa, int lim){
	if(!b[c[u]]) b[c[u]] = true, f[lim]++;
	for(int i = head[u]; i; i = ed[i].nxt){
		int v = ed[i].to;
		if(v == fa || ed[i].w > lim) continue;
		dfs(v, u, lim);
	}
}

int main(){
	n = read(), m = read(), q = read(), x = read(), op = read();
	if(op == 1) M = read();
	for(int i = 1; i <= n; i++) c[i] = read();
	for(int i = 1, u, v, w; i <= m; i++){
		u = read(), v = read(), w = read();
		add_edge(u, v, w), add_edge(v, u, w);
	}
	bool check = true;
	for(int i = 1; i <= q; i++){
		l[i] = read(), r[i] = read();
		maxn = max(maxn, r[i]), minn = min(minn, l[i]);
		if(l[i] != r[i]) check = false;
	}
	for(int i = minn; i <= maxn; i++){
		memset(b, false, sizeof(b));
		dfs(x, 0, i);
	}
	for(int i = 1; i <= q; i++){
		ans = 0;
		for(int j = l[i]; j <= r[i]; j++){
			ans += f[j];
		}
		printf("%d\n", ans);
	}
	return 0;
}

