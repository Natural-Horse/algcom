#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

struct State {
    long long cost;
    int last_index;
    
    bool operator<(const State& other) const {
        if (cost != other.cost) return cost < other.cost;
        return last_index < other.last_index;
    }
};

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1); 
    vector<vector<int>> pos(k + 1);
    
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        for (int v = 1; v <= min(a[i], k); v++) {
            pos[v].push_back(i);
        }
    }

    vector<vector<State>> dp(k + 1, vector<State>(k + 1, {INF, n + 1}));

    dp[0][0] = {0, 0};

    long long max_happiness = 0;

    for (int c = 0; c <= k; c++) {
        for (int v = 0; v <= c; v++) {
            if (dp[c][v].cost == INF) continue;
   
            long long current_happiness = (long long)(n + 1) * v - dp[c][v].cost;
            max_happiness = max(max_happiness, current_happiness);

            int max_possible_next = k - c;
            
            for (int v_next = v + 1; v_next <= max_possible_next; v_next++) {
                const vector<int>& candidates = pos[v_next];
                auto it = upper_bound(candidates.begin(), candidates.end(), dp[c][v].last_index);
                
                if (it != candidates.end()) {
                    int idx_next = *it;
                    long long new_cost = dp[c][v].cost + (long long)idx_next * (v_next - v);
                    
                    State new_state = {new_cost, idx_next};
                    if (new_state < dp[c + v_next][v_next]) {
                        dp[c + v_next][v_next] = new_state;
                    }
                }
            }
        }
    }

    cout << max_happiness << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}