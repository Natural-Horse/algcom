#include <bits/stdc++.h>
#define inf 0x3f3f3f3f3f
#define ll long long
#define pll pair<ll, ll>
#define mkp make_pair
using namespace std;

inline int read(){
    int x = 0, f = 1; char ch = getchar();
    while(!isdigit(ch)){if(f == '-') f = -1; ch = getchar();}
    while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - 48; ch = getchar();}
    return x * f;
}

const int N = 2e5 + 5;

ll n, T, l, r;
ll ans;
map<ll, ll> mp;


void reset(){
    ans = 0;
    mp.clear();
}

pll iter(ll L, ll R, ll p){
    ll idx = log2(R) + 1;
    ll sum = (1 << idx) - 1;
    ll upbound = R, lobound = sum - R;
    
    if(lobound < L){
        lobound = L;
        upbound = sum - lobound;
    }

    ll pt = upbound;
    for(pt = upbound; pt >= lobound && sum - pt >= lobound; --pt){
        ll pr = sum - pt;
        mp[pt|p] = pr|p;
        ans += ((pt|p) | (pr|p));
    }
    if(upbound == R) return mkp(L, lobound - 1);
    else return mkp(upbound + 1, R);
}

void solve(){
    n = r - l + 1;

    ll L = l, R = r, p = 0;
    while(R >= L){
        if(L == R){
            mp[L|p] = (R|p);
            ans += (L|p);
            break;
        }
        if(R < L) break;
        while(((1 << ((ll)log2(R))) - 1) < L){
            p |= (1 << (ll)log2(R));
            ll mask = ~p;
            L &= mask, R &= mask;
        }

        pll ret = iter(L, R, p);
        // L = ret.first, R = ret.second;
        L = ret.first, R = ret.second;
        
        
    }
}


int main(){
    T = read();
    int count = T;
    while(T--){
        l = read(), r = read();
        reset();
        solve();
        printf("%lld\n", ans);
        for(int i = l; i <= r; i++){
            printf("%lld ", mp[i]);
        }
        printf("\n");
    }
    return 0;
}