#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

inline int read(){
	int x = 0, f = 1; char ch = getchar();
	while(!isdigit(ch)){if(ch == '-') f = -1; ch = getchar();}
	while(isdigit(ch)){x = (x << 1) + (x << 3) + ch - 48; ch = getchar();}
	return x * f;
}

const int N = 1e5 + 5;

struct Ed{
	int u, v, nxt;
}ed[N];
int t, n, m, tot, hd[N], pre[N], cnt, ans[N];
priority_queue<int, vector<int>, less<int> > q;
bool b;

void add_edge(int u, int v){
	ed[++tot].v = v, ed[tot].u = u;
	ed[tot].nxt = hd[u], hd[u] = tot;
	pre[v]++;
}

void topo_sort(){
	for(int i = 1; i <= n; i++){
		if(!pre[i]){
//			b = true;
			q.push(i);
		}
	}
//	if(!b) return;
	while(!q.empty()){
		int u = q.top(); q.pop();
//		printf("%d ", u);
		ans[++cnt] = u;
		for(int i = hd[u]; i; i = ed[i].nxt){
			int v = ed[i].v;
			pre[v]--;
			if(!pre[v]){
				q.push(v);
//				printf("%d ", v);
			}
		}
	}
}

int main(){
	t = read();
	while(t--){
		n = read(), m = read();
		tot = 0, cnt = 0;
		memset(pre, 0, sizeof pre);
		memset(hd, 0, sizeof hd);
		for(int i = 1, u, v; i <= m; i++){
			u = read(), v = read();
			add_edge(v, u);
		}
//		printf("matianrandasabi\n");
		topo_sort();
		if(cnt != n){printf("Impossible!");}
		else for(int i = cnt; i; i--) printf("%d ", ans[i]);
		printf("\n");
	}
	return 0;
}

