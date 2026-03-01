#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
#define db double
#define R register
using namespace std;

inline int read(){
	int x = 0, f = 1; char ch = getchar();
	while(!isdigit(ch)){if(ch == '-') f = -1; ch = getchar();}
	while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - 48; ch = getchar();}
	return x * f;
}

const int N = 1e5 + 5, M = 405;

int n, m, S, P, a[N], ls[N], tot, num, bl[N], cl[N], g[M][M], f[M][N], val[N];
ll ans, tmp, k;

inline int lb(int x){return x & -x;}
inline void op_add(int u,int v){for(int i=u;i<=num;i+=lb(i)) val[i]+=v;}
inline int qr_val(int u){int res=0; for(int i=u;i;i-=lb(i)) res+=val[i]; return res;}

inline void change(int l, int r){
    if(bl[l] != bl[r]){
        for(R int i = bl[l]; i < bl[r]; i++){
            g[i][cl[a[l]]]--, g[i][cl[a[r]]]++;
            f[i][a[l]]--, f[i][a[r]]++;
        }         
    }
    swap(a[l], a[r]);
}

inline int get(int l, int r, int val){
    int res = 0; tmp = 0;
    if(l > r) return 0;
    if(l == r){
    	for(int i = l; i <= r; i++) tmp += (a[i] > val), res += (a[i] < val);
    	return res;
    }
    for(R int i = cl[val]+1; i <= cl[num]; i++) tmp += g[bl[r]-1][i] - g[bl[l]][i];
    for(R int i = val+1; i <= min(cl[val]*P,num); i++) tmp += f[bl[r]-1][i] - f[bl[l]][i];
    for(R int i = 1; i < cl[val]; i++) res += g[bl[r]-1][i] - g[bl[l]][i];
    for(R int i = (cl[val]-1)*P+1; i < val; i++) res += f[bl[r]-1][i] - f[bl[l]][i];
    for(R int i = l; i <= bl[l]*S; i++) tmp += (a[i] > val), res += (a[i] < val);
    for(R int i = (bl[r]-1)*S+1; i <= r; i++) tmp += (a[i] > val), res += (a[i] < val);
    return res;
}

int main(){
//    freopen("1.in", "r", stdin);
//    freopen("out.out", "w", stdout);
    n = read(); S = sqrt(n);
    for(int i = 1; i <= n; i++) a[i] = read(), ls[++tot] = a[i];
    sort(ls + 1, ls + 1 + tot);
    num = unique(ls + 1, ls + 1 + tot) - ls - 1;
    P = sqrt(num);
    for(R int i = 1; i <= n; i++){
        a[i] = lower_bound(ls + 1, ls + 1 + num, a[i]) - ls;
        ll jud = qr_val(a[i]);
        ans += (ll)(i - 1 - jud); op_add(a[i], 1);
        bl[i] = (i-1) / S + 1, cl[a[i]] = (a[i]-1) / P + 1;
        g[bl[i]][cl[a[i]]]++, f[bl[i]][a[i]]++;
    }
    m = read();
    printf("%lld\n", ans);
    for(R int i = 1; i <= bl[n]; i++){
        for(R int j = 1; j <= cl[num]; j++) g[i][j] += g[i-1][j];
        for(R int j = 1; j <= num; j++) f[i][j] += f[i-1][j];
    }
    for(R int i = 1, l, r; i <= m; i++){
        l = read(), r = read();
        if(l == r){
            printf("%lld\n", ans);
            continue;
        }
        if(l > r) swap(l, r);
		ll x1 = get(l+1,r-1,a[l]), y1 = tmp;
		ll x2 = get(l+1,r-1,a[r]), y2 = tmp;
		ans += x2 + y1 - x1 - y2;
		if(a[l] > a[r]) ans--;
		else if(a[l] < a[r]) ans++;
		printf("%lld\n", ans);
		change(l, r);
    }
    return 0;
}
