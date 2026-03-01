#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

void solve() {
    ll s, k, m;
    if (!(cin >> s >> k >> m)) return;

    ll num_flips = m / k;
    ll fab;

    if (s <= k) {
        fab = s;
    } 
    else {
        if (num_flips % 2 == 0) {
            fab = s;
        } else {
            fab = k;
        }
    }

    ll rem = m % k;
    ll ans = max(0LL, fab - rem);
    // cout << "ans : "; 
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}