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

const int N = 2e5 + 5;

struct Tree{
    int l, r, ls, rs, cnt;
}tr[N * 20];
int n, m, a[N], ls[N], rt[N], tot, num, pnt;

int New(int u){
    tr[++pnt] = tr[u];
    return pnt;
}
inline void push_back(int u){
    int ls = tr[u].ls, rs = tr[u].rs;
    tr[u].cnt = tr[ls].cnt + tr[rs].cnt;
}
void build(int &u, int l, int r){
    u = ++pnt;
    tr[u].l = l, tr[u].r = r;
    if(l != r){
        int mid = (l + r) >> 1;
        build(tr[u].ls, l, mid), build(tr[u].rs, mid+1, r);
    }
}
int op_add(int u, int plc){
    u = New(u);
    int l = tr[u].l, r = tr[u].r;
    if(l > plc || r < plc) return u;
    if(l == plc && r == plc) {tr[u].cnt++; return u;}
    int mid = (l + r) >> 1;
    if(plc <= mid) tr[u].ls = op_add(tr[u].ls, plc);
    else tr[u].rs = op_add(tr[u].rs, plc);
    push_back(u); return u;
}
int qr_rk(int u, int v, int rk){
    int l = tr[u].l, r = tr[u].r;
    if(tr[u].l == tr[u].r) return tr[u].l;
    push_back(u);
    int sum = tr[tr[v].ls].cnt - tr[tr[u].ls].cnt;
    if(rk <= sum) return qr_rk(tr[u].ls, tr[v].ls, rk);
    else return qr_rk(tr[u].rs, tr[v].rs, rk - sum);
}

int main(){
    n = read(), m = read();
    for(int i = 1; i <= n; i++) ls[++tot] = a[i] = read();
    sort(ls + 1, ls + 1 + tot);
    num = unique(ls + 1, ls + 1 + tot) - ls - 1;
    build(rt[0], 1, num);
    for(int i = 1; i <= n; i++){
        a[i] = lower_bound(ls + 1, ls + 1 + num, a[i]) - ls;
        rt[i] = op_add(rt[i-1], a[i]);
    }
    for(int i = 1, l, r, k; i <= m; i++){
        l = read(), r = read(), k = read();
        printf("%d\n", ls[qr_rk(rt[l-1], rt[r], k)]);
    }
    return 0;
}
