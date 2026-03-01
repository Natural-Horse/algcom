#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
#define db double
using namespace std;

inline ll read(){
	ll x = 0, f = 1; char ch = getchar();
	while(!isdigit(ch)){if(ch == '-') f = -1; ch = getchar();}
	while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - 48; ch = getchar();}
	return x * f;
}

int T;
ll a, b, c, d;

int main(){
    T = read();
    while(T--){
        a = read(), b = read(), c = read(), d = read();
        ll l = abs(a - c), r = abs(b - d);
        //printf("l:%lld r:%lld\n", l, r);
        if(l == r) {printf("%lld\n", l + r); continue;}
        else if(l > r){
            ll ans = min(l,r)*2 + ((l-r)/2)*4;
            if((l-r)%2) ans++;
            printf("%lld\n", ans);
        }
        else{
            ll ans = min(l,r)*2 + ((r-l)/2)*4;
            if((r-l)%2) ans++;
            printf("%lld\n", ans);
        }
    }
    return 0;
}

