#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long 
using namespace std;

inline int read(){
    int x = 0, f = 1; char ch = getchar();
    while(!isdigit(ch)){if(f == '-') f = -1; ch = getchar();}
    while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - 48; ch = getchar();}
    return x * f;
}

const int N = 1e2 + 5;

int T, n, k, a[N], b[N];

int main(){
    T = read();
    while(T--){
        n = read(), k = read();
        memset(b, 0, sizeof b);
        for(int i = 1; i <= n; i++) a[i] = read(), b[a[i]]++;
        
    }
}