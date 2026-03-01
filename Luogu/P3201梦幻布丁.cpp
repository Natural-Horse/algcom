// clang-format off
#include <bits/stdc++.h>
#define inf 0x7fffffffffffffff
#define ll long long
using namespace std;

inline ll read(){
    ll x = 0, f = 1;
    char ch = getchar();
    while(!isdigit(ch)){if(ch == '-')f = -1; ch = getchar();}
    while(isdigit(ch)){ x = (x << 3) + (x << 1) + ch - 48; ch = getchar();}
    return x * f;
}

// const long long inf = 1e19;
const int N = 1e5 + 5, C = 1e6 + 5;

int n, m, c[N];
int hd[C], nxt[N], f[C], siz[C];
int ans;

void merge(int x, int y){
    int las = 0;
    for(int i = hd[x]; i; i = nxt[i]){
        ans -= (c[i-1] == y) + (c[i+1] == y);
    }
    for(int i = hd[x]; i; i = nxt[i]){
        c[i] = y, las = i;
    }
    nxt[las] = hd[y], hd[y] = hd[x];
    siz[y] += siz[x];
    hd[x] = 0, siz[x] = 0;
}

int main(){
    n = read(), m = read();
    for(int i = 1; i <= n; i++){
        c[i] = read(), siz[c[i]]++;
        if(c[i] != c[i-1]) ans++;
        if(!hd[c[i]]) hd[c[i]] = i, f[c[i]] = c[i];
        else nxt[i] = hd[c[i]], hd[c[i]] = i;
    }
    for(int i = 1, op; i <= m; i++){
        op = read();
        if(op == 1){
            int x = read(), y = read();
            if(x == y) continue;
            if(siz[f[x]] > siz[f[y]]) swap(f[x], f[y]);
            if(!siz[f[x]]) continue;
            merge(f[x], f[y]);
        }
        else printf("%d\n", ans);
    }
    return 0;
}