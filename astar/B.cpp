#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long 
using namespace std;

inline ll read(){
    ll x = 0, f = 1; char ch = getchar();
    while(!isdigit(ch)){if(ch == '-') f = -1; ch = getchar();}
    while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - 48; ch = getchar();}
    return x * f;
}

const int N = 1e5 + 5;

struct Tree{
    ll l, r, siz;
    ll cnt[4];
    ll add;
}tr[N << 4];
ll n, ls[N << 1], tot, p[4], mn, mx;
char op[N], len[N];

void build(int u, int l, int r){
    if(l == r && l != tot){
        tr[u].cnt[0] = 1;
        tr[u].l = l, tr[u].r = r, tr[u].siz = tr[u].cnt[0] = ls[l+1] - ls[l];
        return;
    }
    tr[u].l = l, tr[u].r = r;
    int mid = (l + r) >> 1;
    build(u << 1, l, mid), build(u << 1 | 1, mid+1, r);
    tr[u].cnt[0] = tr[u].siz = tr[u<<1].siz + tr[u<<1|1].siz;
}

void push_down(int u){
    int na = u << 1, nb = na | 1;
    if(tr[u].add != 0){
        tr[na].add += tr[u].add;
        tr[nb].add += tr[u].add;
        p[0] = tr[na].cnt[0], p[1] = tr[na].cnt[1], p[2] = tr[na].cnt[2], p[3] = tr[na].cnt[3];
        for(int i = 0; i <= 3; i++){
            tr[na].cnt[i] = p[(i - tr[u].add + 4) % 4];
        }
        p[0] = tr[nb].cnt[0], p[1] = tr[nb].cnt[1], p[2] = tr[nb].cnt[2], p[3] = tr[nb].cnt[3];
        for(int i = 0; i <= 3; i++){
            tr[nb].cnt[i] = p[(i - tr[u].add + 4) % 4];
        }
        tr[u].add = 0;
    }
    return;
}
void push_back(int u){
    int na = u << 1, nb = na | 1;
    for(int i = 0; i <= 3; i++) tr[u].cnt[i] = tr[na].cnt[i] + tr[nb].cnt[i];
    return;
}
void op_add(int u, int st, int re, int val){
    int l = tr[u].l, r = tr[u].r;
    if(l > re || r < st) return;
    push_down(u);
    if(l >= st && r <= re){
        p[0] = tr[u].cnt[0], p[1] = tr[u].cnt[1], p[2] = tr[u].cnt[2], p[3] = tr[u].cnt[3];
        for(int i = 0; i <= 3; i++){
            tr[u].cnt[i] = p[(i - val + 4) % 4];
        }
        tr[u].add += val;
        push_down(u);
        return;
    }
    push_down(u);
    op_add(u << 1, st, re, val);
    op_add(u << 1 | 1, st, re, val);
    push_back(u);
}
ll qr_cnt(int u, int st, int re){
    int l = tr[u].l, r = tr[u].r;
    if(l > re || r < st) return 0;
    push_down(u);
    if(l >= st && r <= re) return tr[u].cnt[1];
    push_down(u); push_back(u);
    return qr_cnt(u << 1, st, re) + qr_cnt(u << 1 | 1, st, re);
}

int main(){
    n = read();
    mn = mx = 0;
    ll plc = 0; ls[++tot] = 0, ls[++tot] = -1, ls[++tot] = 1;
    for(int i = 1; i <= n; i++){
        len[i] = read(), op[i] = getchar();
        if(op[i] == 'R') plc += len[i] - 1;
        else plc -= len[i] - 1;
        ls[++tot] = plc;
        ls[++tot] = plc-1, ls[++tot] = plc+1;
        mn = min(mn, plc), mx = max(mx, plc);
    }
    sort(ls + 1, ls + 1 + tot);
    tot = unique(ls + 1, ls + 1 + tot) - ls - 1;
    build(1, 1, tot - 1);
    plc = 0;
    for(int i = 1; i <= n; i++){
        if(op[i] == 'R'){
            int st = lower_bound(ls + 1, ls + 1 + tot, plc) - ls;
            plc += len[i] - 1;
            int re = lower_bound(ls + 1, ls + 1 + tot, plc) - ls;
            op_add(1, st, re, 1);
        }
        else{
            int st = lower_bound(ls + 1, ls + 1 + tot, plc) - ls;
            plc -= len[i] - 1;
            int re = lower_bound(ls + 1, ls + 1 + tot, plc) - ls;
            op_add(1, re, st, 1);
        }
    }
    int st = lower_bound(ls + 1, ls + 1 + tot, mn) - ls;
    int re = lower_bound(ls + 1, ls + 1 + tot, mx) - ls;
    ll ans = qr_cnt(1, st, re);
    printf("%lld\n", ans);
    return 0;
}