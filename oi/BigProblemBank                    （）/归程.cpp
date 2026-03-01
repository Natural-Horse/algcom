#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

const int Maxn = 4e5 + 5;
const int Maxm = 8e5 + 5;

struct Edge{
	int nxt, to;
	int w;
}ed[Maxm * 2], ed_[Maxm * 4];

struct Node{
	int from, dist;
	bool operator < (const Node &x)const{
		return dist > x.dist;
	}
};

struct E{
	int u, v, h;
}e[Maxn];

int T;
int n, m, Q, K, S;
int head[Maxn], tot, head_[Maxn * 2], tot_, tot__, cnt;
int st, le;
int dis[Maxn];
priority_queue<Node> q;
bool vis[Maxn];
int w[Maxn * 2], len[Maxn * 2], fa[Maxn * 2];
int dep[Maxn * 2];
int f[Maxn][25];

void add_edge(int u, int v, int w){
	ed[++tot].nxt = head[u];
	ed[tot].to = v, ed[tot].w = w;
	head[u] = tot;
}

void add_edge_(int u, int v){
	ed_[++tot_].nxt = head_[u];
	ed_[tot_].to = v;
	head_[u] = tot_;
}

void add_(int u, int v, int h){
	e[++tot__].u = u, e[tot__].v = v, e[tot__].h = h; 
}

void dijkstra(){
	for(int i = 1; i <= n; i++) dis[i] = inf, vis[i] = false;
	dis[1] = 0;
	q.push((Node){1, 0});
	while(!q.empty()){
		Node x = q.top();
		q.pop();
		int u = x.from;
		if(vis[u]) continue;
		vis[u] = true;
		for(int i = head[u]; i; i = ed[i].nxt){
			int v = ed[i].to;
			int w = ed[i].w;
			if(dis[v] > dis[u] + w){
				dis[v] = dis[u] + w;
				q.push((Node){v, dis[v]});
			}
		}
	}
	for(int i = 1; i <= n; i++) len[i] = dis[i];
}

bool cmp(E a, E b){
	return a.h > b.h;
}

int find(int x){
	if(fa[x] == x) return fa[x];
	else return fa[x] = find(fa[x]);
}

void merge(int u, int v, int h){
	int fx = find(u), fy = find(v);
	w[++cnt] = h;
	add_edge_(cnt, fx), add_edge_(fx, cnt);
	add_edge_(cnt, fy), add_edge_(fy, cnt);
	fa[fx] = fa[fy] = cnt;
}

void kruskal(){
	sort(e + 1, e + 1 + tot__, cmp);
	int jud = n;
	for(int i = 1; i <= tot__; i++){
		if(jud == 1) break;
		int u = e[i].u, v = e[i].v, h = e[i].h;
		if(find(u) != find(v)){
			merge(u, v, h);
			jud--;
		}	
	}
}

void dfs(int u, int father){
	f[u][0] = father;
	dep[u] = dep[father] + 1;
	for(int i = 1; i <= 19; i++) f[u][i] = f[f[u][i-1]][i-1];
	for(int i = head_[u]; i; i = ed_[i].nxt){
		int v = ed_[i].to;
		if(v == father) continue;
		dfs(v, u);
		len[u] = min(len[u], len[v]);
	}
}

int ST(int x, int lim){
	for(int i = 19; i >= 0; --i){
		if(dep[x] - (1 << i) > 0 && w[f[x][i]] > lim) x = f[x][i];		
	}
	return len[x];
}

void init(){
	memset(e, 0, sizeof(e));
	memset(head, 0, sizeof(head));
	memset(head_, 0, sizeof(head_));
	memset(dep, 0, sizeof(dep));
	memset(f, 0, sizeof(f));
	memset(w, 0, sizeof(w));
	for(int i = 1; i <= n * 2; i++) fa[i] = i, len[i] = inf;
	tot = tot_ = tot__ = 0;
	cnt = n;
}

int main(){
//	freopen("1", "w", stdout);
	scanf("%d", &T);
	for(int ii = 1; ii <= T; ii++){		
		int lastans = 0;		
		scanf("%d %d", &n, &m);
		init();
		for(int i = 1; i <= m; i++){
			int u, v, l, a;
			scanf("%d %d %d %d", &u, &v, &l, &a);
			add_edge(u, v, l);
			add_edge(v, u, l);
			add_(u, v, a);
		}
		dijkstra();
		kruskal();
		dfs(cnt, 0);
		scanf("%d %d %d", &Q, &K, &S);
		for(int iii = 1; iii <= Q; iii++){
			int V, P;
			scanf("%d %d", &V, &P);
			st = (V + K * lastans - 1) % n + 1;
			le = (P + K * lastans) % (S + 1);
			lastans = ST(st, le);
			printf("%d\n", lastans);
		}
	}
	return 0;
}
