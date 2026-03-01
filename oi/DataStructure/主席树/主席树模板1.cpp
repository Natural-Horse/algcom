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

const int N = 1e6 + 5;

struct Tree{
    int l, r;
    int ls, rs, val;
}tr[N * 24];
int n, a[N], m, pnt, rt[N];

int New(int u){
    tr[++pnt] = tr[u];
    return pnt;
}
int build(int u, int l, int r){
    u = ++pnt;
    tr[u].l = l, tr[u].r = r;
    if(l != r){
        int mid = (l + r) >> 1;
        tr[u].ls = build(tr[u].ls, l, mid), tr[u].rs = build(tr[u].rs, mid + 1, r);
        tr[u].val = tr[tr[u].ls].val + tr[tr[u].rs].val;
    }
    else tr[u].val = a[l];
    return u;
}
int op_dev(int u, int plc, int val){
    u = New(u);
    int l = tr[u].l, r = tr[u].r;
    if(l > plc || r < plc) return u;
    if(l == plc && r == plc) tr[u].val = val;
    int mid = (l + r) >> 1;
    if(plc <= mid) tr[u].ls = op_dev(tr[u].ls, plc, val);
    else tr[u].rs = op_dev(tr[u].rs, plc, val);
    return u;
}
int qr_val(int u, int plc){
    int l = tr[u].l, r = tr[u].r;
    if(l > plc || r < plc) return 0;
    if(l == plc && r == plc) return tr[u].val;
    int mid = (l + r) >> 1;
    if(plc <= mid) return qr_val(tr[u].ls, plc);
    else return qr_val(tr[u].rs, plc);
}

int main(){
    n = read(), m = read();
    for(int i = 1; i <= n; i++) a[i] = read();
    rt[0] = build(0, 1, n);
    for(int i = 1, ver, op, plc; i <= m; i++){
        ver = read(), op = read(), plc = read();
        if(op == 1){
            int val = read();
            rt[i] = op_dev(rt[ver], plc, val);
        }
        else {
            printf("%d\n", qr_val(rt[ver], plc));
            rt[i] = rt[ver];
        }
    }
    return 0;
}
