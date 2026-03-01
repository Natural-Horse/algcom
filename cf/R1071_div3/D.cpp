#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

const int N = 1e5 + 5;

int T;

void solve(){
    ll n = 0, ans = 0;
    cin >> n;
    vector<ll> a;
    ll x = 1, x_max = 0, y_max = 0;
    for(x = 1; x <= n; x++){
        ll y = ((x * (x+1)) >> 1) * (1 << (n-x));
        // for(ll j = x; j; --j){
        //     y += j * (1LL << (n - x));
        // }
        if(y > y_max) y_max = y, x_max = x;
    }
    vector<bool> b((1 << n), false);
    for(int i = x_max; i > 0; --i){
        for(int j = (1 << i) - 1; j < (1 << n); j += (1 << x_max)) 
            a.push_back(j), b[j] = true;
    }
    // for(int i = (1 << x_max) - 1; i < (1 << n); i++) a.push_back(i), b[i] = true;
    // int jud = ((1 << x_max) - 1) >> 1;
    // while(jud){
    //     a.push_back(jud);
    //     b[jud] = true;
    //     jud >>= 1;
    // }
    for(int i = 0; i < (1 << n); i++){
        if(!b[i]) a.push_back(i);
    }
    // cout << "ans : ";
    for(int i = 0; i < (1 << n); i++){
        cout << a[i] << " ";
    }
    cout << endl;
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