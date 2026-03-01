#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

const int Maxn = 1e3+5;

struct Edge{
	int nxt, to, len;
}ed[Maxn * 2];

int T;
int n, m;
int head[Maxn], tot; 

void add_edge(int u, int v, int w){
	ed[++tot].nxt = head[u];
	ed[tot].to = v;
	ed[tot].len = w;
	head[u] = tot;
}

queue<int> q;
int dis[Maxn], cnt[Maxn];
bool b[Maxn];

bool SPFA(int st){
	for(int i = 0; i <= n; i++){
		cnt[i] = 0;
		dis[i] = inf;
	}
	dis[st] = 0;
	q.push(st);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		b[u] = true;
		if(++cnt[u] > n) return false;
		for(int i = head[u]; i; i = ed[i].nxt){
			int v = ed[i].to, w = ed[i].len;
			if(dis[v] > dis[u] + w){
				dis[v] = dis[u] + w;
				q.push(v);
			}
		}
	}
	return true;
}

int main(){
	scanf("%d", &T);
	for(int ii = 1; ii <= T; ii++){
		scanf("%d %d", &n, &m);
		tot = 0;
		memset(b, false, sizeof(b));
		memset(head, 0, sizeof(head));
		for(int i = 1; i <= m; i++){
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			u -= 1;
			add_edge(u, v, w);
			add_edge(v, u, -w);
		}
		bool jud = false;
		for(int i = 0; i <= n; i++){
			if(!b[i]){
				if(!SPFA(i)){
					printf("false\n");
					jud = true;
					break;	
				}
			}				
		}
		if(!jud) printf("true\n");
	}
	return 0;
}
