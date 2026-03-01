#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

const int N = 2e5 + 5;

void solve() {
    ll n = 0, ans = 0;
    cin >> n;
    vector<int> a(n + 1, 0);
    vector<vector<int>> dif(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (i > 1) dif[abs(a[i] - a[i-1]) + 1].push_back(i - 1);
        if (i < n) ans += i;
    }
    // cout << "1 : ";
    cout << ans << " ";
    // cout << endl;
    multiset<int> s;
    s.insert(0), s.insert(n);
    for (int i = 2; i < n; i++) {
        for (auto plc : dif[i]) {
            auto it = s.insert(plc);
            int las = *prev(it);
            int nxt = *next(it);
            ans -= (ll)(plc - las) * (ll)(nxt - plc);
        }
            // cout << i << " : ";
        cout << ans << " ";
        // cout << endl;
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int T = 0;
    cin >> T;
    while (T--) solve();
    return 0;
}