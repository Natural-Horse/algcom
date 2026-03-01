#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
#define pii pair<int, int>
#define mkp make_pair
using namespace std;

inline ll read(){
    ll x = 0, f = 1; char ch = getchar();
    while(!isdigit(ch)){if(ch == '-') f = -1; ch = getchar();}
    while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - 48; ch = getchar();}
    return x * f;
}

const int N = 2e5 + 5, mod = 998244353, nmax = 2e5;

ll n, T, a[N], ans, fac[N], pre[N], inv[N];

void reset(){
    for(int i = 1; i <= n; i++) pre[i] = 0;
}

ll qp(ll aa, ll bb){
    ll res = 1, jud = aa;
    while(bb){
        if(bb & 1) res = res * jud % mod;
        jud = jud * jud % mod, bb >>= 1;
    }
    return res;
}

void prework(){
    fac[0] = 1;
    fac[1] = 1;
    inv[0] = 1;
    for(int i = 2; i <= nmax; i++) fac[i] = (fac[i-1] * i) % mod;
    inv[nmax] = qp(fac[nmax], mod - 2);
    for(int i = nmax - 1; i; --i) inv[i] = inv[i + 1] * (i + 1) % mod;
}

ll C(ll aa, ll bb){
    return (fac[aa] * inv[aa - bb] % mod) * inv[bb] % mod;
}

ll solve(){
    for(int i = n / 2 + 1 + (n & 1); i <= n; i++) 
        if(a[i] != 0) return 0;
    ll res = 1;
    if(a[1] < 2) return 0;
    for(int i = n / 2 + (n & 1); i; --i){
        
        ll rem = ((n & 1) + 2 * ((n / 2) + 1 - i) - pre[i + 1]) % mod;

        if(i == 1){
            if(rem < 2) return 0;
            res = res * C(rem - 2, a[i] - 2);
            if(rem != a[i]) return 0;
        }
        else{
            pre[i] = (pre[i + 1] + a[i]) % mod;
            if(rem < a[i]) return 0;
            res = res * C(rem, a[i]) % mod;
        }
        
    }
    return (res + mod) % mod;
}


int main(){
    T = read();
    int count = T;
    prework();
    while(T--){
        n = read();
        for(int i = 1; i <= n; i++) a[i] = read();
        reset();
        ans = solve();
        // printf("Test %lld : ", count - T);
        // printf("Test %lld : ", count - T);
        printf("%lld\n", ans);
    }
    return 0;
}