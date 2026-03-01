#include<bits/stdc++.h>
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

int n, m;
ll a[N];

int main(){
    n = read(), m = read();
    for(int i = 1; i <= m; i++) a[i] = read();
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){
            ll x = read();
            a[j] -= x;
        }
    for(int i = 1; i <= m; i++)
        if(a[i] > 0){printf("No\n"); return 0;}
    printf("Yes\n");
    return 0;
}