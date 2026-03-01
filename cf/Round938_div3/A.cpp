#include<iostream>
#include<cstring>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

inline int read(){ 
    int x = 0, f = 1; char ch = getchar();
    while(!isdigit(ch)){if(ch == '-') f = -1; ch = getchar();}
    while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - 48; ch = getchar();}
    return x * f;
}

const int N = 1e2 + 5;

int t, n, a, b, f[N];

int main(){
    t = read();
    while(t--){
        memset(f, inf, sizeof f);
        n = read(), a = read(), b = read();
        f[1] = a, f[0] = 0;
        for(int i = 2; i <= n; i++) f[i] = min(f[i-1] + a, f[i-2] + b);
        printf("%d\n", f[n]);
    }
    return 0;
}