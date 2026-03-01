#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

ll c[35][35];

const ll mod = 1e9 + 7;
ll fac[40], inv[40];

ll qpow(ll a, ll b) {
    ll res = 1;
    a %= mod;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void mod_init() {
    fac[0] = 1;
    for (int i = 1; i <= 35; i++) fac[i] = fac[i - 1] * i % mod;
    inv[35] = qpow(fac[35], mod - 2);
    for (int i = 34; i >= 0; i--) inv[i] = inv[i + 1] * (i + 1) % mod;
}

ll C_mod(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fac[n] * inv[k] % mod * inv[n - k] % mod;
}

void init() {
    for (int i = 0; i <= 32; i++) {
        c[i][0] = 1;
        for (int j = 1; j <= i; j++)
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
    }
}

void solve() {
    ll n, k;
    cin >> n >> k;
    int d = 0;
    ll temp = n;
    while (temp > 1) {
        temp >>= 1;
        d++;
    }
    ll fab = 0;
    for (int i = 0; i < d; i++) {
        int max_ones = (int)k - i - 1;
        if (max_ones < 0) continue;
        for (int j = 0; j <= min((int)i, max_ones); j++) {
            fab += c[i][j];
        }
    }
    if (d + 1 <= k) fab++;
    cout << n - fab << endl;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    init();
    mod_init();

    cout << "Comparison for C(30, 15):" << endl;
    cout << "Pascal triangle (Actual): " << c[30][15] << endl;
    cout << "Factorial with Modulo:    " << C_mod(30, 15) << endl;
    cout << "--------------------------" << endl;

    int T = 0;
    cin >> T;
    while (T--) solve();
    return 0;
}
    ll fab1 = 1, fab2 = 1, fab3 = 1;
    for (int i = 1; i <= )
    return 0;
}