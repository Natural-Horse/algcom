// clang-format off
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

inline int read(){
    int x = 0, f = 1; char ch = getchar();
    while (!isdigit(ch)){if (f == '-') f = -1; ch = getchar();}
    while (isdigit(ch)){x = (x << 3) + (x << 1) + ch - 48; ch = getchar();}
    return x * f;
}

const int N = 1e3 + 5;

int T, n, k, a[N], b;

int main(){
    T = read();
    while (T--){
        n = read(); b = 0;
        for(int i = 1; i <= n; i++){
            a[i] = read();
            if(i == 1) continue;
            if(abs(a[i] - a[i - 1]) != 5 && abs(a[i] - a[i - 1]) != 7) b = 1;
        }
        if(b == 1) printf("No\n");
        else printf("Yes\n");
    }
    return 0;
}