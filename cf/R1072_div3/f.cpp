#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
vector<int> adj[N];
bool dp[N][3];

void dfs(int u, int p) {
    bool is_leaf = true;
    bool current_possible[3] = {true, false, false}; // 初始合并子树的和为0

    for (int v : adj[u]) {
        if (v == p) continue;
        is_leaf = false;
        dfs(v, u);

        bool next_possible[3] = {false, false, false};
        for (int r1 = 0; r1 < 3; ++r1) {
            if (!current_possible[r1]) continue;
            for (int r2 = 0; r2 < 3; ++r2) {
                if (dp[v][r2]) {
                    next_possible[(r1 + r2) % 3] = true;
                }
            }
        }
        memcpy(current_possible, next_possible, sizeof(next_possible));
    }

    if (is_leaf) {
        // 叶子节点：必须摇晃自己（作为起点）
        dp[u][0] = false;
        dp[u][1] = true;
        dp[u][2] = false;
    } else {
        // 非叶子节点：
        // 1. 不摇 $u$，用子树合并的结果
        for (int r = 0; r < 3; ++r) dp[u][r] = current_possible[r];
        // 2. 摇 $u$ 本身，产生 1 次摇晃并覆盖子树所有叶子
        dp[u][1] = true;
    }
}

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) adj[i].clear();
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);

    if (dp[1][0]) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}