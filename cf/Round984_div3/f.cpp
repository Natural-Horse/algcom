// clang-format off
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
#define pii pair<int, int>
using namespace std;

inline int read(){
    int x = 0, f = 1; char ch = getchar();
    while (!isdigit(ch)){if (f == '-') f = -1; ch = getchar();}
    while (isdigit(ch)){x = (x << 3) + (x << 1) + ch - 48; ch = getchar();}
    return x * f;
}

const int N = 2e5 + 5;

int T, L, R, K, I;
int f[32][32], tmp[32];

int main(){
    // freopen("C.out", "w", stdout);
    T = read();
    while (T--){
        L = read(), R = read(), I = read(), K = read();
        for(int i = 1; i <= 31; i++){
            
        }
    }
    return 0;
}