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
const int N = 1e5 + 5, M = 3e5 + 5;
struct Edge{int nxt, to;}ed[M<<1];
int n, m;
int val[N], fa[N], ch[N][2], r[N], xr[N], head[N], tot, root;

inline void add_edge(int u, int v){ed[++tot].nxt=head[u];ed[tot].to=v;head[u]=tot;}
inline bool Nr(int u){return ch[fa[u]][0]==u || ch[fa[u]][1]==u;}

inline void push_down(int u){
	if(r[u]){swap(ch[u][0],ch[u][1]);r[ch[u][0]]^=1,r[ch[u][1]]^=1;r[u]=0;}
}
inline void push_back(int u){xr[u]=xr[ch[u][0]]^xr[ch[u][1]]^val[u];}
inline void rotate(int u){
	int f = fa[u], g = fa[f];
	push_down(g), push_down(f);
	int d = ch[f][1] == u, x = ch[u][d^1];
	fa[u] = g, ch[g][f==ch[g][1]] = u;
	fa[f] = u, ch[u][d^1] = f, ch[f][d] = x;
	push_back(f);
}
inline void splay(int u){
	push_down(u);
	while(Nr(u)){
		int f = fa[u], g = fa[f];
		if(Nr(f)) (ch[g][1]==f) ^ (ch[f][1]==u)? rotate(u): rotate(f);
		rotate(u);
	}
	if(!fa[u]) root = u;
	else push_back(u);
}
inline void rev(int u){r[u] ^= 1;push_down(u);}
inline void access(int u){
	int v;
	while(fa[u]){
		splay(u);
		v = u;
		u = fa[u];
		ch[u][1] = v;
	}
}
inline void makeroot(int u){
	access(u);
	splay(u);
	rev(u);
}
inline int findroot(int u){
	access(u), splay(u);
	while(ch[u][0]) push_down(u), u = ch[u][0];
	splay(u);
	return u;
}
inline void link(int u, int v){
	makeroot(u);
	if(findroot(v) != u) fa[u] = v;
}
inline void split(int u, int v){
	makeroot(u);
	access(v);
	splay(v);
}
inline void cut(int u, int v){split(u,v);fa[u]=ch[v][0]=0;push_back(v);}
int main(){
	n = read(), m = read();
	for(int i = 1; i <= n; i++) val[i] = read();
	for(int i = 1, op, u, v; i <= m; i++){
		op = read(), u = read(), v = read();
		if(op == 0){split(u, v); printf("%d\n", xr[v]);}
		if(op == 1){link(u, v);}
		if(op == 2){cut(u, v);}
		if(op == 3){splay(u); val[u] = v;}
	}
	return 0;
}
