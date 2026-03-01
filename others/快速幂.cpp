// clang-format off
#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long 
using namespace std;

inline ll read(){
    ll x = 0, f = 1; char ch = getchar();
    while(!isdigit(ch)){if(ch == '-') f = -1; ch = getchar();}
    while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - 48; ch = getchar();}
    return x * f;
}

ll mod;

inline ll qp(ll aa, ll bb){
    ll res = 1, jud = aa;
    while(bb){
        if(bb & 1) res = (res * jud) % mod;
        jud = (jud * jud) % mod, bb >>= 1;
    }
    return res;
}

int main(){
    ll a, b;
    a = read(), b = read(), mod = read();
    cout << qp(a, b);
    return 0;
}