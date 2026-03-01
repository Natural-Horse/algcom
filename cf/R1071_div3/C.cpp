#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

const int N = 1e5 + 5;

int T;

void solve(){
    ll n = 0, ans = 0;
    cin >> n;
    vector<ll> a(n, 0);
    for(int i = 1; i <= n; i++) cin >> a[i-1];
    sort(a.begin(), a.end());
    if(a[1] - a[0] >= a[0]) ans = a[1] - a[0];
    else ans = a[0];
    cout << "ans : ";
    cout << ans << endl;
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}