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

const int N = 1e3 + 5, M = 2e4 + 5;

struct Edge{
    int nxt, to, cap, id;
    bool d, b;
}ed[M << 1], ed_[N+M*3];
struct E{
    int fr, to;
}e[M << 1];
int n, m, s, t, mx, mxf, deg[N];
int head[N], tot=1, head_[N], tot_=1, d[N], now[N], fa[N];
queue<int> q;
int ans[N], cnt;

void add_edge(int u, int v, int w, int id){
    ed[++tot].nxt = head[u]; ed[tot].to = v, ed[tot].id = id, ed[tot].cap = w; head[u] = tot;
    e[id] = (E){u, v};
}
void add_edge_(int u, int v, int w, int id){
    ed_[++tot_].nxt = head_[u]; ed_[tot_].to = v, ed_[tot_].id = id, ed_[tot_].cap = w; head_[u] = tot_;
}
void add_flow(int u, int v, int w, int id){
    add_edge_(u, v, w, id), add_edge_(v, u, 0, id);
}

bool bfs(){
    for(int i = 1; i <= t; i++) d[i] = 0;
    while(!q.empty()) q.pop();
    q.push(s), d[s] = 1, now[s] = head_[s];
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int i = head_[u]; i; i = ed_[i].nxt){
            int v = ed_[i].to;
            if(!d[v] && ed_[i].cap){
                q.push(v), d[v] = d[u] + 1, now[v] = head_[v];
                if(v == t) return true;
            }
        }
    }
    return false;
}
int dfs(int u, int flo){
    if(u == t) return flo;
    int res = flo, k, i;
    for(i = now[u]; i && res; i = ed_[i].nxt){
        int v = ed_[i].to;
        if(d[v] == d[u] + 1 && ed_[i].cap){
            k = dfs(v, min(ed_[i].cap, res));
            ed_[i].cap -= k, ed_[i^1].cap += k, res -= k;
            if(!k) d[v] = 0;
        }
    }
    now[u] = i;
    return flo - res;
}
int dinic(){
    int res = 0;
    while(bfs()) res += dfs(s, inf);
    return res;
}

bool check(int x){
    for(int i = 1; i <= t; i++) head_[i] = 0;
    tot_ = 1;
    int jud = 0;
    for(int i = 1; i <= n; i++){
        for(int j = head[i]; j; j = ed[j].nxt){
            int v = ed[j].to;
            if(ed[j].cap >= x){
                add_flow(ed[j].id+n, i, 1, ed[j].id);
            }
        }
    }
    int c = m;
    for(int i = 1; i <= n; i++){
        add_flow(i, t, deg[i]>>1, ++c), jud += (deg[i] >> 1);
    }
    for(int i = n + 1; i <= n + m; i++) add_flow(s, i, 1, ++c);
    int fab = dinic();
    if(fab == jud) return true;
    else return false;
}

int find(int x){
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}
void merge(int u, int v){
    fa[find(u)] = find(v);
}
void get(int u){
    printf("%d ", u);
    for(int i = head[u]; i; i = ed[i].nxt){
        if(ed[i].b){
            ed[i].b = false;
            ans[++cnt] = ed[i].id;
            int v = ed[i].to;
            get(v);
        }
    }
}

int main(){
    n = read(), m = read();
    s = n + m + 1, t = s + 1;
    int cnt = n;
    for(int i = 1; i <= n; i++) fa[i] = i;
    for(int i = 1, u, v, l, p; i <= m; i++){
        u = read(), v = read(), l = read(), p = read();
        add_edge(u, v, l, (tot>>1)+1), add_edge(v, u, p, tot>>1);
        mx = max(mx, max(l, p));
        if(find(u) != find(v)) merge(u, v), cnt--;
    }
    bool fab = true;
    for(int i = 1; i <= n; i++){
        for(int j = head[i]; j; j = ed[j].nxt){
            int v = ed[j].to;
            deg[i]++;
        }
    }   
    for(int i = 1; i <= n; i++){
        if(deg[i] % 2){ printf("NIE\n"); return 0; }
        if(!deg[i]) fab = false;
    } 
    if(cnt > 1 && fab){printf("NIE\n"); return 0;}
    int l = 0, r = mx;
    while(l < r){
        int mid = (l + r + 1) >> 1;
        if(check(mid)) l = mid;
        else r = mid - 1;
    }
    printf("%d\n", l);
    for(int i = n+1; i <= n+m; i++){
        for(int j = head_[i]; j; j = ed_[j].nxt){
            int v = ed_[j].to;
            printf("ed:%d v:%d\n", i, v);
            if(v <= n && !ed_[j].cap){
                if(v == e[ed_[j].id].to) ed[(i-n)<<1].b = true;
                else if(v == e[ed_[j].id].fr) ed[(i-n)<<1|1].b = true;
            }
        }
    }
//    printf("::");
//    get(1);
//    printf("\n");
//    for(int i = 1; i <= cnt; i++) printf("%d ", ans[i]);
//    printf("\n");
    return 0;
}
