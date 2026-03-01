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

const int N = 2e5 + 5;

ll n, m, q, T, a[N], b[N], prea[N], preb[N];
ll lsa[N], lsb[N], tota, totb, ans;

void reset(){
    tota = totb = 0;   
}

void pre_work(){
    sort(lsa + 1, lsa + 1 + tota);
    tota = unique(lsa + 1, lsa + 1 + tota) - lsa - 1;
    sort(lsb + 1, lsb + 1 + totb);
    totb = unique(lsb + 1, lsb + 1 + totb) - lsb - 1;

    sort(a + 1, a + 1 + n, greater());
    sort(b + 1, b + 1 + m, greater());
    for(int i = 1; i <= n; i++){
        prea[i] = prea[i-1] + a[i];
    }
    for(int i = 1; i <= m; i++){
        preb[i] = preb[i-1] + b[i];
    }
}

bool check1(ll x, ll pta, ll ptb){
    return a[pta - x + 1] < b[ptb + x];
}
bool check2(ll x, ll pta, ll ptb){
    return a[pta + x] > b[ptb - x + 1];
}

void solve(ll x, ll y, ll z){
    ll pta = 0, ptb = 0;
    ans = 0;
    if(x >= y){
        if(z > x){
            pta = x, ptb = z - x;
            ans = prea[pta] + preb[ptb];
        } 
        else{
            pta = z, ptb = 0;
            ans = prea[pta] + preb[ptb];
        }
        ll l = 0, r = min(pta, y - ptb), mid = 0;
        while(l < r){
            mid = (l + r + 1) >> 1;
            if(check1(mid, pta, ptb)) l = mid;
            else r = mid - 1;
        }
        pta = pta - l, ptb = ptb + l;
        ans = prea[pta] + preb[ptb];
    }
    else{
        if(z > y){
            ptb = y, pta = z - y;
            ans = prea[pta] + preb[ptb];
        } 
        else{
            ptb = z, pta = 0;
            ans = prea[pta] + preb[ptb];
        }
        ll l = 0, r = min(ptb, x - pta), mid = 0;
        while(l < r){
            mid = (l + r + 1) >> 1;
            if(check2(mid, pta, ptb)) l = mid;
            else r = mid - 1;
        }
        ptb = ptb - l, pta = pta + l;
        ans = prea[pta] + preb[ptb];
    }
    return;
}

int main(){
    // freopen("E.out", "w", stdout);
    T = read();
    // init();
    while(T--){
        reset();
        n = read(), m = read(), q = read();
        for(int i = 1; i <= n; i++){
            a[i] = read();
            lsa[++tota] = a[i];
        }
        for(int i = 1; i <= m; i++){
            b[i] = read();
            lsb[++totb] = b[i];
        }

        pre_work();

        for(int i = 1, x, y, z; i <= q; i++){
            x = read(), y = read(), z = read();
            solve(x, y, z);
            printf("%lld\n", ans);
        }
    }
    return 0;
}