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

int n, T, a[N];
int ans;

void reset(){
    ans = 0;
}

void solve(){
    sort(a + 1, a + 1 + n);
    for(int i = 1; i <= n; i += 2){
        ans = max(ans, abs(a[i] - a[i+1]));
    }
}

int main(){
    T = read();
    int count = T;
    while(T--){
        n = read();
        for(int i = 1; i <= n; i++) a[i] = read();
        reset();
        solve();
        // printf("Test %d : ", count - T);
        printf("%d\n", ans);
    }
    return 0;
}