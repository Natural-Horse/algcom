#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

inline ll read(){
    ll x = 0, f = 1; char ch = getchar();
    while(!isdigit(ch)){if(ch == '-') f = -1; ch = getchar();}
    while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - 48; ch = getchar();}
    return x * f;
}


ll n, T;
vector<ll> ans;

ll qp(ll aa, ll bb){
    ll res = 1, jud = aa;
    while(bb){
        if(bb & 1) res *= jud;
        jud *= jud, bb >>= 1;
    }
    return res;
}

void solve(){
    ll stat = n, pt = 1;
    while(stat){
        ll div = qp(10, pt) + 1;
        if(n % div == 0) ans.push_back(n / div);
        stat >>= 1, pt++;
    }
}

int main(){
    T = read();
    while(T--){
        n = read();
        ans.clear();
        solve();
        if(ans.empty()){printf("0\n"); continue;}
        // printf("ans : ");
        reverse(ans.begin(), ans.end());
        printf("%lu\n", ans.size());
        for(auto ans_s : ans){
            printf("%lld ", ans_s);
        }
        printf("\n");
    }
    return 0;
}