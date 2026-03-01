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
bool vis[Maxn], b[Maxn];
int len;

int spfa(){
	for(int i = 1; i <= n; i++){
		dis[i] = inf;
		cnt[i] = 0;
		vis[i] = false;
	}
	q.push(1);
	dis[1] = 0;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		vis[u] = false;
		for(int i = head[u]; i; i = ed[i].nxt){
			int v = ed[i].to;
			int w = ed[i].w;
			if(dis[v] > dis[u] + w){
				dis[v] = dis[u] + w;
				if(!vis[v]){
					vis[v] = true;
					q.push(v);
				}
			}
		}
	}
	return dis[n];
}

priority_queue<Node> p;

void dijkstra(){
	for(int i = 1; i <= n; i++){
		dis_[i] = inf;
		cnt[i] = 0;
		vis[i] = false;
	}
	dis_[n] = 0;
	p.push((Node){n, 0});
	while(!p.empty()){
		Node x = p.top();
		p.pop();
		int u = x.num;
		if(vis[u]) continue;
		vis[u] = true;
		for(int i = head_[u]; i; i = ed_[i].nxt){
			int v = ed_[i].to;
			int w = ed_[i].w;
			if(dis_[v] > dis_[u] + w){
				dis_[v] = dis_[u] + w;
				p.push((Node){v, dis_[v]});
			}
		}
	}
}

bool fab(){
	for(int i = 1; i <= n; i++){
		dis_[i] = inf;
		cnt[i] = 0;
		vis[i] = false;
	}
	q.push(1);
	dis_[1] = 0;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		vis[u] = false;
		cnt[u]++;
		if(cnt[u] > n) return false;
		for(int i = head[u]; i; i = ed[i].nxt){
			int v = ed[i].to;
			if(!b[v]) continue; 
			int w = ed[i].w;
			if(dis_[v] >= dis_[u] + w){
				dis_[v] = dis_[u] + w;
				if(!vis[v]){
					vis[v] = true;
					q.push(v);
				}
			}
		}
	}
	return true;
}

int ans;
int f[Maxn];

void dfs(int u, int d){
	for(int i = head_[u]; i; i = ed_[i].nxt){
		int v = ed_[i].to, w = ed_[i].w;
		if(dis[v] + w + dis_[u] > len + k) continue;
		
	}
}

int main(){
	scanf("%d", &T);
	for(int ii = 1; ii <= T; ii++){
		memset(head, 0, sizeof(head));
		memset(head_, 0, sizeof(head_));
		memset(b, true, sizeof(b));
		tot = tot_ = 0;
		scanf("%d %d %d %d", &n, &m, &k, &P);
		for(int i = 1, u, v, w; i <= m; i++){
			scanf("%d %d %d", &u, &v, &w);
			add_edge(u, v, w);
			add_edge_(v, u, w);
		}
		len = spfa();
		dijkstra();
		for(int i = 1; i <= n; i++){
			if(dis[i] + dis_[i] > len + k) b[i] = false;
		}
		if(!fab()){
			printf("-1");
			continue;
		}
		for(int i = 1; i <= n; i++) cnt[i] = 0;
		cnt[n] = 1;
		ans = 0;
		dfs(n, 0);
		printf("%d\n", ans % P);
	}
	return 0;
} 
