// clang-format off
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define long long
#define ll long long
#define ull unsigned long long
using namespace std;

inline ll read(){
    ll x = 0, f = 1; char ch = getchar();
    while(!isdigit(ch)){if(ch == '-') f = -1; ch = getchar();}
    while(isdigit(ch)){x = (x << 3) + (x << 1) + (ll)ch - 48; ch = getchar();}
    return x * f;
}

const int N = 1e5 + 5;

struct Edge{
    int v, nxt;
}ed[N << 1];
struct Nd{
    int id;
    int val;
    bool operator < (const Nd &b) const{
        return val < b.val;
    }
}nd[N];
int n, hd[N], tot, fa[N], ans;
ll a[N], b[N], c[N], maxh, et[N];
bool vis[N];
ll LIM = 1e9 + 7;

void add_edge(int u, int v){
    ed[++tot].nxt = hd[u];
    ed[tot].v = v, hd[u] = tot;
}

bool growth(ll st, ll re, int id){
    ll jud = 0;
    if(c[id] > 0){
        if(b[id]+c[id]*st > (LIM << 1)) return true;
        else if (b[id]+c[id]*re > (LIM << 1)) return true;
        else if(re - st + 1 > (LIM << 1)) return true;
        jud = ((b[id]+c[id]*st) + (b[id]+c[id]*re)) * (re - st + 1) >> 1;
    }
    else{
        if(et[id] > re){
            if(b[id]+c[id]*st > (LIM << 1)) return true;
            else if (b[id]+c[id]*re > (LIM << 1)) return true;
            else if(re - st + 1 > (LIM << 1)) return true;
            jud = ((b[id]+c[id]*st) + (b[id]+c[id]*re)) * (re - st + 1) >> 1;
        }
        else if(et[id] > st && et[id] <= re){
            if(b[id]+c[id]*st > (LIM << 1)) return true;
            else if (b[id]+c[id]*(et[id]-1) > (LIM << 1)) return true;
            else if(et[id] - st > (LIM << 1)) return true;
            jud = ((b[id]+c[id]*st) + (b[id]+c[id]*(et[id]-1))) * (et[id] - st) >> 1;
            jud += re - et[id] + 1;
        }
        else jud = re - st + 1;    
    }
    if(jud >= a[id]) return true;
    else return false;
}

void dfs(int u){
    for(int i = hd[u]; i; i = ed[i].nxt){
        int v = ed[i].v; if(fa[u] == v) continue;
        fa[v] = u;
        dfs(v);
    }
}

void dev(int u, int& T){
    int tmp = u;
    // top = 0;
    while(!vis[tmp]){
        T++;
        // s[[[t[++top] = tmp;
        vis[tmp] = true;
        if(tmp != 1 && fa[tmp] && !vis[fa[tmp]]) tmp = fa[tmp];
    }

}

bool check(int T){
    memset(vis, 0, sizeof(vis));
    if(!growth(1, T, 1)) return false;
    for(int i = 1; i <= n; i++){
        if(i == 1){nd[i] = {i, 1}; continue;}
        int l = 2, r = T;
        while(l < r){
            int mid = (l + r + 1) >> 1;
            if(growth(mid, T, i)) l = mid;
            else r = mid - 1;
        }
        if(!growth(l, T, i)) return false;
        nd[i] = {i, l};
    }
    sort(nd + 1, nd + 1 + n);
    int jud = 0;
    for(int i = 1; i <= n; i++){
        int pt = nd[i].id;
        dev(pt, jud);
        if(jud > T || jud > nd[i].val) return false;
    }
    return true;
}

void solve(){
    int l = 1, r = maxh;
    while(l < r){
        int mid = (l + r) >> 1;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }
    ans = l;
}

int main(){
    // freopen("P9755_2.in", "r", stdin);
    // freopen("ans.out", "w", stdout);
    n = read();
    for(int i = 1; i <= n; i++){
        a[i] = read(), b[i] = read(), c[i] = read();
        maxh = max(maxh, a[i]);
        maxh = min(maxh, LIM);
        if(c[i] < 0) et[i] = (b[i] / (-c[i])) + (b[i] % (-c[i]) != 0);
        else if(c[i] == 0) et[i] = inf;
        else et[i] = inf;
    }
    maxh += n;
    for(int i = 1, u, v; i < n; i++){
        u = read(), v = read();
        add_edge(u, v), add_edge(v, u); 
    }
    dfs(1);
    solve();
    cout << ans;
    return 0;
}