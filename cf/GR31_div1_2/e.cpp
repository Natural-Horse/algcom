#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

const int N = 1e5 + 5;

int T;

void solve(){
    ll l, r;
    cin >> l >> r;
    if(l == r){
        cout << 0 << endl;
        return;
    }

    ll lb = __builtin_ctzll(l);
    ll rb = __builtin_ctzll(~r);
    ll ans = 0;
    if (lb < rb) ans = (1LL << lb);
    else ans = (1LL << rb);

    ll xor_val = l ^ r;
    int msb_idx = 63 - __builtin_clzll(xor_val);
    
    ll mask = (1LL << (msb_idx + 1)) - 1;
    
    l &= mask;
    r &= mask;

    if (l + r == mask && l > 0) {
        ans *= 2;
    }

    ans--; // 排除 x=0
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false), cin.tie(0);
    cin >> T;
    while(T--) solve();
}
