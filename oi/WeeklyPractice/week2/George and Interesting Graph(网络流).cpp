#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

const int Maxn = 10100;
const int Maxm = 250005;

struct Edge{
	int nxt, to, cap, from;
}ed[Maxm * 2];

struct Link{
	int from, to;	
}e[Maxm];

int n, m, s = 0, t = 2005;
int head[Maxn], tot = 1;
int rd[Maxn], cd[Maxn];
int ans, final = inf;

void add_edge(int u, int v, int w){
	ed[++tot].nxt = head[u];
	ed[tot].to = v;
	ed[tot].cap = w;
	head[u] = tot;
	ed[++tot].nxt = head[v];
	ed[tot].to = u;
	ed[tot].cap = 0;
	head[v] = tot;
}

queue<int> q;
int d[Maxn], now[Maxn];

bool bfs(){
	memset(d, 0, sizeof(d));
	while(!q.empty()) q.pop();
	q.push(s);
	d[s] = 1, now[s] = head[s];
	while(!q.empty()){
		int u = q.front(); q.pop();
		for(int i = head[u]; i; i = ed[i].nxt){
			int v = ed[i].to;
			if(ed[i].cap && !d[v]){
				d[v] = d[u] + 1;	
				q.push(v);
				now[v] = head[v];
				if(v == t) return true;
			}
		}
	}
	return false;
}

int dinic(int u, int flo){
	if(u == t) return flo;
	int res = flo, i, k;
	for(i = now[u]; i; i = ed[i].nxt){
		int v = ed[i].to;
		if(ed[i].cap && d[v] == d[u] + 1){
			k = dinic(v, min(res, ed[i].cap));
			if(!k) d[v] = 0;
			ed[i].cap -= k;
			ed[i ^ 1].cap += k;
			res -= k;
		}
	}
	now[u] = i;
	return flo - res;
}

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 1, u, v; i <= m; i++){
		scanf("%d %d", &u, &v);
		cd[u]++;
		rd[v]++;
		e[i].from = u, e[i].to = v;
		if(u == v) rd[v]--;
	}
	for(int i = 1; i <= n; i++){
		int suma = rd[i] + cd[i];
		ans = 0;
		memset(head, 0, sizeof(head));
		tot = 1;
		for(int j = 1; j <= n; j++){
			add_edge(s, j, 1);
			add_edge(j + n, t, 1);
		}
		for(int j = 1; j <= m; j++){
			if(e[j].from == i || e[j].to == i) continue;
			add_edge(e[j].from, e[j].to + n, 1);		
		}
		int flo = 0;
		while(bfs()){
			ans += dinic(s, inf);
		}
		final = min(final, n - 1 - ans + m - ans - suma + 2 * n - 1 - suma);
	}
	printf("%d", final);
	return 0;
}
