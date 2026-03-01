#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

int read(){
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9'){if(ch == '-') f = -1; ch = getchar();}
	while (ch >= '0' && ch <= '9'){x = x*10 + ch - 48; ch = getchar();}
	return x * f;
}

const int N = 1e5 + 5;

struct Edge{
	int nxt, to;
}ed[N << 1];
struct Tree{
	int l, r;
	bool gc, sta;
}tr[N << 2];

int n, m;
int head[N], tot, fa[N], top[N], id[N], rk[N], num, siz[N], s[N];
vector<int> c, cc;
bool b[N];

void add_edge(int u, int v){
	ed[++tot].nxt = head[u], ed[tot].to = v, head[u] = tot;
}

void dfs1(int u, int father){
	siz[u] = 1, fa[u] = father;
	for(int i = head[u]; i; i = ed[i].nxt){
		int v = ed[i].to;
		if(v == father) continue;
		dfs1(v, u);
		if(siz[v] > siz[s[u]]) s[u] = v;
		siz[u] += siz[v];
	}
}
void dfs2(int u, int Top){
	id[u] = ++num, rk[num] = u, top[u] = Top;
	if(s[u] != 0) dfs2(s[u], Top);
	for(int i = head[u]; i; i = ed[i].nxt){
		int v = ed[i].to;
		if(v == fa[u] || v == s[u]) continue;
		dfs2(v, v);
	}
}
void build(int u, int l, int r){
	tr[u].l = l, tr[u].r = r;
	if(l != r){
		int na = u << 1, nb = na | 1, mid = (l + r) >> 1;
		build(na, l, mid), build(nb, mid + 1, r);
	}
}
void push_down(int u){
	int na = u << 1, nb = na | 1;
	if(tr[u].gc){
		tr[na].gc = true, tr[nb].gc = true;
		if(tr[na].l == tr[na].r) tr[na].sta = false;
		if(tr[nb].l == tr[nb].r) tr[nb].sta = false;
		tr[u].gc = false;
	}
}
void op_dev(int u, int plc){
	int l = tr[u].l, r = tr[u].r;
	if(l > plc || r < plc) return;
	if(l == plc && r == plc){
		tr[u].sta = true;
		return;
	} 
	if(l != r){
		push_down(u);
		op_dev(u<<1, plc), op_dev(u<<1|1, plc);
	}
}
bool query_ign(int u, int plc){
	int l = tr[u].l, r = tr[u].r;
	if(l > plc || r < plc) return false;
	if(l == plc && r == plc) return tr[u].sta;
	if(l != r){
		push_down(u);
		return query_ign(u<<1, plc) | query_ign(u<<1|1, plc);
	}
}

int main(){
	n = read(), m = read();
	for(int i = 1, u, v; i < n; i++){
		u = read(), v = read();
		add_edge(u, v), add_edge(v, u);
	}
	for(int i = 1, op, plc; i <= m; i++){
		op = read();plc = read();
		if(op != 2){
			for(int j = 0; j < c.size(); j++) cc.push_back(c[j]);
			c.clear();
			for(int j = 0; j < cc.size(); j++){
				b[cc[j]] = true;
				for(int k = head[cc[j]]; k; k = ed[k].nxt) c.push_back(ed[k].to);
			}
			cc.clear();
		}
		else{
			c.clear();cc.clear();
			for(int j = 1; j <= n; j++) b[j] = false;
		}
		if(op == 1){;
			b[plc] = true;
			for(int j = head[plc]; j; j = ed[j].nxt) c.push_back(ed[j].to);
		}
		else if(op == 3){
			if(b[plc]) printf("wrxcsd\n");
			else printf("orzFsYo\n");
		}
	}
	return 0;
}
