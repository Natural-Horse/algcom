#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define long long
using namespace std;

inline int read(){
    int x = 0, f = 1; char ch = getchar();
    while(!isdigit(ch)){if(ch == '-') f = -1; ch = getchar();}
    while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - 48; ch = getchar();}
    return x * f;
}

const int N = 1e5 + 5;

int n, q, plc[N];

int main(){
    n = read(), q = read();
    for(int i = 1; i <= n; i++){
        plc[i] = read();
    }
    sort(plc + 1, plc + 1 + n);
    for(int i = 1, l, r; i <= q; i++){
        l = read(), r = read();
        l = lower_bound(plc + 1, plc + 1 + n, l) - plc;
        r = upper_bound(plc + 1, plc + 1 + n, r) - plc - 1;
        printf("%d\n", r - l + 1);
    }
    return 0;
}