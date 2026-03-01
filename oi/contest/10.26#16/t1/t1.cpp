#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
#define db double
using namespace std;

inline int read(){
	int x = 0, f = 1; char ch = getchar();
	while(!isdigit(ch)){if(ch == '-') f = -1; ch = getchar();}
	while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - 48; ch = getchar();}
	return x * f;
}

const int N = 5e6 + 5;

struct Edge{
    int nxt, to;
}ed[N << 1];
int n, m, a, b, x, y, fab[N], jud[N], f[N], siz[N], q[N];
int fa[N], head[N], tot, ans;

void add_edge(int u, int v){
    ed[++tot].nxt = head[u]; ed[tot].to = v; head[u] = tot;
}

void dfs(int u, int p){
    int tmp = p;
    if(!p && fab[u]) p = fab[u];
    else if(fab[u] < p && fab[u]) p = fab[u];
    siz[u] = 1;
    for(int i = head[u]; i; i = ed[i].nxt){
        dfs(ed[i].to, p);
        siz[u] += siz[ed[i].to];
    }
    if(!tmp && fab[u]) jud[p] += siz[u];
    else if(fab[u] < tmp && fab[u]) jud[tmp] -= siz[u], jud[p] += siz[u];
}

int main(){
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    n = read(), m = read(), a = read(), b = read();
    fa[2] = 1, add_edge(1, 2);
    for(int i = 3; i <= n; i++) {
        fa[i] = ((1ll * fa[i - 1] * a + b) ^ 19760817) % (i - 1) + 1;
        add_edge(fa[i], i);
    }
    q[1] = read(), x = read(), y = read();
    fab[q[1]] = 1;
    for(int i = 2; i <= m; i++){
        q[i] =  (((1ll * q[i - 1] * x + y) ^ 19760817) ^ (i << 1)) % (n - 1) + 2;
        if(!fab[q[i]]) fab[q[i]] = i;
        else fab[q[i]] = min(fab[q[i]], i);    
    }
    dfs(1, 0);
    jud[0] = 0;
    for(int i = 1; i <= m; i++){
        jud[i] = jud[i-1] + jud[i];
        ans = ans ^ (siz[1] - jud[i]);
    } 
    printf("%d\n", ans);
    return 0;
}

