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

const int N = 100005;

    struct Ed{
        int u, v, nxt;
    }ed[N<<1];
    int n, dfn[N], low[N], st[N], top, num, tot, hd[N], hd_[N];
    bool vis[N];
    int scc_num, c[N], ans;
    vector<int> p[N];

    void add_edge(int u, int v){
        ed[++tot].nxt = hd[u], hd[u] = tot;
        ed[tot].u = u, ed[tot].v = v;
        ed[++tot].nxt = hd_[v], hd_[v] = tot;
        ed[tot].u = v, ed[tot].v = u;
    }

    void tarjan(int u){
        dfn[u] = low[u] = ++num;
        st[++top] = u, vis[u] = true;
        for(int i = hd[u]; i; i = ed[i].nxt){
            int v = ed[i].v;
            if(!dfn[v]) tarjan(v), low[u] = min(low[u], low[v]);
            else if(vis[v]) low[u] = min(low[u], dfn[v]);
        }
        if(low[u] == dfn[u]){
            scc_num++;
            do{
                p[scc_num].push_back(st[top]);
                c[st[top]] = scc_num;
            }while(st[top--] != u);
            if(p[scc_num].size() > ans) ans = p[scc_num].size();
        }
    }

    int get(int u, int flag){
        int res = 0;
        for(int i = hd_[u]; i; i = ed[i].nxt){
            int v = ed[i].v; if(c[v] == flag) continue;
            res = max(res, get(v, flag) + 1);
        }
        return res;
    }

    int main() {
        n = read();
        for(int i = 1, u; i <= n; i++){
        	u = read();
            add_edge(i, u);
        }
        for(int i = 1; i <= n; i++){
            if(!dfn[i]) tarjan(i);
        }
        
        int jud = 0;
        for(int i = 1; i <= scc_num; i++){
        	int siz =  p[i].size();
            if(siz == 2){
                for(auto u : p[i]){
                    jud = max(jud, get(u, i));
                }
            }
            ans = max(ans, jud + 2);
        }
        
        cout << ans;
    }
