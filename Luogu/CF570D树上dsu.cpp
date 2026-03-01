// clang-format off
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

inline int read(){
    int x = 0, f = 1; char ch = getchar();
    while(!isdigit(ch)){if(ch == '-') f = -1; ch = getchar();}
    while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - 48; ch = getchar();}
    return x * f;
}

const int N = 5e5 + 5;

struct{
    int nxt, v;
}ed[N << 1];
int n, m, c[N], fa[N], top[N], son[N], siz[N], d[N];
vector<int> qid[N], qd[N];
int hd[N], tot;
bool ans[N], vis[N];
int s[N];

void add_edge(int u, int v){
    ed[++tot].nxt = hd[u], ed[tot].v = v, hd[u] = tot;
}

void dfs1(int u){
    siz[u] = 1;
    for(int i = hd[u]; i; i = ed[i].nxt){
        int v = ed[i].v;
        d[v] = d[u] + 1;
        dfs1(v);
        siz[u] += siz[v];
        if(siz[v] > siz[son[u]]) son[u] = v;
    }
}

int calc(int stat){
    int res = 0;
    while(stat){res += stat & 1; stat >>= 1;}
    return res;
}

void update(int u){
    s[d[u]] ^= (1 << (c[u] - 'a'));
    for(int i = hd[u]; i; i = ed[i].nxt){
        int v = ed[i].v; if(vis[v]) continue;
        update(v);
    }
}

void dfs2(int u, bool is_son){
    if(son[u] != 0){
        for(int i = hd[u]; i; i = ed[i].nxt){
            int v = ed[i].v; if(v == son[u]) continue;
            dfs2(v, 0);
        }
        dfs2(son[u], 1);
        vis[son[u]] = 1, update(u), vis[son[u]] = 0;
    }
    else update(u);
    if(!qid[u].empty()){
        for(int i = 0; i < qid[u].size(); i++){
            int dep = qd[u][i];
            int cnt = calc(s[dep]);
            ans[qid[u][i]] = (cnt <= 1) ? true : false;
        }
    }
    
    if(!is_son) update(u);
}

int main(){
    n = read(), m = read();
    for(int i = 2; i <= n; i++) fa[i] = read(), add_edge(fa[i], i);
    for(int i = 1; i <= n; i++) c[i] = getchar();
    d[1] = 1;
    dfs1(1);
    for(int i = 1; i <= m; i++){
        int u = read(), dep = read();
        qid[u].push_back(i);
        qd[u].push_back(dep);
    }
    dfs2(1, 1);
    // for(int i = 1; i <= n; i++) printf("%c ", c[i]);
    // printf("\n");
    for(int i = 1; i <= m; i++){
        ans[i] ? printf("Yes\n") : printf("No\n");
    }
    return 0;
}