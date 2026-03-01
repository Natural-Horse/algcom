// clang-format off
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

inline int read(){
    int x = 0, f = 1; char ch = getchar();
    while(!isdigit(ch)){if(ch == '-') f = -1; ch = getchar();}
    while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - 48; ch = getchar();}
    return x * f;
}

const int N = 1e5 + 5;

struct Tr{
    int l, r, siz, mx;
}tr[N << 2];
int n, nxt[N], a[N], b[N];
vector<int> plc[N];

void build(int u, int l, int r){
    tr[u].l = l, tr[u].r = r, tr[u].siz = r - l + 1, tr[u].mx = 0;
    if(l == r) return;
    int mid = (l + r) >> 1;
    build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
}

void push_back(int u){
    int na = u << 1, nb = na | 1;
    // tr[na].mx = max(tr[u].mx, tr[u].mx), tr[nb].mx = max(tr[nb].mx, tr[u].mx);
    tr[u].mx = max(tr[u].mx, max(tr[na].mx, tr[nb].mx));
}

void op_dev(int u, int st, int re, int val){
    int l = tr[u].l, r = tr[u].r;
    if(l > re || r < st) return;
    if(l >= st && r <= re){
        tr[u].mx = max(tr[u].mx, val);
        return;
    }
    push_back(u);
    op_dev(u << 1, st, re, val), op_dev(u << 1 | 1, st, re, val);
    push_back(u);
}
int qr_mx(int u, int st, int re){
    int l = tr[u].l, r = tr[u].r;
    if(l > re || r < st) return 0;
    if(l >= st && r <= re) return tr[u].mx;
    push_back(u);
    int jud1 = qr_mx(u << 1, st, re);
    int jud2 = qr_mx(u << 1 | 1, st, re);
    push_back(u);
    return max(jud1, jud2);
}

int main(){
    n = read(); n *= 5;
    for(int i = 1; i <= n; i++) a[i] = read();
    for(int i = 1; i <= n; i++){
        b[i] = read();
        plc[b[i]].push_back(i);
    }
    build(1, 1, n);
    for(int i = 1; i <= n; i++){
        for(int j = plc[a[i]].size() - 1; j >= 0; --j){
            int p = plc[a[i]][j];
            int jud = qr_mx(1, 1, p - 1);
            op_dev(1, p, p, jud + 1);
        }
    }
    printf("%d\n", qr_mx(1, 1, n));
    return 0;
}