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
	int nxt, to, rev;
}ed[N << 1];

int n;
int head[N], tot;

void add_edge(int u, int v, int rev){
	ed[++tot].nxt = head[u], ed[tot].to = v;
	ed[tot].rev = rev;
	head[u] = tot;
}

pair<int, int> f[N][2];
pair<int,int> add(pair<int,int> aa, pair<int,int> bb){
	return make_pair(aa.first+bb.first, aa.second+bb.second);
}

void dfs(int u, int fa, int rev){
	pair<int,int> p = make_pair(0, 0), q = make_pair(inf, inf);
	for(int i = head[u]; i; i = ed[i].nxt){
		int v = ed[i].to, r = ed[i].rev;
		if(v == fa) continue;// p为不以u为终点, q为以u为终点 
		dfs(v, u, r);
		pair<int,int> juda = p, judb = q;
		p = min(add(f[v][0],juda), add(f[v][1],judb));
        q = min(add(f[v][1],juda), add(f[v][0],judb));
	}
	if(rev == 2){
		f[u][0] = min(p, make_pair(q.first+1, q.second));
		f[u][1] = min(make_pair(p.first+1, p.second+1), make_pair(q.first, q.second+1));
	}
	else if(rev == 1){
		f[u][0] = make_pair(inf, inf);
		f[u][1] = min(make_pair(p.first+1, p.second+1), make_pair(q.first, q.second+1));
	}
	else{
		f[u][0] = min(p, make_pair(q.first+1, q.second));
		f[u][1] = make_pair(inf, inf);
	}
}

int main(){
	n = read();
	for(int i = 1; i < n; i++){
		int a, b, c, d;
		a = read(), b = read(), c = read(), d = read();
		if(d == 2) add_edge(a, b, 2), add_edge(b, a, 2);
		else add_edge(a, b, c^d), add_edge(b, a, d^c);
	}
	dfs(1, 0, 2);
	printf("%d %d\n", f[1][0].first/2, f[1][0].second);
	return 0;
}

