#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
#define db double
#define pii pair<int, int>
#define mkp make_pair()
using namespace std;

inline int read(){
    int x = 0, f = 1; char ch = getchar();
    while(!isdigit(ch)){if(ch == '-') f = -1; ch = getchar();}
    while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - 48; ch = getchar();}
    return x * f;
}

const int N = 1e5 + 5, mod = 676767677;

ll n, T, k, a[N], c[N];
ll A[N], P[N];
ll ans;

void reset(){
    ans = 1;
}

void solve(){
    ll jud = 0;
    for(int i = 1; i <= n / 2 - (!(n & 1)); i++){
        A[i] = c[i] + c[n - i + 1];
        P[i] = 2 * P[i - 1] + A[i] - A[i-1];
    }

    for(int i = 1; i <= n / 2 - (!(n & 1)); i++) jud = (jud + P[i]) % mod;
    if(n == 1){
        if(a[1] == 1) ans = 2;
        else ans = 0;
        return;
    }

    if(n & 1){
        if(jud != c[n / 2 + 1]) ans = 0;
        else{
            for(int i = 1; i <= n / 2 - (!(n & 1)); i++){
                if(c[i] == c[n / 2 + 1]){
                    ans = 1;
                    return;
                }
            }
            ans = 2;
        }
    }
    else{
        ans = 1;
        ll fab1 = c[n / 2] - jud, fab2 = c[n / 2 + 1] - jud;
        if(fab1 != 0 && fab1 != 1 && fab2 != 0 && fab2 != 1) ans = 0;
    }
    
}

int main(){
    T = read();
    int count = T;
    while(T--){
        n = read();
        for(int i = 1; i <= n; i++){
            a[i] = read();
            c[i] = a[i] - i;
        }
        reset();
        solve();
        // printf("Test %lld : ", count - T);
        printf("%lld\n", ans);
    }
    return 0;
}