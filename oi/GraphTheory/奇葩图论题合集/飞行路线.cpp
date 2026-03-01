#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

const int Maxn = 1e6 + 5;
const int Maxm = 2e6 + 5;

struct Edge{
	int nxt, to, w;
}ed[Maxm * 2];

struct Node{
	int from, dist;
	bool operator < (const Node &x)const{
		return dist > x.dist;
	}
};

int n, m, k;
int s, t;

int head[Maxn], tot;

void add_edge(int u, int v, int w){
	ed[++tot].nxt = head[u];
	ed[tot].to = v;
	ed[tot].w = w;
	head[u] = tot;
}

priority_queue<Node> q;
int dis[Maxn];
bool vis[Maxn];

void dijkstra(){
	for(int i = 0; i <= n * (k + 1) - 1; i++) dis[i] = inf;
	dis[s] = 0;
	q.push((Node){s, 0});
	while(!q.empty()){
		Node x = q.top();
		q.pop();
		int u = x.from;
		for(int i = head[u]; i; i = ed[i].nxt){
			int v = ed[i].to;
			int w = ed[i].w;
			if(dis[v] > dis[u] + w){
				dis[v] = dis[u] + w;
				q.push((Node){v, dis[v]});
			}
		}
	}
}

int main(){
	scanf("%d %d %d", &n, &m, &k);
	scanf("%d %d", &s, &t);
	for(int i = 1, u, v, w; i <= m; i++){
		scanf("%d %d %d", &u, &v, &w);
		for(int j = 0; j <= k; j++){
			add_edge(u + j * n, v + j * n, w);
			add_edge(v + j * n, u + j * n, w);
			if(j != k){
				add_edge(u + j * n, v + (j+1) * n, 0);
				add_edge(v + j * n, u + (j+1) * n, 0);
			} 
		}
	}
	dijkstra();
	int ans = inf;
	for(int i = 0; i <= k; i++){
		ans = min(ans, dis[t+i*n]);
	}
	printf("%d", ans);
	return 0;
}
