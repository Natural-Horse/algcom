#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;
const int M = 3005;

vector<int> d[M];

void init() {
    for (int i = 1; i < M; i++) {
        for (int j = 1; j * j <= i; j++) {
            if (i % j == 0) {
                d[i].push_back(j);
                if (j * j != i) d[i].push_back(i / j);
            }
        }
    }
}

void solve() {
    int n, m;
    if (!(cin >> n >> m)) return;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    if (a[0] > 1) {
        cout << 0 << endl;
        return;
    }
    vector<int> f(m + 1, 0);
    f[1] = 1;
    for (int i = 0; i < n - 1; i++) {
        vector<int> newf(m + 1, 0);
        int l = 1, r = m;
        if (a[i] != 0) l = r = a[i];
        for (int val = l; val <= r; val++) {
            if (!f[val]) continue;
            long long cur = f[val];
            for (int tmp : d[val]) {
                int newval = val + tmp;
                if (newval > m) continue;
                if (a[i+1] != 0 && a[i+1] != newval) continue;
                newf[newval] = (newf[newval] + cur) % mod;
            }
        }
        f = newf;
    }
    long long ans = 0;
    for (int v = 1; v <= m; v++) {
        ans = (ans + f[v]) % mod;
    }
    // cout << "ans : ";
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); 
    init(); 
    int t; 
    if (cin >> t) { 
        while (t--) solve(); 
    } 
    return 0; 
}