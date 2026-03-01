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

const int N = 1e5 + 5;

int n;
ll l, r, c, a[N], b[N];

bool check(ll x){
    ll cnt = 0;
    for(int i = 1; i <= n; i++){
        if(x >= b[i]) cnt += (x - b[i]) / a[i] + 1 - ((l - 1)>= b[i]) * ((l - 1 - b[i]) / a[i] + 1);
    }
    return cnt >= c;
}

int main(){
    n = read();
    for(int i = 1; i <= n; i++) a[i] = read();
    for(int i = 1; i <= n; i++) b[i] = read();
    l = read(), r = read(), c = read();
    ll L = l, R = r + 1, mid = (L + R) >> 1;
    while(L < R){
        mid = (L + R) >> 1;
        if(check(mid)) R = mid;
        else L = mid + 1;
    }
    if(L >= r + 1) printf("-1\n");
    else printf("%lld\n", R);
    return 0;
}