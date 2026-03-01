#include <bits/stdc++.h>
#define inf 0x3f3f3f3f3f
#define ll long long
using namespace std;

inline int read(){
    int x = 0, f = 1; char ch = getchar();
    while(!isdigit(ch)){if(f == '-') f = -1; ch = getchar();}
    while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - 48; ch = getchar();}
    return x * f;
}

const int N = 1e5 + 5;

int n, T;
int a[N], b[N], mx, mn, ans;

void reset(){
    memset(b, 0, sizeof b);
    mx = 0, mn = inf, ans = 0;
}


int main(){
    T = read();
    while(T--){
        reset();
        n = read();
        for(int i = 1; i <= n; i++){
            a[i] = read();
            mx += (a[i] > a[i-1]);
            b[mx]++;
        }
        sort(b + 1, b + 1 + mx);
        for(int i = 1; i <= mx; i++){
            ans = max(ans, b[i] * (mx - i + 1));
        }
        printf("%d\n", ans);
    }
    return 0;
}