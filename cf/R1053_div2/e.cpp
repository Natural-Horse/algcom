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

const int N = 2e5 + 5;

struct Tr{
    int l, r;
    ll sum, siz, dev;
    bool flg;
}tr[N << 2];

int n, T, a[N], b[N], rka[N], rkb[N], ida[N], idb[N];
ll v[N], ans;

void reset(){
    ans = 0;
}


void prework(){
    
}

void build(int u, int l, int r){
    tr[u].l = l, tr[u].r = r, tr[u].siz = r - l + 1, tr[u].dev = -1;
    tr[u].flg = false;
    if(l == r){
        tr[u].sum = v[idb[l]];
        return;
    }
    int mid = (l + r) >> 1;
    build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
    tr[u].sum = tr[u<<1].sum, tr[u<<1|1].sum;
}

void push_down(int u){
    int na = u << 1, nb = na | 1;
    if(tr[u].dev != -1){
        tr[na].dev = tr[u].dev, tr[na].sum = tr[u].dev * tr[u].siz;
        tr[nb].dev = tr[u].dev, tr[nb].sum = tr[u].dev * tr[u].siz;
        tr[u].dev = -1;
    }
    if(tr[u].flg == true){
        tr[na].flg = tr[nb].flg = true;
    }
    tr[u].sum = tr[na].sum + tr[nb].sum;
}

void op_dev(int u, int st, int re, ll val){
    int l = tr[u].l, r = tr[u].r;
    if(l > re || r < st) return;
    if(l >= st && r <= re){
        push_down(u);
        tr[u].sum = tr[u].siz * val, tr[u].dev = val;
        tr[u].flg = true;
        return;
    }
    push_down(u);
    op_dev(u << 1, st, re, val);
    op_dev(u << 1 | 1, st, re, val);
    push_down(u);
}

ll qr_sum(int u, int st, int re){
    int l = tr[u].l, r = tr[u].r;
    if(l > re || r < st) return 0;
    if(l >= st && r <= re) return tr[u].sum;
    push_down(u);
    ll prt1 = qr_sum(u << 1, st, re);
    ll prt2 = qr_sum(u << 1 | 1, st, re);
    return prt1 + prt2;
}

bool qr_flg(int u, int st, int re){
    int l = tr[u].l, r = tr[u].r;
    if(l > re || r < st) return 0;
    if(l >= st && r <= re) return tr[u].flg;
    push_down(u);
    bool prt1 = qr_flg(u << 1, st, re);
    bool prt2 = qr_flg(u << 1 | 1, st, re);
    return prt1 | prt2;
}

void solve(){
    build(1, 1, n);
    for(int i = 1; i <= n; i++){
        int tmp_id = ida[i];
        int tmp_rkb = rkb[tmp_id];
        if(qr_flg(1, tmp_rkb, tmp_rkb)) continue;
        if(v[tmp_id] >= 0){
            ans += v[tmp_id];
            op_dev(1, tmp_rkb, tmp_rkb, 0);
        }
        else{
            int last_rkb = tmp_rkb - 1;
            int last_idb = idb[last_rkb];
            ll tmp_costb = qr_sum(1, 1, tmp_rkb);
            if(-v[tmp_id] > tmp_costb){
                op_dev(1, 1, tmp_rkb, 0);
            }
            else{
                ans += v[tmp_id];
                op_dev(1, tmp_rkb, tmp_rkb, 0);
            }
        }
    }
}


int main(){
    freopen("ans.out", "w", stdout);
    T = read();
    int count = T;
    // prework();
    while(T--){
        n = read();
        for(int i = 1; i <= n; i++) v[i] = read();
        for(int i = 1; i <= n; i++) ida[i] = read(), rka[ida[i]] = i;
        for(int i = 1; i <= n; i++) idb[i] = read(), rkb[idb[i]] = i;
        reset();
        solve();
        printf("Test %d : ", count - T);
        printf("%lld\n", ans);
    }
    return 0;
}