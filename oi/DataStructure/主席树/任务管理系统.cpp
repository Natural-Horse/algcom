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

const int N = 1e5 + 5;

struct Tree{
    int l, r, ls, rs;
    ll cnt, val;
}tr[N * 100];
struct Q{
    int fab, val;
};
ll n, m, lasans = 1, rt[N], tot, lsh[N], tott, num, jud, lim;
vector<Q> op[N];

int build(int u, int l, int r){
    u = ++tot;
    jud = tot;
    tr[u].l = l, tr[u].r = r;
    if(l != r){
        int mid = (l + r) >> 1;
        tr[u].ls = build(u, l, mid), tr[u].rs = build(u, mid+1, r);
    }
    return u;
}
int New(int u){
    tr[++tot] = tr[u];
    jud = max(jud, tot);
    return tot;
}
void push_back(int u){
    int ls = tr[u].ls, rs = tr[u].rs;
    tr[u].cnt = tr[ls].cnt + tr[rs].cnt, tr[u].val = tr[ls].val + tr[rs].val;
}
void op_dev(int u, int fab, int val){
    int l = tr[u].l, r = tr[u].r;
    if(l == val && r == val){
        if(fab) tr[u].cnt++, tr[u].val += lsh[val];
        else tr[u].cnt--, tr[u].val -= lsh[val];
        return;
    }
    int mid = (l + r) >> 1;
    if(val <= mid){
        if(tr[u].ls <= lim) tr[u].ls = New(tr[u].ls);
        op_dev(tr[u].ls, fab, val);
    } 
    else {
        if(tr[u].rs <= lim) tr[u].rs = New(tr[u].rs);
        op_dev(tr[u].rs, fab, val);
    }
    if(tr[u].ls && tr[u].rs) push_back(u);
    return;
}
ll qr_val(int u, ll k){
    int l = tr[u].l, r = tr[u].r, ls = tr[u].ls, rs = tr[u].rs;
    if(!ls && !rs){
        if(tr[u].cnt == k) return tr[u].val;
        else return tr[u].val / tr[u].cnt * k;
    }
    if(tr[ls].cnt >= k) return qr_val(ls, k);
    else return tr[ls].val + qr_val(rs, k - tr[ls].cnt);
}

signed main(){
//    freopen("P3168_1.in", "r", stdin);
//    freopen("1.out", "w", stdout);
    m = read(), n = read();
    for(int i = 1, l, r, k; i <= m; i++){
        l = read(), r = read(), k = read();
        op[l].push_back((Q){1, k}), op[r+1].push_back((Q){0, k});
        lsh[++tott] = k;
    }
    sort(lsh + 1, lsh + 1 + tott);
    num = unique(lsh + 1, lsh + 1 + tott) - lsh - 1;
    rt[0] = build(1, 1, num);
    lim = jud;
    for(int i = 1; i <= n; i++){
        int sz = op[i].size();
        rt[i] = New(rt[i-1]);
        for(int j = 0; j < sz; j++){
            int val = lower_bound(lsh + 1, lsh + 1 + num, op[i][j].val) - lsh;
            op_dev(rt[i], op[i][j].fab, val);
        }
        lim = jud;
    }
    for(int i = 1, x, a, b, c; i <= n; i++){
        x = read(), a = read(), b = read(), c = read();
        ll k = 1 + (lasans * a + b) % c;
        if(tr[rt[x]].cnt <= k) lasans = tr[rt[x]].val;
        else lasans = qr_val(rt[x], k);
        printf("%lld\n", lasans);
    }
    return 0; 
}

