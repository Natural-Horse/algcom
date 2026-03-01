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

const int N = 1e6 + 4;

struct Edge{
    int nxt, to, a, b;
}ed[N << 1];
int n, m, fa[N], top[N], siz[N], s[N], d[N], l[N], r[N], pre[N];
int head[N], tot, fr[N], to[N], cnt;
vector<int> st;

void add_edge(int u, int v, int a, int b){
    ed[++tot].nxt = head[u]; ed[tot].to = v, ed[tot].a = a, ed[tot].b = b; head[u] = tot;
}

void dfs1(int u, int f){
    fa[u] = f, d[u] = d[f] + 1, siz[u] = 1;
    for(int i = head[u]; i; i = ed[i].nxt){
        int v = ed[i].to;
        if(v == fa[u]) continue;
        l[v] = v, r[v] = v;
        if(ed[i].a) l[v] = l[u];
        if(ed[i].b) r[v] = r[u];
        dfs1(v, u);
        if(siz[s[u]] < siz[v]) s[u] = v;
        siz[u] += siz[v];
    }
}
void dfs2(int u, int Top){
    top[u] = Top;
    if(!s[u]) return;
    dfs2(s[u], Top);
    for(int i = head[u]; i; i = ed[i].nxt){
        int v = ed[i].to;
        if(v != s[u] && v != fa[u]) dfs2(v, v);
    }
}
int lca(int u, int v){
    while(top[u] != top[v]){
        if(d[u] < d[v]) swap(u, v);
        u = fa[top[u]];
    }
    if(d[u] > d[v]) swap(u, v);
    return u;
}

int main(){
    freopen("friendship.in", "r", stdin);
    freopen("friendship.out", "w", stdout);
    n = read(), m = read();
    for(int i = 1, op; i <= m; i++){
        op = read();
        if(!op){
            int fab = read(), k = read(); n++;
            for(int j = 1, v; j <= k; j++){
                v = read();
                if(k == 1) add_edge(n, v, 1, 1);
                else if(fab) add_edge(n, v, 0, 1);
                else add_edge(n, v, 1, 0);
                pre[v]++;
            }
        }
        else fr[++cnt] = read(), to[cnt] = read();
    }
    for(int i = 1; i <= n; i++){
        if(!pre[i]) st.push_back(i);
    }
    int sz = st.size();
    for(int i = 0; i < sz; i++){
       // printf("st:%d\n", st[i]);
        dfs1(st[i], 0); 
        dfs2(st[i], st[i]);
    }
    //for(int i = 1; i <= n; i++) printf("fab:%d %d %d %d\n", top[i], l[i], r[i], s[i]);
    for(int i = 1; i <= cnt; i++){
        int u = fr[i], v = to[i];
        int anc = lca(u, v);
       // printf("anc:%d\n", anc);
        if(!anc){printf("0\n"); continue;}
        if(u == anc){
            if(d[l[v]] <= d[anc]) printf("1\n");
            else printf("0\n");
        }
        else if(v == anc){
            if(d[r[u]] <= d[anc]) printf("1\n");
            else printf("0\n");
        }
        else printf("0\n");
    }
    return 0;
}
