#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

const int N = 2e5 + 5;

struct Ed{
    int v, nxt;
}ed[N << 1];
int n, hd[N], tot, f[N][2][3];

void add_edge(int u, int v){
    ed[++tot].nxt = hd[u], ed[tot].v = v;
    hd[u] = tot;
}

void clear(){
    tot = 0;
    for (int i = 1; i <= n; i++) {
        hd[i] = 0;
        f[i][0][0] = f[i][0][1] = f[i][0][2] = f[i][1][0] = f[i][1][1] = f[i][1][2] = 0;
    }
}

void dp(int u, int fa){
    int g[3] = {1, 0, 0};
    int cnt = 0;
    for(int i = hd[u]; i; i = ed[i].nxt){
        int v = ed[i].v;
        if (v == fa) continue;
        cnt++;
        dp(v, u);
        int g_v[3][3] = {{0, 0, 0},{0, 0, 0},{0, 0, 0}};
        if (f[v][1][0]) {
            g_v[0][0] = g[0], g_v[0][1] = g[1], g_v[0][2] = g[2];
        }
        if (f[v][1][1]) {
            g_v[1][0] = g[2], g_v[1][1] = g[0], g_v[1][2] = g[1];
        }
        if (f[v][1][2]) {
            g_v[2][0] = g[1], g_v[2][1] = g[2], g_v[2][2] = g[0];
        }
        g[0] = g_v[0][0] | g_v[1][0] | g_v[2][0];
        g[1] = g_v[0][1] | g_v[1][1] | g_v[2][1];
        g[2] = g_v[0][2] | g_v[1][2] | g_v[2][2];
    }
    
    f[u][0][0] = 1; 
    if (!cnt) {
        f[u][1][1] = 1;
    } else {
        f[u][1][0] = g[0];
        f[u][1][1] = g[1] | 1; 
        f[u][1][2] = g[2];
    }
}

void solve() {
    cin >> n;
    clear(); 
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        add_edge(u, v), add_edge(v, u);
    }
    dp(1, 0);
    if (f[1][1][0]) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int T = 0;
    cin >> T;
    while (T--) solve();
    return 0;
}