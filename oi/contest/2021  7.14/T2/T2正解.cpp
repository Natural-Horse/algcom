#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

ll read(){
	ll x = 0,f = 1;char ch = getchar();
	while (ch < '0' || ch > '9'){if (ch == '-') f = -1; ch = getchar();}
	while (ch >= '0' && ch <= '9'){x = x*10 + ch - 48; ch = getchar();}
	return x * f;
}

//T2并查集:
/*把所有点按点权从大到小排序:使之后合并的时候,从大到小枚举每个点,并枚举每条
出边,如果出点点权大于等于当前点才能合并,这样就保证了所求出的直径中一定没有
比当前点点权更大的*/
/*合并的时候,求出的合并后该并查集里的直径不一定经过当前点:这种情况只存在于所
求出的最大直径就是合并前两个并查集中的某一条直径,而这条直径一定在求前面那个并
查集的时候就已经被处理过了;而且因为合并顺序是点权从大到小,第一次处理这条直径
的时候所乘的点权一定比之后再搞到这条直径的时候所用的点权大,点权*直径一定是前
后,所以不会对答案产生影响*/
/*如果合并后并查集的直径是由原先两个并查集的端点求距离推过来的:
因为每次合并操作中,合并的两个点一定是相邻的,而且原图满足树形结构,所以两个点所
属的并查集之间也有且只有一条边相连.所以如果新的直径的端点分别属于两个并查集
,那么这条直径一定经过合并的两个点,且整条直径肯定跑不到两个并查集外头.又因为
满足并查集里所有点的点权都大于等于当前枚举点,所以可以直接用这条直径乘当前点
点权更新答案*/
/*手模一下即可*/
const int N = 1e5 + 5;
struct Edge{int nxt, to;ll w;}ed[N << 1];
struct S{ll st, re, d;}s[N];
struct Node{ll id, w;}nd[N];
int n, T;
ll fa[N], f[N][30], dis[N], head[N], tot, lg[N], dep[N], w[N];
bool vis[N];
ll ans;

void init(){
	for(int i = 1; i <= N; i++){
		lg[i] = lg[i-1] + (i % (1 << lg[i-1]) == 0);
	}
}
void add_edge(int u, int v, ll w){
	ed[++tot].nxt = head[u];
	ed[tot].to = v, ed[tot].w = w;
	head[u] = tot;
}
bool cmp(Node aa, Node bb){
	return aa.w > bb.w;
}
void dfs(int u, int fa){
	f[u][0] = fa;
	dep[u] = dep[fa] + 1;
	for(int i = 1; i <= lg[dep[u]]; i++)
		f[u][i] = f[f[u][i-1]][i-1];
	for(int i = head[u]; i; i = ed[i].nxt){
		int v = ed[i].to;
		if(v == fa) continue;
		dis[v] = dis[u] + ed[i].w;
		dfs(v, u);
	}
}
int lca(int x, int y){
	if(dep[x] < dep[y]) swap(x, y);
	while(dep[x] > dep[y])
		x = f[x][lg[dep[x]-dep[y]]-1];
	if(x == y) return x;
	for(int i = lg[dep[x]] - 1; i >= 0; --i){
		if(f[x][i] != f[y][i])
			x = f[x][i], y = f[y][i];
	}
	return f[x][0];
}
int find(int x){
	if(fa[x] == x) return x;
	else return fa[x] = find(fa[x]);
}
void merge(int u, int v){
	u = find(u), v = find(v);
	if(u != v){
		fa[v] = u;
		S jud;
		s[u].d > s[v].d? jud = s[u]: jud = s[v];
		ll st1 = s[u].st, re1 = s[u].re, st2 = s[v].st, re2 = s[v].re;
		ll anc = lca(st1, st2);
		ll dist = dis[st1] + dis[st2] - (dis[anc] << 1);
		if(dist > jud.d) jud = (S){st1, st2, dist};
		anc = lca(st1, re2);
		dist = dis[st1] + dis[re2] - (dis[anc] << 1);
		if(dist > jud.d) jud = (S){st1, re2, dist};
		anc = lca(re1, st2);
		dist = dis[re1] + dis[st2] - (dis[anc] << 1);
		if(dist > jud.d) jud = (S){re1, st2, dist};
		anc = lca(re1, re2);
		dist = dis[re1] + dis[re2] - (dis[anc] << 1);
		if(dist > jud.d) jud = (S){re1, re2, dist};
		s[u] = jud;
	}
}

int main(){
	freopen("b.in", "r", stdin);
	T = read();
	init();
	for(int ii = 1; ii <= T; ii++){
		memset(head, 0, sizeof(head));	
		memset(vis, false, sizeof(vis));
		dis[1] = 0, dep[0] = 0;
		ans = 0, tot = 0;
		n = read();
		for(int i = 1; i <= n; i++){
			nd[i].id = i, nd[i].w = read();
			w[i] = nd[i].w, s[i] = {i, i, 0};
			fa[i] = i;
		}			
		for(int i = 1; i < n; i++){
			ll u, v, w;
			u = read(), v = read(), w = read();
			add_edge(u, v, w), add_edge(v, u, w);
		}
		dfs(1, 0);
		sort(nd + 1, nd + 1 + n, cmp);
		for(int i = 1; i <= n; i++){
			int u = nd[i].id;
			vis[u] = true;
			for(int i = head[u]; i; i = ed[i].nxt){
				int v = ed[i].to;
				if(!vis[v]) continue;			
				merge(u, v);				
			}
			ans = max(ans, s[u].d * w[u]);
		}
		printf("%lld\n", ans);
	}	
	return 0;
}
