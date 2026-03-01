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
    int n, hd[N], tot, b[N], f[N], cnt[N], tmp[N], all[N], len[N], ans, siz[N], fa[N];
    int rnm[N];
    bool vis[N], vis2[N];

    void add_edge(int u, int v){
        ed[++tot].nxt = hd[u], hd[u] = tot;
        ed[tot].u = u, ed[tot].v = v;
    }

    int get(int u){
        int res = b[u];
        for(int i = hd[u]; i; i = ed[i].nxt){
            int v = ed[i].v;
            if(v == fa[u]) continue;
            fa[v] = u;
            if(b[v]) len[u] = max(len[u], 1);
            for(int j = hd[v]; j; j = ed[j].nxt){
                int p = ed[j].v;
                if(p == v || p == u) continue;                     //加判断不是u 
                if(b[p]) res += b[p], len[u] = 2;
            }
            res += b[v], siz[u] += b[v];
        }
        return res;
    }

//    pair<int, int> get1(int u, int plc){
//        pair<int, int> res = {b[u], 0};
//        for(int i = hd[u]; i; i = ed[i].nxt){
//            int v = ed[i].v; if(v == plc) continue;            //去掉v == fa 
//            if(b[v]) res.second = max(res.second, 1);
//            for(int j = hd[v]; j; j = ed[j].nxt){
//                int p = ed[j].v;                                  
//                if(p == u) continue;                            //plc改成u 
//                if(b[p]) res.first += b[p], res.second = 2;
//            }
//            res.first += b[v];
//        }
//        return res;
//    }

    void dfs1(int u){
        cnt[u] = get(u);
        all[u] = b[u];
        for(int i = hd[u]; i; i = ed[i].nxt){
            int v = ed[i].v; if(vis[v]) continue;
            vis[v] = true;
            fa[v] = u;
            dfs1(v);
            all[u] += all[v];
        }
        for(int i = hd[u]; i; i = ed[i].nxt){
            int v = ed[i].v; if(v == fa[u]) continue;
            if(cnt[v] == all[v] && len[v] == 2) f[u]++;
            else if(cnt[v] < all[v]) f[u] += f[v] + 1;
        }
    }

    void dfs2(int u){
        ans = min(ans, f[u] << 1);
        tmp[u] = f[u]; 
        int maxlen = 0, maxlen_ = 0;
        for(int i = hd[u]; i; i = ed[i].nxt){
            int v = ed[i].v; if(v == fa[u]) continue;
            tmp[v] = f[v];
            if(len[v] > maxlen) maxlen_ = maxlen, maxlen = len[v];
            else if(len[v] <= maxlen && len[v]> maxlen_) maxlen_ = len[v];
            // else if(b[v]){
                // if(maxlen < 1) maxlen_ = maxlen, maxlen = 1;
                // else if(maxlen >= 1 && maxlen_ < 1) maxlen_ = 1;
            // } 
        }
        for(int i = hd[u]; i; i = ed[i].nxt){
            int v = ed[i].v; if(vis2[v]) continue;
            vis2[v] = true;
            if(cnt[v] == all[v] && len[v] == 2) f[u]--;
            else if(cnt[v] < all[v]) f[u] -= f[v] + 1;
			
			pair<int, int> fab = {0, 0};
			if(b[fa[fa[u]]]) fab.second = 2;
			else if(siz[fa[u]] - b[u] > 0) fab.second = 2;
			else if((len[v] != maxlen && maxlen >= 1) || (len[v] == maxlen && maxlen_ >= 1)) fab.second = 2;
			else if(b[fa[u]]) fab.second = 1;
			else if(siz[u] - b[v] > 0) fab.second = 1; 
			//else if((len[v] + 1 != maxlen && maxlen == 1) || (len[v] + 1 == maxlen && maxlen_ == 1)) fab.second = 1;
			
			fab.first = cnt[u] - siz[v] - b[v] + siz[fa[u]] + b[fa[u]] - b[u] + b[fa[fa[u]]]; 

            if(fab.first == all[1] - all[v] && fab.second == 2) f[v]++;      //all[u]改成all[1] 
            else if(fab.first < all[1] - all[v]) f[v] += f[u] + 1;
			dfs2(v);
			
            f[v] = tmp[v];
            f[u] = tmp[u];
        }
    }

    int main() {
        n = read(); 
		for(int i = 1; i <= n; i++) b[i] = read();
        for(int i = 1, u, v; i < n; i++){
            u = read(), v = read();
            add_edge(u, v), add_edge(v, u);
            rnm[u]++, rnm[v]++;
        }
        
        ans = inf;
        vis[1] = true, fa[1] = 0;
        dfs1(1);
        vis2[1] = true, siz[0] = b[1];
        dfs2(1);
        cout << ans;
        
    }

