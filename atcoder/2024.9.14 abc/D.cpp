#include<bits/stdc++.h>
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

int n, q, tot;
ll pre[N<<1], mp[N];
pair<ll, ll> a[N];

int main(){
    n = read();
    for(int i = 1; i <= n; i++) a[i].first = read();
    for(int i = 1; i <= n; i++) a[i].second = read();
    q = read();
    sort(a + 1, a + 1 + n);
    for(int i = 1; i <= n; i++){
        pre[i] = pre[i-1] + a[i].second;
        mp[i] = a[i].first;
    }
    for(int i = 1; i <= q; i++){
        ll l, r;
        l = read(), r = read();
        ll plc1 = lower_bound(mp + 1, mp + 1 + n, l) - mp;
        ll plc2 = upper_bound(mp + 1, mp + 1 + n, r) - mp - 1;
        printf("%lld\n", pre[plc2] - pre[plc1-1]);
    }
    return 0;
}