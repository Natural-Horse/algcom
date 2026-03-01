// clang-format off
#include <bits/stdc++.h>
#define inf 0x7fffffffffffffff
#define ll long long
using namespace std;

inline ll read(){
    ll x = 0, f = 1;
    char ch = getchar();
    while(!isdigit(ch)){if(ch == '-')f = -1; ch = getchar();}
    while(isdigit(ch)){ x = (x << 3) + (x << 1) + ch - 48; ch = getchar();}
    return x * f;
}

// const long long inf = 1e19;
const int N = 5e5 + 5;
const int mod = 1e9 + 7;

struct Tr{
    ll l, r, lmax, rmax, cnt, add;
} tr[N << 4];
ll n, x[N], r[N], tot, ls[N * 3], ans[N], fans;
ll LMAX[N], RMAX[N];
ll c[N];

void build(int u, int l, int r){
    tr[u].lmax = inf, tr[u].rmax = -1;
    if (l == r){
        tr[u].l = tr[u].r = l;
        return;
    }
    int mid = (l + r) >> 1;
    build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
    tr[u].l = tr[u<<1].l, tr[u].r = tr[u<<1|1].r;
}

void push_back(int u){
    int na = u << 1, nb = na | 1;
    tr[u].lmax = min(tr[u].lmax, min(tr[na].lmax, tr[nb].lmax)), tr[u].rmax = max(tr[u].rmax, max(tr[na].rmax, tr[nb].rmax));
    tr[u].cnt = tr[na].cnt + tr[nb].cnt;
}

void op_chgl(int u, int plc, ll val){
    int l = tr[u].l, r = tr[u].r;
    if (l > plc || r < plc) return;
    if (l >= plc && r <= plc){tr[u].lmax = min(tr[u].lmax, val); return;}
    push_back(u);
    op_chgl(u << 1, plc, val), op_chgl(u << 1 | 1, plc, val);
    push_back(u);
}
void op_chgr(int u, int plc, ll val){
    int l = tr[u].l, r = tr[u].r;
    if (l > plc || r < plc) return;
    if (l >= plc && r <= plc){tr[u].rmax = max(tr[u].rmax, val); return;}
    push_back(u);
    op_chgr(u << 1, plc, val), op_chgr(u << 1 | 1, plc, val);
    push_back(u);
}
void op_add(int u, int plc){
    int l = tr[u].l, r = tr[u].r;
    if (l > plc || r < plc) return;
    if (l >= plc && r <= plc){tr[u].cnt++;return;}
    push_back(u);
    op_add(u << 1, plc), op_add(u << 1 | 1, plc);
    push_back(u);
}

ll qr_lmax(int u, int st, int re){
    int l = tr[u].l, r = tr[u].r;
    if (l > re || r < st) return inf;
    if (l >= st && r <= re) return tr[u].lmax;
    push_back(u);
    ll jud = qr_lmax(u << 1, st, re);
    jud = min(jud, qr_lmax(u << 1 | 1, st, re));
    return jud;
}
ll qr_rmax(int u, int st, int re){
    int l = tr[u].l, r = tr[u].r;
    if (l > re || r < st) return 0;
    if (l >= st && r <= re) return tr[u].rmax;
    push_back(u);
    return max(qr_rmax(u << 1, st, re), qr_rmax(u << 1 | 1, st, re));
}
ll qr_cnt(int u, int st, int re){
    int l = tr[u].l, r = tr[u].r;
    if (l > re || r < st) return 0;
    if (l >= st && r <= re) return tr[u].cnt;
    push_back(u);
    return qr_cnt(u << 1, st, re) + qr_cnt(u << 1 | 1, st, re);
}

int main(){
    n = read();
    for (int i = 1; i <= n; i++){
        x[i] = read(), r[i] = read();
        ls[++tot] = x[i], ls[++tot] = x[i] - r[i], ls[++tot] = x[i] + r[i];
    }
    sort(ls + 1, ls + 1 + tot);
    tot = unique(ls + 1, ls + 1 + tot) - ls - 1;
    build(1, 1, tot);
    for(int i = 1; i <= n; i++){
        c[i] = lower_bound(ls + 1, ls + 1 + tot, x[i]) - ls;
        op_add(1, c[i]);
        op_chgl(1, c[i], lower_bound(ls + 1, ls + 1 + tot, x[i] - r[i]) - ls);
        op_chgr(1, c[i], lower_bound(ls + 1, ls + 1 + tot, x[i] + r[i]) - ls);
    }
    for (int i = 1; i <= n; i++){
        ll plcl = lower_bound(ls + 1, ls + 1 + tot, x[i] - r[i]) - ls;
        ll plcr = lower_bound(ls + 1, ls + 1 + tot, x[i] + r[i]) - ls;
        LMAX[i] = min(plcl, qr_lmax(1, plcl, c[i]));
        RMAX[i] = max(plcr, qr_rmax(1, LMAX[i], c[i]));
        // ll CNT = qr_cnt(1, LMAX, c[i]);
        // ans[i] += CNT;
        op_chgl(1, c[i], LMAX[i]);
        // printf("%lld ", ans[i]);
    }
    // printf("\n");
    for (int i = n; i; --i){
        // ll plcr = lower_bound(ls + 1, ls + 1 + tot, x[i] + r[i]) - ls;
        RMAX[i] = max(RMAX[i], qr_rmax(1, LMAX[i], RMAX[i]));
        LMAX[i] = min(LMAX[i], qr_lmax(1, LMAX[i], RMAX[i]));
        // ll CNT = qr_cnt(1, c[i], RMAX);
        // ans[i] += CNT - 1;
        op_chgr(1, c[i], RMAX[i]);
    }
    for (ll i = 1; i <= n; i++){
        ans[i] = qr_cnt(1, LMAX[i], RMAX[i]);
        fans = (fans + (ans[i] * i) % mod) % mod;
        // printf("%lld ", ans[i]);
    }
    // printf("\n");
    printf("%lld\n", fans);
    return 0;
}