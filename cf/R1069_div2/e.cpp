#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long 
using namespace std;

const int N = 1e5 + 5;

int T;

ll qp(ll aa, ll bb, ll mod){
    ll res = 1, jud = aa % mod;
    while (bb) {
        if (bb & 1) res = (res * jud) % mod;
        jud = (jud * jud) % mod, bb >>= 1;
    }
    return res;
}
ll inv(ll aa, ll mod){
    return qp(aa, mod - 2, mod);
}

void solve(){
    ll n, m, mod;
    cin >> n >> m >> mod;
    ll part_1 = 0, part_2 = 0;
    
    for(int i = 1; i <= n; i++) {
        for(int j = i; j <= n; j++) {
            part_1 = (part_1 + inv(qp(m, (j-i+1)>>1, mod), mod)) % mod;
        }
    }
    part_1 = (part_1 * part_1) % mod;

    vector<ll> P(n + 1);
    P[0] = 1; 
    ll inv_m = inv(m, mod);
    for(int k = 1; k <= n; k++) P[k] = (P[k-1] * inv_m) % mod;

    for(int i = 1; i <= n; i++) {
        int max_k = min(i - 1, (int)n - i);
        ll sum_p = 0; 
        for(int k = 0; k <= max_k; k++) {
            ll p_k = P[k];
            ll term = (p_k - p_k * p_k) % mod;
            ll cross = (2 * k * p_k) % mod; 
            cross = (cross - 2 * p_k * sum_p) % mod;
            
            part_2 = (part_2 + term + cross) % mod;
            sum_p = (sum_p + p_k) % mod;
        }
    }

    for(int i = 1; i < n; i++) {
        int max_k = min(i, (int)n - i);
        ll sum_p = 0;
        for(int k = 1; k <= max_k; k++) {
            ll p_k = P[k];
            ll term = (p_k - p_k * p_k) % mod;
            ll cross = (2 * (k - 1) * p_k) % mod;
            cross = (cross - 2 * p_k * sum_p) % mod;
            
            part_2 = (part_2 + term + cross) % mod;
            sum_p = (sum_p + p_k) % mod;
        }
    }

    ll ans = (part_1 + part_2 % mod + mod) % mod;
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false), cin.tie(0);
    cin >> T;
    while(T--) solve();
    return 0;
}