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

const int N = 3e5 + 5;

int n, a[N], pre[N], nxt[N], las[N];
ll ans;

int main(){
    n = read();
    for(int i = 1; i <= n; i++){
        a[i] = read();
        pre[i] = las[a[i]], nxt[las[a[i]]] = i;
        las[a[i]] = i;
    }
    for(int i = 1; i <= n; i++){
        int u = i, cnt = 1, jud = 0;
        while(nxt[u] != 0){
            jud += nxt[u] - u - 1;
            u = nxt[u];
            ans += jud;
        }
    }
    printf("%lld\n", ans);
    return 0;
}