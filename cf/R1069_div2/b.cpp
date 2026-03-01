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

const int N = 5e5 + 5;

int T, n, l, r, p[N], a[N];

void reset(){
    
}

void solve(){
    for(int i = 1; i <= n; i++){
        if(i == r) p[i] = p[l - 1];
        else if(i == r + 1) p[i] = p[i - 2] + 1;
        else p[i] = p[i-1] + 1;
        a[i] = p[i] ^ p[i-1];
    }
}

int main(){
    T = read();
    while(T--){
        n = read(), l = read(), r = read();
        solve();
        // printf("ans : ");
        for(int i = 1; i <= n; i++) printf("%d ", a[i]);
        printf("\n");
    }
    return 0;
}