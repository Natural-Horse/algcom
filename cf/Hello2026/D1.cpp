#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

const int N = 2e5 + 5;

struct Ed{
    int v, nxt;
}ed[N << 1];
int n, c[N], fa[N], tot, hd[N], dep[N], cnt[N], maxdep, ans;
vector<int> f[N];

void add_edge(int u, int v){
    ed[++tot].nxt = hd[u];
    ed[tot].v = v, hd[u] = tot;
}

void reset(){
    for(int i = 1; i <= n; i++) {
        cnt[i] = 0, hd[i] = 0, f[i].clear();
    }
    n = 0, tot = 0, maxdep = 0, ans = 0;
}

void dfs(int u, int father){
    fa[u] = father;
    dep[u] = dep[fa[u]] + 1;
    cnt[dep[u]]++;
    f[dep[u]].push_back(father);
    maxdep = max(maxdep, dep[u]);
    for(int i = hd[u]; i; i = ed[i].nxt){
        int v = ed[i].v; 
        if(v == father) continue;
        dfs(v, u);
    }
}

void solve(){
    reset();
    cin >> n;
    for(int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        add_edge(u, v), add_edge(v, u);
    }
    dfs(1, 0);
    ans = 1;
    for(int i = 2; i <= maxdep; i++) {
        sort(f[i].begin(), f[i].end());

        auto it = unique(f[i].begin(), f[i].end());

        int count = it - f[i].begin();
        if (count == 1) {
            ans = max(ans, cnt[i] + 1);
        }
        else {
            ans = max(ans, cnt[i]);
        }
    }
    // cout << "ans : ";
    cout << ans << endl;
}


int main(){
    // freopen("D_ans.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 0; cin >> t;
    while(t--) solve();
    return 0;
}