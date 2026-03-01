#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
#define pii pair<int, int>
#define mkp make_pair
using namespace std;

inline ll read(){
    ll x = 0, f = 1; char ch = getchar();
    while(!isdigit(ch)){if(ch == '-') f = -1; ch = getchar();}
    while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - 48; ch = getchar();}
    return x * f;
}

const int N = 2e5 + 5, mod = 998244353;

int T, n, a[N], p[N], st[N], top, rt, ls[N], rs[N], dfn[N], tot;
ll ans[N], c[N], val[N], min_c, fans, subsize[N], group_min[N];
int top_rep[N];
struct Tr{
    int l, r;
    ll dev, sum, siz;
}tr[N << 2];

void reset(){ 
    for(int i = 0; i <= n; i++){
        ans[i] = 0;
        ls[i] = rs[i] = 0;
        subsize[i] = 0;
        top_rep[i] = 0;
    }
    min_c = 2e18;
    fans = 0;
    top = 0;
    tot = 0;
}

void dfs_top(int u, int p_node) {
    if (!u) return;
    if (p_node && a[u] == a[p_node]) top_rep[u] = top_rep[p_node];
    else top_rep[u] = u;
    
    dfs_top(ls[u], u);
    dfs_top(rs[u], u);
}

void update_c_group() {
    for(int i = 1; i <= n; ++i) group_min[i] = 2e18;
    
    for(int i = 1; i <= n; ++i) {
        int root = top_rep[i];
        group_min[root] = min(group_min[root], c[i]);
    }
    
    for(int i = 1; i <= n; ++i) {
        c[i] = group_min[top_rep[i]];
    }
}

void dfs(int u){
    if(!u) return;
    dfn[u] = ++tot;
    ll las_min = min_c;
    min_c = min(min_c, c[u]);
    val[tot] = min_c; 
    
    dfs(ls[u]);
    dfs(rs[u]);
    
    if(u == rt) val[dfn[u]] = 0;
    subsize[u] = subsize[ls[u]] + subsize[rs[u]] + 1;
    min_c = las_min;
}

void build(int u, int l, int r){
    tr[u].l = l, tr[u].r = r, tr[u].siz = r - l + 1;
    tr[u].dev = 0;
    if(l == r){
        tr[u].sum = val[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    tr[u].sum = tr[u<<1].sum + tr[u<<1|1].sum;
}

void push_down(int u){
    int na = u << 1, nb = na | 1;
    if(tr[u].dev){
        tr[na].dev = tr[nb].dev = 1;
        tr[na].sum = tr[nb].sum = 0;
    }
}
void push_up(int u){
    int na = u << 1, nb = na | 1;
    tr[u].sum = tr[na].sum + tr[nb].sum;
}

void op_dev(int u, int st, int re){
    int l = tr[u].l, r = tr[u].r;
    if(l > re || r < st) return;
    if(l >= st && r <= re){
        tr[u].dev = 1, tr[u].sum = 0;
        return;
    }
    push_down(u);
    op_dev(u << 1, st, re);
    op_dev(u << 1 | 1, st, re);
    push_up(u);
}

ll qr_sum(int u, int st, int re){
    int l = tr[u].l, r = tr[u].r;
    if(l > re || r < st) return 0;
    if(l >= st && r <= re) return tr[u].sum;
    push_down(u);
    return qr_sum(u << 1, st, re) + qr_sum(u << 1 | 1, st, re);
}

void solve(){
    dfs_top(rt, 0);
    update_c_group();
    dfs(rt);
    build(1, 1, n);
    ans[0] = qr_sum(1, 1, n);
    for(int i = 1; i <= n; i++){
        int target = top_rep[p[i]]; 
        op_dev(1, dfn[target], dfn[target] + subsize[target] - 1);
        ans[i] = qr_sum(1, 1, n);
    }
}

signed main(){
    T = read();
    while(T--){
        n = read();
        reset();
        for(int i = 1; i <= n; i++){
            a[i] = read();
            int las = 0;
            while(top >= 1 && a[i] >= a[st[top]]) las = st[top], top--;
            if(top) rs[st[top]] = i;
            else rt = i;
            ls[i] = las;
            st[++top] = i;
        }
        for(int i = 1; i <= n; i++) c[i] = read();
        for(int i = 1; i <= n; i++) p[i] = read();
        solve();
        // printf("ans : ");
        for(int i = 0; i <= n; i++){
            printf("%lld ", ans[i]);
        }
        printf("\n");
    }
    return 0;
}