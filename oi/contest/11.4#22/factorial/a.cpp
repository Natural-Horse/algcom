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
ll T, n, cnt;

bool cmp(Ans aa, Ans bb){
    return aa.a < bb.a;
}

int main(){
    freopen("factorial.in", "r", stdin);
    freopen("factorial.out", "w", stdout);
    T = read();
    while(T--){
        n = read(); cnt = 0;
        if(n == 1){
            printf("-1\n");
            continue;
        }
        ll lim = sqrt(n);
        for(int i = 2; i <= lim; i++){
            if(n % i == 0){
                ll fab = 1;
                for(int j = i+1; j <= n; j++){
                    fab *= j;
                    if(fab * i > n) break;
                    else if(fab * i == n){
                        if(i > 1) ans[++cnt] = (Ans){j, i-1}; 
                        else ans[++cnt] = (Ans){j, i};
                        break;
                    }
                }
            }
        }
        if(n != 2) ans[++cnt] = (Ans){n, n-1};
        sort(ans + 1, ans + 1 + cnt, cmp);
        printf("%lld\n", cnt);
        for(int i = 1; i <= cnt; i++) printf("%lld %lld\n", ans[i].a, ans[i].b);
    }
    return 0;
}

