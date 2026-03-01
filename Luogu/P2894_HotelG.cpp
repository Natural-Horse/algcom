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

const int N = 5e4 + 5;

struct Tr{
    int l, r, siz, lmx, rmx, mmx, dev;
}tr[N << 2];
int n, m;

void build(int u, int l, int r){
    tr[u].l = l, tr[u].r = r, tr[u].dev = -1;
    tr[u].lmx = tr[u].mmx = tr[u].rmx = tr[u].siz = r - l + 1;
    if(l == r) return;
    int mid = (l + r) >> 1;
    build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
}

void push_down(int u){
    int na = u << 1, nb = na | 1;
    if(tr[u].dev == 0){
        tr[na].lmx = tr[na].mmx = tr[na].rmx = tr[na].siz;
        tr[na].dev = 0;
        tr[nb].lmx = tr[nb].mmx = tr[nb].rmx = tr[nb].siz;
        tr[nb].dev = 0;
        tr[u].dev = -1;  
    }
    else if(tr[u].dev == 1){
        tr[na].lmx = tr[na].mmx = tr[na].rmx = 0;
        tr[na].dev = 1;
        tr[nb].lmx = tr[nb].mmx = tr[nb].rmx = 0;
        tr[nb].dev = 1;
        tr[u].dev = -1; 
    }
}

void push_back(int u){
    int na = u << 1, nb = na | 1;
    tr[u].lmx = tr[na].lmx + (tr[na].lmx == tr[na].siz) * tr[nb].lmx;
    tr[u].mmx = max(tr[na].rmx + tr[nb].lmx, max(tr[na].mmx, tr[nb].mmx));
    tr[u].rmx = tr[nb].rmx + (tr[nb].rmx == tr[nb].siz) * tr[na].rmx;
}

void op_dev(int u, int st, int re, int val){
    int l = tr[u].l, r = tr[u].r;
    if(l > re || r < st) return;
    if(l >= st && r <= re){
        tr[u].lmx = tr[u].mmx = tr[u].rmx = (!val) * tr[u].siz;
        tr[u].dev = val;
        return;
    }
    push_down(u);
    op_dev(u << 1 | 1, st, re, val);
    op_dev(u << 1, st, re, val);
    push_back(u);
}

int flag = 0, mxLen, tmpLen;
void qr_mxlen(int u, int st, int re){
    int l = tr[u].l, r = tr[u].r;
    if(l > re || r < st) return;
    if(l >= st && r <= re){
        mxLen = max(mxLen, tr[u].mmx);
        if(flag == 0){
            tmpLen = tr[u].lmx, flag = 1;
        }
        else{
            mxLen = max(mxLen, tmpLen + tr[u].rmx);
            if(tr[u].rmx == tr[u].siz) tmpLen += tr[u].siz;
            else tmpLen = tr[u].lmx;
        }
        mxLen = max(mxLen, tmpLen);
        return;
    }
    push_down(u);
    qr_mxlen(u << 1 | 1, st, re);
    qr_mxlen(u << 1, st, re);
    push_back(u);
    return;
}

int solve(int l, int r, int len){
    while(l < r){
        int mid = (l + r) >> 1;
        flag = 0, mxLen = 0, tmpLen = 0;
        qr_mxlen(1, 1, mid);
        if(mxLen >= len) r = mid;
        else l = mid + 1;
    }
    return r;
}

int main(){
    n = read(), m = read();
    build(1, 1, n);
    for(int i = 1, op, x, y; i <= m; i++){
        op = read();
        if(op == 1){
            x = read();
            int plc = solve(x, n + 1, x);
            if(plc != n + 1){
                printf("%d\n", plc - x + 1);
                op_dev(1, plc - x + 1, plc, 1);
            } 
            else printf("%d\n", 0);
        }
        else{
            x = read(), y = read();
            op_dev(1, x, x + y - 1, 0);
        }
    }
    return 0;
}