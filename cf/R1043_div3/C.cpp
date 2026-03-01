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

const int N = 45;

ll n, T, ans, k;
ll dcnt[N], dtot, dmax, fab, dval[N];


ll qp(ll aa, ll bb){
    ll res = 1, jud = aa;
    while(bb){
        if(bb & 1) res *= jud;
        jud *= jud, bb >>= 1;
    }
    return res;
}

void reset(){
    dmax = dtot = 0;
    ans = 0;
    memset(dcnt, 0, sizeof dcnt);
}

void init(){
    ll stat = n, pt = 0;
    while(stat != 0){
        ll cur_val = qp(3, pt + 1);
        if(pt > 0) cur_val += pt * qp(3, pt - 1);
        ll cur_cnt = qp(3, pt);
        ll cur_need = stat % 3;
        dcnt[pt] = cur_need, dtot += cur_need;
        dval[pt] = cur_val;
        ans += cur_need * cur_val;
        if(cur_need != 0) dmax = max(dmax, pt);
        stat /= 3, pt++;
    }
}

void solve(){
    fab = (k - dtot) >> 1;
    if(dmax == 0) return;
    for(int i = dmax; i; i--){
        if(!dcnt[i]) continue;
        if(fab >= dcnt[i]){
            dcnt[i-1] += dcnt[i] * 3;
            fab -= dcnt[i];
            ans = ans - dval[i] * dcnt[i] + dval[i-1] * dcnt[i] * 3;
        }
        else {
            dcnt[i-1] += fab * 3;
            ans = ans - dval[i] * fab + dval[i-1] * fab * 3;
            fab = 0;
            break;
        }
    }
}

int main(){
    T = read();
    while(T--){
        n = read(), k = read();
        reset();
        init();
        if(dtot > k){printf("-1\n"); continue;}
        solve();
        printf("%lld\n", ans);
    }
    return 0;
}