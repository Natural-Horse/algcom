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

const int N = 2e6 + 5;

struct Edge{
    int nxt, to;
}ed[N << 1];
int n, top[N], s[N], siz[N], d[N], fa[N], rk[N], id[N], num, pre[N];
int head[N], tot, f[N], g[N];
ll ans;

void add_edge(int u, int v){
    ed[++tot].nxt = head[u]; ed[tot].to = v; head[u] = tot;
}

void dfs1(int u){
    d[u] = d[fa[u]] + 1;
    f[u] = u, g[u] = u;
    for(int i = head[u]; i; i = ed[i].nxt){
        int v = ed[i].to;
        dfs1(v);
        if(siz[v] > siz[s[u]]) s[u] = v;
        siz[u] += siz[v];
    }
}
void dfs2(int u, int Top){
    rk[u] = ++num, id[num] = u, top[u] = Top;
    if(s[u]) dfs2(s[u], Top);
    for(int i = head[u]; i; i = ed[i].nxt){
        int v = ed[i].to; if(v == s[u]) continue;
        dfs2(v, v);
    }
}
int lca(int x, int y){
    while(top[x] != top[y]){
        if(d[x] < d[y]) swap(x, y);
        x = fa[top[x]];
    }
    if(d[x] > d[y]) swap(x, y);
    return x;
}

void get(int u, int father, bool fab, int len){
    for(int i = head[u]; i; i = ed[i].nxt){
        int v = ed[i].to; if(v == father) continue;
        if(fab){
            if(v > father) len++;
            else{
                ans += (ll)len * (ll)(len-1) / 2;
                len = 2, fab = false;
            }
        }
        else{
            if(v < father) len++;
            else{
                ans += (ll) len * (ll)(len-1) / 2;
                len = 2, fab = true;
            }
        }
    }
}

int main(){
    freopen("charity.in", "r", stdin);
    freopen("charity.out", "w", stdout);
    n = read();
    for(int i = 1; i <= n; i++){
        fa[i] = read();
        if(fa[i] > 1) add_edge(fa[i], i), add_edge(i, fa[i]), pre[fa[i]]++, pre[i]++; 
    }
    bool check = true; int cnt = 0, st = 0;
    for(int i = 1; i <= n; i++){
        if(pre[i] == n - 1){
            ans = (ll)(i - 1) * (ll)(n - i);
            printf("%lld\n", ans);
            return 0;
        }
        if(pre[i] == 1) cnt++, st = i;
        if(pre[i] > 2) check = false;
    }
    if(check && cnt == 2){
        get(st, 0, true, 1);
        printf("%lld\n", ans);
    }
    return 0;
}

