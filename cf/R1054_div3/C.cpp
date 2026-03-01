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

const int N = 2e5 + 5;

int n, T, a[N], k, b[N];
int cnt_ltk, cnt_eqk, ans, maxn;

void reset(){
    for(int i = 0; i <= maxn; i++) b[i] = 0;
    maxn = 0;
    cnt_eqk = cnt_ltk = ans = 0;
}

void solve(){
    for(int i = 0; i < k; i++) cnt_ltk += (b[i] == 0);
    cnt_eqk = b[k];
    ans = max(cnt_eqk, cnt_ltk);
}

int main(){
    T = read();
    int count = T;
    while(T--){
        n = read(), k = read();
        reset();
        for(int i = 1; i <= n; i++){
            a[i] = read();
            b[a[i]]++;
            maxn = max(maxn, a[i]);
        }
        solve();
        // printf("Test %d : ", count - T);
        printf("%d\n", ans);
    }
    return 0;
}