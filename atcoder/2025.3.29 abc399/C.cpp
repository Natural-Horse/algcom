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

const int N = 2e5 + 5;

struct Ed{
    int u, v, nxt;
}ed[N << 1];
int n, m, hd[N], tot;
int fa[N];

void add_edge(int u, int v){
    ed[++tot].nxt = hd[u], hd[u] = tot;
    ed[tot].u = u, ed[tot].v = v;
}

int find(int x){
    if(fa[x] == x) return x;
    else return fa[x] = find(fa[x]);
}

void merge(int x, int y){
    int u = find(x), v = find(y);
    fa[u] = v;
}

int check(){
    int cnt = 0;
    for(int i = 1; i <= tot; i += 2){
        int u = ed[i].u, v = ed[i].v;
        if(find(u) != find(v)){
            merge(u, v);
            cnt++;
        }
    }
    return cnt;
}

// int solve(){
//     int l = 0, r = tot >> 1 + 1;
//     while(l < r){
//         int mid = (l + r) >> 1;
//         if(check(mid)) l = mid + 1;
//         else r = mid;
//     }
//     return l;
// }

int main(){
    n = read(), m = read();
    for(int i = 1; i <= n; i++) fa[i] = i;
    for(int i = 1, u, v; i <= m; i++){
        u = read(), v = read();
        add_edge(u, v), add_edge(v, u);
    }
    int ans = m - check();
    cout << ans;
}