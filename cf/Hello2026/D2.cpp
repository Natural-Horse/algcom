#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2e5 + 5;

struct Ed{
    int v, nxt;
}ed[N << 1];
int n, tot, hd[N], fa[N], dep[N], col[N], mxdep, ans;
vector<int> lyr[N], res[N];

void add(int u, int v){
    ed[++tot] = {v, hd[u]};
    hd[u] = tot;
}

void dfs(int u, int f){
    fa[u] = f;
    dep[u] = dep[f] + 1;
    mxdep = max(mxdep, dep[u]);
    lyr[dep[u]].push_back(u);
    for(int i = hd[u]; i; i = ed[i].nxt){
        int v = ed[i].v;
        if(v != f) dfs(v, u);
    }
}

void solve(){
    cin >> n;
    tot = 0; ans = 0; mxdep = 0;
    for(int i = 0; i <= n; i++) {
        hd[i] = 0; lyr[i].clear(); res[i].clear();
    }
    for(int i = 1, u, v; i < n; i++){
        cin >> u >> v;
        add(u, v); add(v, u);
    }
    dfs(1, 0);
    ans = 1;
    for(int i = 2; i <= mxdep; i++){
        int sz = lyr[i].size();
        set<int> st;
        for(int u : lyr[i]) st.insert(fa[u]);
        if(st.size() == 1) ans = max(ans, sz + 1);
        else ans = max(ans, sz);
    }
    
    cout << ans << "\n";
    col[1] = 1;
    res[1].push_back(1);
    vector<pair<int, int>> nodes_sort; 
    for(int i = 2; i <= mxdep; i++){
        nodes_sort.clear();
        for(int u : lyr[i]) {
            nodes_sort.push_back({fa[u], u});
        }
        sort(nodes_sort.begin(), nodes_sort.end());
        struct Grp { int bc; vector<int> nds; };
        vector<Grp> groups;
        set<int> bad_set;
        if(!nodes_sort.empty()){
            int curr_p = nodes_sort[0].first;
            int curr_bc = col[curr_p];
            groups.push_back({curr_bc, {}});
            bad_set.insert(curr_bc);
            
            for(auto& p : nodes_sort){
                if(p.first != curr_p){
                    curr_p = p.first;
                    curr_bc = col[curr_p];
                    groups.push_back({curr_bc, {}});
                    bad_set.insert(curr_bc);
                }
                groups.back().nds.push_back(p.second);
            }
        }
        int m = groups.size();
        int node_count = lyr[i].size();
        int needed_free = node_count;
        if(m > 1) needed_free -= m;
        vector<int> my_free;
        int check_c = 1;
        while((int)my_free.size() < needed_free){
            if(bad_set.find(check_c) == bad_set.end()){
                my_free.push_back(check_c);
            }
            check_c++;
        }
        if(m == 1){
            int idx = 0;
            for(int u : groups[0].nds){
                int c = my_free[idx++];
                col[u] = c;
                res[c].push_back(u);
            }
        } 
        else {
            for(int j = 0; j < m; j++){
                int use_color = groups[j].bc; 
                int give_to_grp = (j + 1) % m;
                int u = groups[give_to_grp].nds.back();
                groups[give_to_grp].nds.pop_back();
                col[u] = use_color;
                res[use_color].push_back(u);
            }
            int f_idx = 0;
            for(int j = 0; j < m; j++){
                for(int u : groups[j].nds){
                    int c = my_free[f_idx++];
                    col[u] = c;
                    res[c].push_back(u);
                }
            }
        }
    }
    
    for(int i = 1; i <= ans; i++){
        cout << res[i].size();
        for(int u : res[i]) cout << " " << u;
        cout << "\n";
    }
}

int main(){
    ios::sync_with_stdio(false), cin.tie(0);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}
