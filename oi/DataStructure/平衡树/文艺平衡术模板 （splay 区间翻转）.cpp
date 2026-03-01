#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

int read(){
	int f = 1, x = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){if(ch == '-') f = -1; ch = getchar();}
	while(ch >='0' && ch <= '9'){x = x*10 + ch - 48; ch = getchar();}
	return f * x;
}

const int N = 1e5 + 5;

int n, m, root, num;
int fa[N], ch[N][2], siz[N], rev[N], val[N];

void push_back(int u){
	siz[u] = siz[ch[u][0]] + siz[ch[u][1]] + 1;
}

void push_down(int u){
	if(rev[u]){
		rev[ch[u][0]] ^= 1, rev[ch[u][1]] ^= 1;
		swap(ch[u][0], ch[u][1]);
	}
	rev[u] = 0;
}

void rotate(int u){
	int f = fa[u], g = fa[f];
	int d = (u == ch[f][1]), x = ch[u][d^1];
	if(g) ch[g][f==ch[g][1]] = u;
	fa[u] = g;
	ch[u][d^1] = f, fa[f] = u;
	ch[f][d] = x, fa[x] = f;
	push_back(f);
}

void splay(int u, int to){
	while(fa[u] != to){
		int f = fa[u], g = fa[f];
		if(g != to) 
			(ch[f][0] == u) ^ (ch[g][0] == f)? rotate(u): rotate(f);
		rotate(u);
	}
	push_back(u);
	if(!to) root = u;
}

void insert(int v){
	int u = root, f = 0;
	while(u){
		f = u, u = ch[u][v>val[u]];
	}
	u = ++num;
	if(f) ch[f][v>val[f]] = u;
	fa[u] = f, val[u] = v;
	if(fa[u] == 0) root = u;
	else splay(u, 0);
}

int find(int u, int rk){
	push_down(u);
	if(siz[ch[u][0]] + 1 == rk) return u;
	else if(siz[ch[u][0]] >= rk) find(ch[u][0], rk);
	else find(ch[u][1], rk - siz[ch[u][0]] - 1);
}

void rev_(int l, int r){
	int st = find(root, l), re = find(root, r+2);
	splay(st, 0);
	splay(re, root);
	rev[ch[re][0]] ^= 1;
	push_down(ch[re][0]);
	push_back(re), push_back(st);
}

void print(int u){
	push_down(u);
	if(val[u] > n+2 || val[u] <= 0) return;
	print(ch[u][0]);
	if(val[u]-1>=1 && val[u]-1<=n)printf("%d ", val[u]-1);
	print(ch[u][1]);
}

int main(){
	freopen("1", "w", stdout);
	n = read(), m = read();
	for(int i = 1; i <= n + 2; i++){
		insert(i);
	}
	for(int i = 1, st, re; i <= m; i++){
		st = read(), re = read();
		rev_(st, re);
	}
	print(root);
	return 0;
} 
