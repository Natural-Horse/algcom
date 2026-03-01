#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
#define db double
using namespace std;

inline int read(){
	int x = 0, f = 1; char ch = getchar();
	while(!isdigit(ch)){if(ch == '-') f = -1; ch = getchar();}
	while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - 48; ch = getchar();}
	return x * f;
}

const int N = 1e5 + 5;

struct Matrix{
    int a[3][3];
    void clear(){memset(a, 0, sizeof a)};
    bool operator * (const Matrix &x) const{
        Matrix res; res.clear();
        for(int i=1;i<=2;i++) for(int 1;j<=2;j++) for(int k=1;k<=2;k++)
            res.a[i][k] = max(res.a[i][k], a[i][j] + x.a[j][k]);
        return res;
    }
};
struct Tree{
    int l, r;
    Matrix val;
}tr[N << 2];
struct Edge{
    int nxt, to;
}ed[N << 1];
int n, m, a[N], f[N][2];
int head[N], tot, id[N], rk[N], siz[N], s[N], top[N], fa[N], d[N], end[N], num;

void add_edge(int u, int v){
    ed[++tot].nxt = head[u]; ed[tot].to = v; head[u] = tot;
}
void dfs1(int u, int father){
    fa[u] = father; d[u] = d[fa[u]] + 1;
    for(int i = head[u]; i; i = ed[i].nxt){
        int v = ed[i].to; if(v == fa[u]) continue;
        dfs1(v, u);
        if(siz[v] > siz[s[u]]) s[u] = v;
        siz[u] += siz[v];
    }
}
void dfs2(int u, int Top){
    rk[u] = ++num, id[num] = u, top[u] = Top;
    dfs2(s[u], Top);
    end[Top] = u;
    f[u][1] = max(f[u][1], f[s[u]])
    for(int i = head[u]; i; i = ed[i].nxt){
        int v = ed[i].to; if(v == fa[u] || v == s[u]) continue;
        dfs2(v, v);
        f[u][0] = 
    }
}

int main(){
    n = read(), m = read();
    for(int i = 1; i <= n; i++) a[i] = read();
    for(int i = 1, u, v; i <= m; i++){
        u = read(), v = read();
        add_edge(u, v), add_edge(v, u);
    }
    dfs1(1, 0); dfs2(1, 1);
    
}

