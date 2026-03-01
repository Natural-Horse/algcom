#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
#define db double
// #define int long long
using namespace std;

inline int read(){
	int x = 0, f = 1; char ch = getchar();
	while(!isdigit(ch)){if(ch == '-') f = -1; ch = getchar();}
	while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - 48; ch = getchar();}
	return x * f;
}

const int N = 4e5 + 5;

struct Q{
    int l, r, id, rk, typ;
}q[N], q1[N], q2[N];
int n, m, a[N], ls[N], tot, ans[N], c[N];
int tr[N];

inline int lb(int x){return x & -x;}
void op_add(int u,int v){for(int i=u;i<=tot;i+=lb(i)) tr[i]+=v;}
int qr_cnt(int u){int res=0; for(int i=u;i;i-=lb(i)) res+=tr[i]; return res;}

void solve(int l, int r, int ql, int qr){
    if(ql > qr) return;
    if(l == r){
        for(int i = ql; i <= qr; i++) 
            if(q[i].typ) ans[q[i].id] = ls[l];
        return;
    }
    int mid = (l + r) >> 1;
    int p1 = 0, p2 = 0;
    for(int i = ql; i <= qr; i++){
        if(!q[i].typ){
            if(c[q[i].id] <= mid){
                op_add(q[i].id, 1);
                q1[++p1] = q[i];
            }
            else q2[++p2] = q[i];
        }
        else{
            int jud = qr_cnt(q[i].r) - qr_cnt(q[i].l - 1);
            if(q[i].rk <= jud) q1[++p1] = q[i];
            else{
                q[i].rk -= jud;
                q2[++p2] = q[i];
            }
        }
    }
    for(int i = ql; i <= qr; i++){
        if(!q[i].typ && c[q[i].id] <= mid) op_add(q[i].id, -1);
    }
    for(int i = 1; i <= p1; i++) q[ql+i-1] = q1[i];
    for(int i = 1; i <= p2; i++) q[ql+p1-1+i] = q2[i];
    solve(l, mid, ql, ql + p1 - 1);
    solve(mid + 1, r, ql + p1, qr);
}

int main(){
    n = read(), m = read();
    // build(1, 1, n);
    for(int i = 1; i <= n; i++){
        a[i] = read(); ls[++tot] = a[i];
    }
    sort(ls + 1, ls + 1 + tot);
    tot = unique(ls + 1, ls + 1 + tot) - ls - 1;
    for(int i = 1; i <= n; i++){
        int plc = lower_bound(ls + 1, ls + 1 + tot, a[i]) - ls;
        c[i] = plc;
        q[i] = {0, 0, i, 1, 0};
    }
    for(int i = 1; i <= m; i++){
        q[i + n].l = read(), q[i + n].r = read(), q[i + n].rk = read();
        q[i + n].id = i, q[i + n].typ = 1;
    }
    solve(1, tot, 1, m + n);
    for(int i = 1; i <= m; i++) printf("%d\n", ans[i]);
    return 0;
}