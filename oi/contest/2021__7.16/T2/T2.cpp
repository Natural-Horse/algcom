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

const int N = 5e4 + 5;

int n, m, T;
ll lw[N], hi[N], l[N], r[N], s[N], k[N], all;
ll ans, ss, tt;

struct Edge{
	int nxt, to;
	ll cap;
}ed[N << 2];

int head[N<<1], tot = 1, now[N<<1], d[N<<1];
queue<int> q;

void add_edge(int u, int v, int w){
	ed[++tot].nxt = head[u], ed[tot].to = v, ed[tot].cap = w, head[u] = tot;
}

bool bfs(){
	memset(d, 0, sizeof(d));
	while(!q.empty()) q.pop();
	q.push(ss);
	now[ss] = head[ss], d[ss] = 1;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int i = head[u]; i; i = ed[i].nxt){
			int v = ed[i].to;
			if(ed[i].cap && !d[v]){
				q.push(v);
				now[v] = head[v];
				d[v] = d[u] + 1;
				if(v == tt) return true;
			}
		}
	}
	return false;
}

ll dinic(int u, ll flo){
	if(u == tt) return flo;
	ll res = flo, k, i;
	for(i = now[u]; i && res; i = ed[i].nxt){
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
//	freopen("machine2.in", "r", stdin);
//	freopen("fab", "w", stdout);
	T = read();
	for(int ii = 1; ii <= T; ii++){
		ans = 0, all = 0;
		n = read(), m = read();
		for(int i = 1; i <= n; i++) lw[i] = read(), hi[i] = read(), s[i] = read(), all += s[i];
		for(int i = 1; i <= m; i++) l[i] = read(), r[i] = read(), k[i] = read();
		if(n == 1){
			for(int i = 1; i <= m; i++){
				if(l[i] <= lw[1] && r[i] >= hi[1]) ans += k[i];
			}
		}
		else if(n <= 2000 && m <= 2000){
			memset(head, 0, sizeof(head));
			tot = 1;
			ss = n + m + 1, tt = n + m + 2;
			for(int i = 1; i <= n; i++){
				add_edge(ss, i, s[i]), add_edge(i, ss, 0);
				for(int j = 1; j <= m; j++){
					if(i == 1) add_edge(tt, j+n, 0), add_edge(j+n, tt, k[j]);
					if(l[j] <= lw[i] && r[j] >= hi[i]) add_edge(i, j+n, inf), add_edge(j+n, i, 0);
				}
			}
			ll flo = 0;
			while(bfs()){
				while(flo = dinic(ss, inf)) ans += flo;
			}
		}
		if(ans >= all) printf("Yes\n");
		else printf("No\n");
	}
	return 0;

}

