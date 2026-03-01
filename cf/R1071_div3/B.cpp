#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

const int N = 1e5 + 5;

int T;

void solve(){
    ll n = 0, sum = 0;
    cin >> n;
    vector<ll> a(n + 2, 0);
    ll ans = inf;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        sum += (i-1>0)*abs(a[i] - a[i-1]);
    }
    ans = sum;
    for(int i = 1; i <= n; i++){
        ll jud = sum - (i-1>0)*abs(a[i] - a[i-1]) - (i+1<=n)*abs(a[i+1] - a[i]) + (i-1>0)*(i+1<=n)*abs(a[i+1] - a[i-1]);
        if(jud < ans){
            ans = jud;
        }
    }
    // cout << "ans : ";
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