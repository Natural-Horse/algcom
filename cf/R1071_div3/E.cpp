#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    int n;
    ll x, y;
    cin >> n >> x >> y;
    string s;
    cin >> s;
    vector<ll> p(n);
    for (int i = 0; i < n; ++i) cin >> p[i];

    ll min_x = 0, min_y = 0;
    bool has_A = false, has_B = false;

    for (int i = 0; i < n; ++i) {
        ll req_a, req_b;
        if (s[i] == '0') { // A wins
            has_A = true;
            // b = floor((p-1)/2), a = p - b
            req_b = (p[i] - 1) / 2;
            req_a = p[i] - req_b;
        } else { // B wins
            has_B = true;
            req_a = (p[i] - 1) / 2;
            req_b = p[i] - req_a;
        }
        min_x += req_a;
        min_y += req_b;
    }

    if (x < min_x || y < min_y) {
        cout << "NO" << endl;
        return;
    }

    if (!has_A) { // All B wins
        if (y < x + n) cout << "NO" << endl;
        else cout << "YES" << endl;
    } else if (!has_B) { // All A wins
        if (x < y + n) cout << "NO" << endl;
        else cout << "YES" << endl;
    } else {
        cout << "YES" << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}