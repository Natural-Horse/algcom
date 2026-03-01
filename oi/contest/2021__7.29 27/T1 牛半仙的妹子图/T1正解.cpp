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
struct E{
	int u, v, w;
}e[N << 1];

int n, m, q, x, op, cnt = 1, c[N], cl;
ll M, las;
int fa[N], head[N], tot, t[1005];

bool cmp(E aa, E bb){
	return aa.w < bb.w;
}
int find(int x){
	if(fa[x] == x) return x;
	else return fa[x] = find(fa[x]);
}
void merge(int aa, int bb){fa[find(aa)]=find(bb);}
void add_edge(int u, int v, int w){
	ed[++tot].nxt = head[u], ed[tot].to = v, ed[tot].w = w, head[u] = tot;
}
void dfs(int u, int fa, int maxn){
	t[c[u]] = min(t[c[u]], maxn);
	for(int i = head[u]; i; i = ed[i].nxt){
		int v = ed[i].to;
		if(v == fa) continue;
		dfs(v, u, max(maxn, ed[i].w));
	}
}

int main(){
	n = read(), m = read(), q = read(), x = read(), op = read();
	if(op == 1) M = read();
	for(int i = 1; i <= n; i++) c[i] = read(), fa[i] = i, cl = max(cl, c[i]);
	for(int i = 1, u, v, w; i <= m; i++){
		u = read(), v = read(), w = read();
		e[++cnt] = (E){u, v, w};
	}
	sort(e + 1, e + 1 + cnt, cmp);
	int nn = n;
	for(int i = 1; i <= cnt && nn > 1; i++){
		if(find(e[i].u) != find(e[i].v)){
			merge(e[i].u, e[i].v);
			add_edge(e[i].u, e[i].v, e[i].w), add_edge(e[i].v, e[i].u, e[i].w);
			nn--;
		}
	}
	memset(t, 0x3f, sizeof(t));
	dfs(x, 0, 0);
	for(int i = 1, l, r; i <= q; i++){
		l = read(), r = read();
		if(op == 1) l = (l^las)	% M + 1, r = (r^las) % M + 1;
		if(l > r) swap(l, r);
		ll ans = 0;
		for(int i = 1; i <= cl; i++){
			if(t[i] <= l) ans += r - l + 1;
			else if(t[i] > l && t[i] <= r) ans += r + 1 - t[i];
		}
		las = ans;
		printf("%lld\n", ans);
	}
	return 0;
}
