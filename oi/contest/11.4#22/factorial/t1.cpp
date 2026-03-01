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

const int N = 1e4 + 5;

struct Ans{
    ll a, b;
}ans[N];
ll n, T, cnt, las;

bool cmp(Ans aa, Ans bb){
    return aa.a < bb.a;
}

int main(){
    freopen("factorial1.in", "r", stdin);
//    freopen("factorial.out", "w", stdout);
    T = read();
    while(T--){
        n = read(), cnt = 0;
        if(n == 1){printf("-1\n"); continue;}
        las = 0;
        for(ll i = 1; i <= 20; i++){
            ll rg = pow(n, (db)1/(db)i);
            //if(rg == las) continue;
            las = rg;
            //printf("rg : %lld\n", rg);
            ll l = max(2ll, rg - i + 1), r = l + i - 1, jud = 1;
            printf("l : %lld r : %lld rg : %lld i : %lld\n", l, r, rg, i);
            for(ll j = l; j <= r; j++) jud *= j;
            if(jud == n) ans[++cnt] = (Ans){r, l-1};
            while(jud < n){
                jud = jud / l * (r+1);
                l++, r++;
                if(jud > n) break;
                else if(jud == n){printf("%lld %lld\n", r, l-1), ans[++cnt] = (Ans){r, l-1}; break;}
            }
        }
//        sort(ans + 1, ans + 1 + cnt, cmp);
//        printf("%lld\n", cnt);
//        for(int i = 1; i <= cnt; i++) printf("%lld %lld\n", ans[i].a, ans[i].b);
    }
    return 0;
}

