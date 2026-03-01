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

const int N = 1e5 + 5;

int T, n, a[N], ans;
bool b[N];

void reset(){
    for(int i = 1; i <= n; i++) b[i] = false;
    ans = 0;
}

void solve(){
    for(int i = 1; i < n; i++){
        if(b[i] == true) continue;
        b[i] = true;
        for(int j = i + 1; j <= n; j++){
            if(a[i] > a[j] && !b[j]) b[j] = true, ans++;
        }
    }
}

int main(){
    T = read();
    while(T--){
        n = read();
        for(int i = 1; i <= n; i++) a[i] = read();
        reset();
        solve();
        printf("%d\n", ans);
    }
    return 0;
}