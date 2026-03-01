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

const int N = 1e3 + 5;

struct Edge{
    int nxt, to;
}ed[N << 1];
int n, m, fa[N], a[N], st[N], re[N], cnt;
int head[N], tot, val[N]; 
bool b[N], vis[N];

void add_edge(int u, int v){
    ed[++tot].nxt = head[u]; ed[tot].to = v; head[u] = tot;
}
int find(int x){return fa[x] == x ? x : fa[x] = find(fa[x]);}
void merge(int u, int v){
    int x = find(u), y = find(v);
    if(x < y) fa[y] = x;
    else fa[x] = y;
}

int main(){
    freopen("str2.in", "r", stdin);
    freopen("1.out", "w", stdout);
    n = read(), m = read();
    for(int i = 1; i <= n; i++) fa[i] = i;
    cnt = n;
    for(int i = 1, x, y, z; i <= m; i++){
        x = read(), y = read(), z = read();
        for(int l = x, r = y; r <= n && r-y+1 <= z; l++, r++){
            if(find(l) != find(r)) merge(l, r), cnt--;
        }
        st[i] = x + z, re[i] = y + z;
    }
    for(int i = 1; i <= m; i++){
        int u = find(st[i]), v = find(re[i]);
        if(u == v){printf("-1\n"); return 0;}
        else add_edge(u, v), add_edge(v, u);
    }
    memset(val, -1, sizeof val);
    for(int i = 1; i <= n; i++){
        int u = find(i);
        if(val[u] != -1){a[i] = val[u]; continue;}
        for(int j = head[u]; j; j = ed[j].nxt){
            int v = ed[j].to;
            b[val[v]] = true;
        }
        for(int j = 0; j < cnt; j++)
            if(!b[j]){val[u] = a[u] = a[i] = j; break;}
        for(int j = 0; j < cnt; j++) b[j] = false; 
    }
    for(int i = 1; i <= n; i++) printf("%d ", a[i]);
    printf("\n");
}

