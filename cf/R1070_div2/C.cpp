#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
#define int long long
using namespace std;

inline int read(){
    int x = 0, f = 1; char ch = getchar();
    while(!isdigit(ch)){if(ch == '-') f = -1; ch = getchar();}
    while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - 48; ch = getchar();}
    return x * f;
}

const int N = 2e5 + 5;

int T, n, a[N], mx_odd, eve[N], eve_tot, ans[N];

void reset(){ 
    eve_tot = 0;
    mx_odd = 0;
}
    

void solve(){
    sort(eve + 1, eve + 1 + eve_tot, greater<int>());
    if(mx_odd == 0){
        for(int i = 1; i <= n; i++) ans[i] = 0;
        return;
    }
    ans[1] = mx_odd;
    for(int i = 2; i <= eve_tot + 1; i++) ans[i] = ans[i-1] + eve[i-1];
    for(int i = eve_tot + 2; i <= n; i++){
        if((i - eve_tot) & 1){
            ans[i] = ans[eve_tot + 1];
        }
        else{
            if(eve_tot == 0) ans[i] = 0;
            else if(n == i) ans[i] = 0;
            else ans[i] = ans[eve_tot + 1] - eve[eve_tot];
        }
    }
}

signed main(){
    T = read();
    while(T--){
        n = read();
        reset();
        for(int i = 1; i <= n; i++){
            a[i] = read();
            if(!(a[i] & 1)) eve[++eve_tot] = a[i];
            else if(a[i] > mx_odd) mx_odd = a[i];
        }
        solve();
        // printf("ans : ");
        for(int i = 1; i <= n; i++) printf("%lld ", ans[i]);
        printf("\n");
    }
    return 0;
}