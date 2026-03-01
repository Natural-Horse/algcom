#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
#define ul unsigned long long
#define db double
using namespace std;

inline ul read(){
	ul x = 0, f = 1; char ch = getchar();
	while(!isdigit(ch)){if(ch == '-') f = -1; ch = getchar();}
	while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - 48; ch = getchar();}
	return x * f;
}

const int N = 6e5 + 5;

struct Qr{
    int id;
    __int128 tot;
}q[N], q1[N], q2[N];
int n, m, k, ans[N], L[N], R[N];
__int128 w[N], tr[N];
vector<int> vec[N];
// bool b[N];

int lb(int x){return x & -x;}
void add(int u, __int128 v){for(int i=u;i<=(m<<1);i+=lb(i)) tr[i]+=v;}
__int128 qr_sum(int u){__int128 res=0; for(int i=u;i;i-=lb(i)) res+=tr[i]; return res;}

void solve(int l, int r, int ql, int qr){
    if(ql > qr) return;
    if(l == r){
        for(int i = ql; i <= qr; i++) ans[q[i].id] = l;
        return;
    }
    int mid = (l + r) >> 1;
    for(int i = l; i <= mid; i++){
        add(L[i], w[i]), add(R[i] + 1, -w[i]);
    }
    int p1 = 0, p2 = 0;
    for(int i = ql; i <= qr; i++){
        __int128 sum = 0;
        for(auto plc : vec[q[i].id]){
            sum += qr_sum(plc) + qr_sum(plc+m);
        }
        if(sum < q[i].tot){
            q[i].tot -= sum;
            q2[++p2] = q[i];
            // q2[p2].tot -= sum;
        }
        else q1[++p1] = q[i];
    }
    for(int i = l; i <= mid; i++)
        add(L[i], -w[i]), add(R[i] + 1, w[i]);
    for(int i = 1; i <= p1; i++) q[ql+i-1] = q1[i], q1[i] = {0, 0};
    for(int i = 1; i <= p2; i++) q[ql+p1+i-1] = q2[i], q2[i] = {0, 0};
    solve(l, mid, ql, ql + p1 - 1);
    solve(mid+1, r, ql + p1, qr);
}

int main(){
    n = read(), m = read();
    for(int i = 1, plc; i <= m; i++) plc = read(), vec[plc].push_back(i);
    for(int i = 1; i <= n; i++) q[i] = {i, read()};
    k = read();
    for(int i = 1; i <= k; i++){
        L[i] = read();
        R[i] = read();
        w[i] = read();
        if(L[i] > R[i]) R[i] += m;
    }
    solve(1, k+1, 1, n);
    for(int i = 1; i <= n; i++){
        if(ans[i] == k+1) printf("NIE\n");
        else printf("%d\n", ans[i]);
    }
    return 0;
}