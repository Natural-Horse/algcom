#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

const int Maxm = 5005;
const int Maxn = 205;

struct Edge{
	int nxt, to;
	ll cap;
}ed[Maxm * 2];

int n, m, s, t;
int head[Maxn], tot = 1;

void add_edge(int u, int v, ll w){
	ed[++tot].nxt = head[u];
	ed[tot].to = v;
	ed[tot].cap = w;
	head[u] = tot;
}

int d[Maxn], now[Maxn];
queue<int> q;
ll ans;

bool bfs(){
	memset(d, 0, sizeof(d));
	while(!q.empty()) q.pop();
	q.push(s);
	now[s] = head[s], d[s] = 1;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int i = head[u]; i; i = ed[i].nxt){
			int v = ed[i].to;
			if(ed[i].cap && !d[v]){
				q.push(v);
				now[v] = head[v];
				d[v] = d[u] + 1;
				if(v == t) return true;
			}
		}
	}
	return false;
}

ll dinic(int u, ll flo){
	if(u == t) return flo;
	ll rs = flo, k, i;
	for(i = now[u]; i && rs; i = ed[i].nxt){
		int v = ed[i].to;
		if(ed[i].cap && d[v] == d[u] + 1){
			k = dinic(v, min(rs, ed[i].cap));
			if(!k) d[v] = 0;
			ed[i].cap -= k;
			ed[i ^ 1].cap += k;
			rs -= k;
		}
	} 
	now[u] = i;
	return flo - rs;
}

signed main(){
	scanf("%d %d %d %d", &n, &m, &s, &t);
	for(int i = 1; i <= m; i++){
		int u, v, w;
		scanf("%d %d %lld", &u, &v, &w);
		add_edge(u, v, w);
		add_edge(v, u, 0);
	}
	ll flo = 0;
	while(bfs()){
		while(flo = dinic(s, inf)) ans += flo;
	}
	printf("%lld", ans);
	return 0;
} 
