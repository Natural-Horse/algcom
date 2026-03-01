#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
#define db double
#define int long long
using namespace std;

inline int read(){
	int x = 0, f = 1; char ch = getchar();
	while(!isdigit(ch)){if(ch == '-') f = -1; ch = getchar();}
	while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - 48; ch = getchar();}
	return x * f;
}

const int N = 1e5 + 5;

struct Nd{
    int t, w;
}a[N];
int n, m, val[N], s[N], f[N];

int lb(int x){return x & -x;}
void op_add(int u, int v){for(int i=u;i<=n;i+=lb(i)) val[i]+=v;}
int qr_val(int u){int res=0; for(int i=u;i;i-=lb(i)) res+=val[i]; return res;}
bool cmpa(Nd aa, Nd bb){
    if(aa.t == bb.t) return aa.w < bb.w;
    return aa.t < bb.t;
}
bool cmpb(Nd aa, Nd bb){
    if(aa.t == bb.t) return aa.w < bb.w;
    return aa.t > bb.t;
}

void cdq(int l, int r){
    if(l == r) return;
    int mid = (l + r) >> 1;
    cdq(l, mid);
    cdq(mid + 1, r);
    sort(a + l, a + mid + 1, cmpb), sort(a + mid + 1, a + r + 1, cmpb);
    int i = l, j = mid + 1;
    for(; j <= r; j++){
        while(a[i].t >= a[j].t && i <= mid) op_add(a[i].w, 1), i++;
        s[a[j].t] += i - l - qr_val(a[j].w); 
    }
    for(j = l; j < i; j++) op_add(a[j].w, -1);
    i = l, j = mid + 1;
    for(; i <= mid; i++){
        while(a[j].t > a[i].t && j <= r) op_add(a[j].w, 1), j++;
        s[a[i].t] += qr_val(a[i].w - 1);
    }
    for(i = mid+1; i < j; i++) op_add(a[i].w, -1);
    return;
}

signed main(){
    n = read(), m = read();
    for(int i = 1; i <= n; i++) a[i].w = read(), a[i].t = n, f[a[i].w] = i; 
    for(int i = 1, x; i <= m; i++) x = read(), a[f[x]].t = i; 
//    printf("T : ");
//    for(int i = 1; i <= n; i++) printf("%d ", a[i].t);
//    printf("\n");
    cdq(1, n);
    for(int i = n; i; --i) s[i] = s[i] + s[i+1];
//    printf("-------------- FAB --------------\n");
    for(int i = 1; i <= m; i++) printf("%lld\n", s[i]);
    return 0;
}

