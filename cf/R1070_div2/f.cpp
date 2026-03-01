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

const int N = 2e5 + 5, mod = 998244353;

int T, n, k, a[N], pm[N], tot, A;
ll omega[N], f[N][20], cnt[N][20], freq[N], ans;
bool b[N];

void Prime(){
    for(int i = 2; i <= N; i++){
        if(!b[i]) pm[++tot] = i, omega[i] = 1;
        for(int j = 1; j <= tot && i * pm[j] <= 200000; j++){
            b[i * pm[j]] = true;
            if(i % pm[j] == 0){
                omega[i * pm[j]] = omega[i];
                break;
            }
            else omega[i * pm[j]] = omega[i] + 1;
        }
    }
}

void reset(){
    for(int i = 1; i <= A; i++) freq[i] = 0;
    A = 0;
    ans = 0;
}

ll qp(ll aa, ll bb){
    ll res = 1, jud = aa;
    while(bb){
        if(bb & 1) res = (res * jud) % mod;
        jud = (jud * jud) % mod;
        bb >>= 1;
    }
    return res;
}

void solve(){
    for(int i = 1; i <= A; i++){
        for(int j = 0; j <= 15; j++) cnt[i][j] = f[i][j] = 0;

    }
    for(int i = 1; i <= A; i++){
        for(int j = i; j <= A; j += i){
            if(freq[j] > 0) cnt[i][omega[j]] += freq[j];
        }
    }
    for(int g = A; g; --g){
        for(int w = 0; w <= 15; w++){
            ll sum = 0, minus = 0;
            for(int l1 = 0; l1 <= (w >> 1); l1++){
                int l2 = w - l1;
                if(l1 < omega[g] || l2 < omega[g]) continue;
                if(l1 == l2) sum = (sum + (cnt[g][l1] * (cnt[g][l1] - 1) >> 1) % mod) % mod;
                else sum = (sum + (cnt[g][l1] * cnt[g][l2]) % mod) % mod;
            }
            for(int i = 2; i * g <= A; i++){
                minus = (minus + f[i * g][w]) % mod;
            }
            f[g][w] = (sum - minus + mod) % mod; 
            ans = (ans + (qp(w - omega[g], k) * f[g][w]) % mod) % mod;
        }
    }
}

signed main(){
    T = read();
    Prime();
    while(T--){
        n = read(), k = read();
        reset();
        for(int i = 1; i <= n; i++){
            a[i] = read();
            freq[a[i]]++;
            A = max(A, a[i]);
        }
        solve();
        // printf("ans : ");
        printf("%lld\n", ans);
    }
    // cout << tot << " " << pm[tot];
    return 0;
}