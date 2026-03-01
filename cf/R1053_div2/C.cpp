#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
#define pii pair<int, int>
#define mkp make_pair
using namespace std;

inline ll read(){
    ll x = 0, f = 1; char ch = getchar();
    while(!isdigit(ch)){if(ch == '-') f = -1; ch = getchar();}
    while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - 48; ch = getchar();}
    return x * f;
}

const int N = 4e5 + 5;

ll n, T, a[N], ans[N];

void reset(){
    memset(ans, 0, sizeof ans);
}

void solve(){
    for(int i = 1; i <= n; i++) ans[n] -= a[i];
    for(int i = n + 1; i <= n * 2; i++) ans[n] += a[i];
    ans[n-1] = ans[n] - 2 * a[n + 1] + 2 * a[n]; 
    for(int i = 2; i <= n - 1; i++){
        ans[n-i] = ans[n-i+2] - 2 * a[n + i] + 2 * a[n - i + 1];
    }
}


int main(){
    T = read();
    int count = T;
    while(T--){
        n = read();
        for(int i = 1; i <= (n << 1); i++) a[i] = read();
        reset();
        solve();
        // printf("Test %lld : ", count - T);
        for(int i = 1; i <= n; i++) printf("%lld ", ans[i]);
        printf("\n");
    }
    return 0;
}