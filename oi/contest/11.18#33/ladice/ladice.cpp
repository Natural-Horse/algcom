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

int n, m, fa[N], siz[N], cnt[N];

int find(int x){return fa[x] == x ? x : fa[x] = find(fa[x]);}
void merge(int u, int v){
    int x = find(u), y = find(v);
    siz[x] += siz[y], cnt[x] += cnt[y];
    fa[y] = x;
}

int main(){
    freopen("ladice.in", "r", stdin);
    freopen("ladice.out", "w", stdout);
    n = read(), m = read();
    for(int i = 1; i <= m; i++) fa[i] = i, siz[i] = 1;
    for(int i = 1, u, v; i <= n; i++){
        u = read(), v = read();
        int x = find(u), y = find(v);
        if(x != y) merge(u, v);
        if(siz[x] > cnt[x]) cnt[x]++, printf("LADICA\n");
        else printf("SMECE\n"); 
    }
    return 0;
} 
//adYWChJ5
