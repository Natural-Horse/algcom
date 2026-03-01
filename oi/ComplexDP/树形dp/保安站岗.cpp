#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
#define int long long
using namespace std;

inline int read(){
    int x = 0, f = 1; char ch = getchar();
    while(!isdigit(ch)){if(ch == '-') f = -1; ch = getchar();}
    while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - 48; ch = getchar();}
    return x * f;
}

const int N = 1505;

struct Edge{
    int nxt, to;
}ed[N << 1];
int n, a[N], f[N][3];
int head[N], tot;

void add_edge(int u, int v){
    ed[++tot].nxt = head[u]; ed[tot].to = v; head[u] = tot;
}

void dfs(int u, int fa){
    int check = false;
    f[u][1] = a[u];
    int cnt = 0, jud = inf, plc = 0;
    for(int i = head[u]; i; i = ed[i].nxt){
        int v = ed[i].to; if(v == fa) continue;
        check = true;
        dfs(v, u);
        f[u][1] += min(f[v][0], min(f[v][1], f[v][2]));
        f[u][2] += f[v][0];
        if(f[v][1] <= f[v][0]) cnt++;
        else if(cnt == 0 && f[v][1] - f[v][0] < jud) plc = v, jud = f[v][1] - f[v][0];
    }
    for(int i = head[u]; i; i = ed[i].nxt){
        int v = ed[i].to; if(v == fa) continue;
        if(v == plc && cnt == 0) f[u][0] += f[v][1];
        else f[u][0] += min(f[v][0], f[v][1]);
    }
    if(!check) f[u][0] = inf;
}

signed main(){
    n = read();
    for(int i = 1, u, k; i <= n; i++){
        u = read(), a[u] = read(), k = read();
        for(int j = 1, v; j <= k; j++){
            v = read();
            add_edge(u, v), add_edge(v, u);
        }
    }
    dfs(1, 0);
    printf("%lld", min(f[1][1], f[1][0]));
    return 0;
}
