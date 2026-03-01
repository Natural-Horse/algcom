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

int tot, son[N][2], fa[N], rt;
ll c[N], w[N], val[N], cost[N]; 

inline void New(ll W, ll C, int f){
	w[++tot] = val[tot] = W, c[tot] = cost[tot] = C, fa[tot] = f;
	return;
}

inline void rotate(int u){
	int x = fa[u], y = fa[x], k = son[x][1] == u;
	ll p = val[u], q = cost[u];
	val[u] += val[x] - val[u], val[x] += val[son[u][k]] - p;
	cost[u] += cost[x] - cost[u], cost[x] += cost[son[u][k]] - q;
	fa[u] = y, son[y][son[y][1]==x] = u;
	son[x][k] = son[u][k^1], fa[son[u][k^1]] = x;
	son[u][k^1] = x, fa[x] = y;
}

inline void splay(int u, int to){
	int v = fa[fa[u]];
	if(u == to) return;
	while(fa[u] != to){
		if(fa[u] == to) rotate(u);
		else if((son[v][0]==fa[u]) == (son[fa[u]][0]==u)) rotate(fa[u]), rotate(u);
		else rotate(u), rotate(u);
	}
	rotate(u);
	if(!fa[u]) rt = u;
}

inline int find(int u, ll C){
	if(C == c[u]) return u;
	else if(C < c[u] && son[u][0]) return find(son[u][0], C);
	else if(C > c[u] && son[u][1]) return find(son[u][1], C);
	else return 0;
}

void Insert(int u, ll W, ll C){
	if(!rt) New(W, C, u), rt = tot;
	else if(C < c[u]){
		if(!son[u][0]){
			New(W, C, u), son[u][0] = tot;
			splay(tot, rt);
		} 
		else Insert(son[u][0], W, C);
	}
	else if(C > c[u]){
		if(!son[u][1]){
			New(W, C, u), son[u][1] = tot; 
			splay(tot, rt);
		}  
		else Insert(son[u][1], W, C);
	}
}

inline int find_min(int u){
	int pos = u;
	while(son[u][0]) u = son[u][0];
	splay(pos, u);
	return pos;
}

inline int find_max(int u){
	int pos = u;
	while(son[u][1]) u = son[u][1];
	splay(pos, u);
	return pos;
}

inline void del(int u){
	if((!son[u][0]) && (!son[u][1])) rt = 0;
	else if(!son[u][0]) rt = son[u][1], fa[son[u][1]] = 0;
	else if(!son[u][1]) rt = son[u][0], fa[son[u][0]] = 0;
	else{
		int v = find_max(son[u][0]);
		son[v][1] = son[u][1], fa[son[u][1]] = v;
		val[v] += val[son[u][1]], cost[v] += cost[son[u][1]];
		rt = v;
	}
	return;
}

int main(){
	int op = read();
	while(op != -1){
		if(op == 1){
			ll W = read(), C = read();
			if(!find(rt, C)){
				Insert(rt, W, C);	
			} 
		}
		else if(op == 2 && rt){
			int u = find_max(rt);
			del(u);
		}
		else if(op == 3 && rt){
			int u = find_min(rt);
			del(u);
		}
		op = read();
	}
	printf("%lld %lld\n", val[rt], cost[rt]);
	return 0;
}

