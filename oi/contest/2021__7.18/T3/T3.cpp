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

const int N = 1e5 + 5;

struct Edge{
	int nxt, to, nw, gl;
}ed[N << 1];

int n;
int head[N], tot;

void add_edge(int u, int v, int w, int fab){
	ed[++tot].nxt = head[u], ed[tot].to = v, head[u] = tot;
	ed[tot].nw = w, ed[tot].gl = fab;
}

int pre[N], lk[N], anscnt, anslen;
bool up[N];

void dfs(int u, int fa){
	for(int i = head[u]; i; i = ed[i].nxt){
		int v = ed[i].to;
		if(v == fa) continue;
		if(ed[i].gl != ed[i].nw && ed[i].gl != 2){
			if(!up[fa]) anscnt++, anslen++, up[v] = true;
			else{
				anslen += 1 + lk[fa];
			}
		}
		else if(ed[i].gl == 2){
			up[v] = true;
			lk[v] = lk[u]++;
		}
		else{
			up[v] = false;
			lk[v] = 0;
		}
		dfs(v, u);
	}
}

int main(){
	n = read();
	bool check = true, fab = true;
	for(int i = 1, a, b, c, d; i < n; i++){
		a = read(), b = read(), c = read(), d = read();
		add_edge(a, b, c, d), add_edge(b, a, c, d);
		pre[a]++, pre[b]++;
		if(d != 2) check = false;
		if(pre[a] > 2 && pre[b] > 2) fab = false;
	}
	if(check){
		printf("0 0");
		return 0;
	}
	else if(fab){
		int st;
		for(int i = 1; i <= n; i++){
			if(pre[i] == 1){
				st = i;
				break;
			} 
		}
		dfs(st, 0);
		printf("%d %d", anscnt, anslen);
	}
	return 0;
}

