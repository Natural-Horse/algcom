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

const int N = 30005;

    struct Ed{
        int u, v, nxt;
    }ed[N<<1];
    int n, hd[N], tot, len[N], ans, fa[N], b[N], rt;

    void add_edge(int u, int v){
        ed[++tot].nxt = hd[u], hd[u] = tot;
        ed[tot].u = u, ed[tot].v = v;
    }

    void dfs1(int u){
        for(int i = hd[u]; i; i = ed[i].nxt){
            int v = ed[i].v; if(v == fa[u]) continue;
            fa[v] = u;
            dfs1(v);
            len[u] = min(len[u], len[v] + 1);
        }
        if(b[u] == 1 && len[u] == inf) len[u] = 0;
    }

    void dfs2(int u){
        for(int i = hd[u]; i; i = ed[i].nxt){
            int v = ed[i].v; if(v == fa[u] || len[v] < 2 || len[v] == inf) continue;
            ans++;
            dfs2(v);
        }
    }

    int main() {
        n = read(); 
		for(int i = 1; i <= n; i++) b[i] = read();
        for(int i = 1, u, v; i < n; i++){
            u = read(), v = read();
            add_edge(u, v), add_edge(v, u);
        }
        for(int i = 1; i <= n; i++) len[i] = inf;
        dfs1(1);
        for(int i = 1; i <= n; i++) 
            if(len[i] == 2){rt = i; break;}
        memset(len, inf, sizeof len);
        dfs1(rt);
        dfs2(rt);
        cout << (ans << 1);
        
    }

