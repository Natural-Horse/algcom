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

const int N = 1e6 + 5, P = 1e5 + 5;

struct Edge{
    int nxt, to;
}ed[P << 1];
int n, m, k, s, b[N], h[5], cnt, st[N], re[N];
int head[N], tot, tmp[N], all;
char a[N];
bool vis[N];
queue<int> q;

void add_edge(int u, int v){
    ed[++tot].nxt = head[u]; ed[tot].to = v; head[u] = tot;
}

void bfs(){
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int i = 1; i <= 4; i++){
            if(u + h[i] <= n*m && u + h[i] > 0){
                int v = u + h[i];
                if(a[v] == '#' || b[v]) continue;
                if(u % m == 1 && v % m == 0) continue;
                if(u % m == 0 && v % m == 1) continue;
                b[v] = cnt; q.push(v);
            }
        }
    }
}
bool dfs(int u, int plc){
    bool res = false;
    if(u == plc) return true;
    vis[u] = true;
    tmp[++all] = u;
    for(int i = head[u]; i; i = ed[i].nxt){
        int v = ed[i].to; if(vis[v]) continue;
        if(dfs(v, plc)) return true;
    }
    return res;
}

int main(){
    freopen("treasure.in", "r", stdin);
    freopen("treasure.out", "w", stdout);
    n = read(), m = read(), k = read(), s = read();
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++) scanf("%c", &a[(i-1)*m+j]);
        scanf("\n");
    } 
    h[1] = -1, h[2] = -m, h[3] = 1, h[4] = m;
    cnt = 0;
    for(int i = 1; i <= n*m; i++){
        if(!b[i] && a[i] == '.'){
            b[i] = ++cnt;
            q.push(i); 
            bfs();
        }
    }
//    for(int i = 1; i <= n; i++){
//        for(int j = 1; j <= m; j++) printf("%d ", b[(i-1)*m+j]);
//        printf("\n");
//    } 
    for(int i = 1, xa, ya, xb, yb; i <= k; i++){
        xa = read(), ya = read(), xb = read(), yb = read();
        int u = (xa-1)*m+ya, v = (xb-1)*m+yb;
        if(b[u] != b[v]) add_edge(b[u], b[v]);
    }
    
    for(int i = 1, xa, ya, xb, yb; i <= s; i++){
        xa = read(), ya = read(), xb = read(), yb = read();
        int u = (xa-1)*m+ya, v = (xb-1)*m+yb;
        if(b[u] == b[v]){printf("1\n"); continue;}
        else{
            int ans = dfs(b[u], b[v]) ? 1 : 0;
            printf("%d\n", ans);
            for(int j = 1; j <= all; j++) vis[tmp[j]] = false;
            all = 0;
        }
    }
    return 0;
}

