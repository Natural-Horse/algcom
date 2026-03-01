// clang-format off
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
#define pii pair<int, int>
#define int long long
using namespace std;

inline int read(){
    int x = 0, f = 1; char ch = getchar();
    while (!isdigit(ch)){if (f == '-') f = -1; ch = getchar();}
    while (isdigit(ch)){x = (x << 3) + (x << 1) + ch - 48; ch = getchar();}
    return x * f;
}

const int N = 1e5 + 5;

struct Tr{
    int l, r, siz, cnt, dev, cls;
}tr[N << 2];
// struct Q{
//     int plc, val;
// }les[N], gre[N];
int n, m, q, k, cnt1, cnt2;
vector<int> a[N], v[N];
char op[N];

void build(int u, int l, int r){
    tr[u].l = l, tr[u].r = r, tr[u].siz = tr[u].cnt = r - l + 1;
    tr[u].dev = 0;
    if(l == r) return;
    int mid = (l + r) >> 1;
    build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
}
void push_down(int u){
    int na = u << 1, nb = na | 1;
    if(tr[u].cls){
        tr[na].cnt = tr[na].siz, tr[nb].cnt = tr[nb].siz;
        tr[na].dev = tr[nb].dev = 0;
        tr[na].cls = tr[nb].cls = 1;
        tr[u].cls = 0;
    }
    if(tr[u].dev){
        tr[na].cnt = tr[nb].cnt = 0;
        tr[na].dev = tr[nb].dev = 1;
        tr[u].dev = 0;
    }
}
void push_back(int u){
    int na = u << 1, nb = na | 1;
    tr[u].cnt = tr[na].cnt + tr[nb].cnt;
}

void op_dev(int u, int st, int re){
    int l = tr[u].l, r = tr[u].r;
    if(l > re || r < st) return;
    if(l >= st && r <= re){
        tr[u].cnt = 0, tr[u].dev = 1;
        return;
    }
    push_down(u);
    op_dev(u << 1, st, re), op_dev(u << 1 | 1, st, re);
    push_back(u);
}
int qr_cnt(int u, int st, int re){
    int l = tr[u].l, r = tr[u].r;
    if(l > re || r < st) return 0;
    if(l >= st && r <= re){
        return tr[u].cnt;
    }
    push_down(u);
    return qr_cnt(u << 1, st, re) + qr_cnt(u << 1 | 1, st, re);
    push_back(u);
}
int res;
int qr_plc(int u){
    if(tr[u].siz == 1){
        if(tr[u].l == n && tr[u].cnt == 0) return -1;
        return tr[u].l;
    }
    int na = u << 1, nb = na | 1;
    push_down(u);
    if(tr[na].cnt >= 1) return qr_plc(na);
    else return qr_plc(nb);
}

signed main(){
    // freopen("ans.out", "w", stdout);
    n = read(), m = read(), q = read();
    for(int i = 1; i <= n; i++){
        a[i].push_back(0);
        for(int j = 1; j <= m; j++){
            a[i].push_back(read());
            if(i > 1) v[j].push_back(v[j][i-1] | a[i][j]);
            else{
                // v[j].clear();
                v[j].push_back(0);
                v[j].push_back(a[i][j]);
            }
            // printf("%d ", v[j][i]);
        }
        // printf("\n");
    }
    // for(int i = 0; i < n; i++){
    //     for(int j = 1; j <= m; j++) printf("%d ", v[j][i]);
    //     printf("\n");
    // } 
    build(1, 1, n);
    while(q--){
        tr[1].cls = 1;
        tr[1].cnt = n, tr[1].dev = 0;
        
        k = read();
        for(int i = 1, fab1, fab2; i <= k; i++){
            fab1 = read();
            char fab3 = getchar();
            fab2 = read();
            if(fab3 == '<'){
                int plc = lower_bound(v[fab1].begin() + 1, v[fab1].end(), fab2) - (v[fab1].begin());
                if(plc <= n) op_dev(1, plc, n);
            }
            else{
                int plc = upper_bound(v[fab1].begin() + 1, v[fab1].end(), fab2) - (v[fab1].begin());
                if(plc - 1 >= 1) op_dev(1, 1, plc - 1);
            }
        }
        int plc = qr_plc(1);
        printf("%lld\n", plc);
    }
    return 0;
}