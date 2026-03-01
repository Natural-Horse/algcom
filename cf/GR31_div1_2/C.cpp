#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
#define int long long
using namespace std;

inline ll read(){
    ll x = 0, f = 1; char ch = getchar();
    while(!isdigit(ch)){if(ch == '-') f = -1; ch = getchar();}
    while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - 48; ch = getchar();}
    return x * f;
}

const int N = 1e6 + 5;

ll T, n, k, cnt[N], pt, ans[N];


void reset(){
    pt = 0;
    for(int i = 1; i <= 35; i++) cnt[i] = 0;
    if(k >= 1) ans[k] = 0;
    if(k >= 2) ans[k-1] = 0;
}

void solve(){
    if(k & 1){
        for(int i = 1; i <= k; i++) ans[i] = n;
    }
    else{
        for(int i = 1; i <= k - 2; i++) ans[i] = n;
        ll tmp_n = n;
        while(tmp_n){
            cnt[++pt] = (tmp_n & 1);
            tmp_n >>= 1;
        }
        int plc = 0;
        
        for(int i = pt - 1; i; --i){
            if(cnt[i]){plc = i; break;}
        }

        for(int i = pt; i > plc; --i){
            ans[k-1] += cnt[i] * (1LL << (i - 1));
        }
        for(int i = plc; i; --i){
            ans[k-1] += (cnt[i] ^ 1) * (1LL << (i - 1));
            ans[k] += (1LL << (i-1));
        }
    }
}

signed main(){
    T = read();
    while(T--){
        n = read(), k = read();
        reset();
        solve();
        for(int i = 1; i <= k; i++){
            printf("%lld ", ans[i]);
        }
        printf("\n");
    }
    return 0;
}