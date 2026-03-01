#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
#define pii pair<int, int>
#define mkp make_pair
using namespace std;

inline ll read(){
    ll x = 0, f = 1; char ch = getchar();
    while(!isdigit(ch)){if(ch == '-') f = -1; ch = getchar();}
    while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - 48; ch = getchar();}
    return x * f;
}

const int N = 2e5 + 5, mod = 998244353;

int T, n, m;
ll ans, a[N];
struct Ed{
    int u, v;
    ll val;
    bool operator < (const Ed& b) const{
        return val > b.val;
    }
}ed[N];

void reset(){ 
    ans = 0;
}
    

void solve(){
    sort(ed + 1, ed + 1 + m);
    vector<map<ll, int>> f(n + 1);
    for(int i = 1; i <= m; i++){
        int u = ed[i].u, v = ed[i].v;
        ll val = ed[i].val;
        f[u][a[v]] = (f[u][a[v]] + f[v][val] + 1) % mod;
        ans = (ans + f[v][val] + 1) % mod;
    }
}

signed main(){
    T = read();
    while(T--){
        n = read(), m = read();
        for(int i = 1; i <= n; i++) a[i] = read();
        reset();
        for(int i = 1, u, v; i <= m; i++){
            u = read(), v = read();
            ed[i] = (Ed){u, v, a[u] + a[v]};
        }
        solve();
        printf("%lld\n", ans);
    }
    return 0;
}