#include <bits/stdc++.h>
#define inf 0x3f3f3f3f3f
#define ll long long
#define pll pair<ll, ll>
#define mkp make_pair
using namespace std;

inline int read(){
    int x = 0, f = 1; char ch = getchar();
    while(!isdigit(ch)){if(f == '-') f = -1; ch = getchar();}
    while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - 48; ch = getchar();}
    return x * f;
}

const int N = 3e5 + 5;

int n, T, a[N], p[N], ans[N];

struct Tr{
    int l, r, siz, cnt;
    int add, mx;
}tr[N << 2];


void build(int u, int l, int r){
    tr[u].l = l, tr[u].r = r, tr[u].siz = r - l + 1;
    tr[u].add = tr[u].mx = 0;
    if(l != r){
        int mid = (l + r) >> 1;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
    }
}

void push_down(int u){
    int na = u << 1, nb = na | 1;
    if(tr[u].add != 0){
        tr[na].mx += tr[u].add, tr[na].add += tr[u].add;
        tr[nb].mx += tr[u].add, tr[nb].add += tr[u].add;
        tr[u].add = 0;
    }
    tr[u].mx = max(tr[na].mx, tr[nb].mx);
}

void op_add(int u, int st, int re, int val){
    int l = tr[u].l, r = tr[u].r;
    if(l > re || r < st) return;
    if(l >= st && r <= re){
        tr[u].mx += val, tr[u].add += val;
        return;
    }
    push_down(u);
    op_add(u << 1, st, re, val);
    op_add(u << 1 | 1, st, re, val);
    push_down(u);
}

void op_dev(int u, int plc, int val){
    int l = tr[u].l, r = tr[u].r;
    if(l > plc || r < plc) return;
    if(l >= plc && r <= plc){
        tr[u].mx = val;
        return;
    }
    push_down(u);
    op_dev(u << 1, plc, val);
    op_dev(u << 1 | 1, plc, val);
    push_down(u);
}

int qr_max(int u, int st, int re){
    int l = tr[u].l, r = tr[u].r;
    if(l > re || r < st) return 0;
    if(l >= st && r <= re) return tr[u].mx;
    push_down(u);
    return max(qr_max(u << 1, st, re), qr_max(u << 1 | 1, st, re));
}

void reset(){
    memset(ans, 0, sizeof ans);
    
}

void input(){
    n = read();
}

void solve(){
    build(1, 0, n);
    for(int i = 1; i <= n; i++){
        a[i] = read();
        op_dev(1, a[i], 0);
        op_add(1, 0, a[i] - 1, 1);
        ans[i] = qr_max(1, 0, n);
    }
}

    



int main(){
    T = read();
    int count = T;
    while(T--){
        input();
        reset();
        solve();
        // printf("test_%d : ", count - T);
        for(int i = 1; i <= n; i++) printf("%d ", ans[i]);
        printf("\n");
    }
    return 0;
}