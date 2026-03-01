#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
    ll n, m, k;
    cin >> n >> m >> k;
    ll max_left = k - 1;
    ll max_right = n - k;
    ll ans = 1; 
    ll lim = max(max_left, max_right);
    for(ll M = 1; M <= lim; ++M) {
        if (2 * M - 1 > m) break;

        ll budget = m - 2 * M + 1;

        if (M <= max_right) {
            ll L = min({M, max_left, budget});
            ans = max(ans, L + M + 1);
        }
        if (M <= max_left) {
            ll R = min({M, max_right, budget});
            ans = max(ans, R + M + 1);
        }
    }
    // cout << "ans : ";
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}