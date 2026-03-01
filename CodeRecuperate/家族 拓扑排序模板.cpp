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
int n, tot, hd[N], pre[N];
queue<int> q;

void add_edge(int u, int v){
	ed[++tot].u = u, ed[tot].v = v;
	ed[tot].nxt = hd[u], hd[u] = tot;
	pre[v]++;
}

void topo_sort(){
	for(int i = 1; i <= n; i++){
		if(!pre[i]) {
			printf("%d ", i);
			q.push(i);
		}
	}
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int i = hd[u]; i; i = ed[i].nxt){
			int v = ed[i].v;
			pre[v]--;
			if(!pre[v]){
				printf("%d ", v);
				q.push(v);
			}
		}
	}
}

int main(){
	n = read();
	for(int i = 1; i <= n; i++){
		int j = read();
		while(j) add_edge(i,j), j = read();
	}
	topo_sort();
	return 0;
}

