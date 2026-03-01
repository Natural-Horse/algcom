#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

map<int, int> mp;

int dfs(int u, int dep, int des, int ver){
    if (mp[u] == ver) return inf;
    mp[u] = ver;
    if (u == des) {
        return dep;
    }
    int ansa = dfs(u >> 1, dep + 1, des, ver);
    int ansb = dfs((u + 1) >> 1, dep + 1, des, ver);
    return min(ansa, ansb);
}

void solve(int ver){
    int n = 0, k = 0;
    cin >> n >> k;
    // cout << "ans : ";
    int ans = dfs(n, 0, k, ver);
    if(ans == inf) ans = -1;
    // cout << "ans : ";
    cout << ans << endl;
}


int main(){
    ios::sync_with_stdio(false), cin.tie(0);
    int T = 0;
    cin >> T;
    for(int i = 1; i <= T; i++){
        solve(i);
    }
    return 0;
}