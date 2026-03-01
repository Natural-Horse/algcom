#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

const int Maxn = 1e5 + 5;
const int Maxm = 2e5 + 5;

struct Edge{
	int nxt, to, w;
}ed[Maxm], ed_[Maxm];

struct Node{
	int num, dist;
	bool operator < (const Node &x) const{
		return dist > x.dist;
	}
};

int T;
int n, m, k, P;
int head[Maxn], tot, head_[Maxn], tot_;
int pre[Maxn], dep[Maxn];

inline void add_edge(int u, int v, int w){
	ed[++tot].nxt = head[u];
	ed[tot].to = v;
	ed[tot].w = w;
	head[u] = tot;
}

inline void add_edge_(int u, int v, int w){
	ed_[++tot_].nxt = head_[u];
	ed_[tot_].to = v;
	ed_[tot_].w = w;
	head_[u] = tot_;
}

queue<int> q;
int dis[Maxn], cnt[Maxn], dis_[Maxn];
bool vis[Maxn], b[Maxn][55];
int len;
int Ans;
int f[Maxn][55];

priority_queue<Node> p;

void dijkstra(){
	for(int i = 1; i <= n; i++){
		dis[i] = inf;
		vis[i] = false;
	}
	dis[1] = 0;
	p.push((Node){1, 0});
	while(!p.empty()){
		Node x = p.top();
		p.pop();
		int u = x.num;
		if(vis[u]) continue;
		vis[u] = true;
		for(int i = head[u]; i; i = ed[i].nxt){
			int v = ed[i].to;
			int w = ed[i].w;
			if(dis[v] > dis[u] + w){
				dis[v] = dis[u] + w;
				p.push((Node){v, dis[v]});
			}
		}
	}
}

int dp(int u, int res){
	int ans = 0;
	if(res < 0 || res > k) return 0;
	if(b[u][res]){
		b[u][res] = false;
		return -1;
	}
	if(f[u][res] != -1) return f[u][res];
	b[u][res] = true;
	for(int i = head_[u]; i; i = ed_[i].nxt){
		int v = ed_[i].to, w = ed_[i].w;
		int jud = dp(v, dis[u] + res - dis[v] - w);
		if(jud == -1){
			b[u][res] = false;
			return -1;
		} 
		ans = (ans + jud) % P;
	}
	b[u][res] = false;
	if(u == 1 && res == 0) ans++;
	f[u][res] = ans;
	return f[u][res];
}

int main(){
	scanf("%d", &T);
	for(int ii = 1; ii <= T; ii++){
		memset(head, 0, sizeof(head));
		memset(head_, 0, sizeof(head_));
		memset(b, false, sizeof(b));
		memset(f, -1, sizeof(f));
		tot = tot_ = 0;
		scanf("%d %d %d %d", &n, &m, &k, &P);
		for(int i = 1, u, v, w; i <= m; i++){
			scanf("%d %d %d", &u, &v, &w);
			add_edge(u, v, w);
			add_edge_(v, u, w);
		}
		dijkstra();
		Ans = 0;
		for(int i = 0; i <= k; i++){
			int jud = dp(n, i);
			if(jud == -1){
				Ans = -1;
				break;
			}
			Ans = (Ans + jud) % P;
		}
		printf("%d\n", Ans % P);
	}
	return 0;
} 
