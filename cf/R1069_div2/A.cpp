#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

inline int read(){
    int x = 0, f = 1; char ch = getchar();
    while(!isdigit(ch)){if(ch == '-') f = -1; ch = getchar();}
    while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - 48; ch = getchar();}
    return x * f;
}

const int N = 1e3 + 5;

int T, n, a[N], b[N], tot, maxa, ans;

void reset(){
    tot = 0;
    maxa = 0;
    ans = 0;
    memset(b, 0, sizeof b);
}

void solve(){
    for(int i = tot; i <= maxa; i++){
        if(b[i]){
            ans = i;
            return;
        }
    }
}

int main(){
    T = read();
    while(T--){
        n = read();
        reset();
        for(int i = 1; i <= n; i++){
            a[i] = read();
            if(!b[a[i]]) b[a[i]] = 1, tot++;
            maxa = max(maxa, a[i]);
        }
        solve();
        // printf("ans : ");
        printf("%d\n", ans);
    }
    return 0;
}