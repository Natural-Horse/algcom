// clang-format off
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
#define pii pair<int, int>
#define mkp make_pair
// #define int long long
using namespace std;

inline int read(){
    int x = 0, f = 1; char ch = getchar();
    while(!isdigit(ch)){if(f == '-') f = -1; ch = getchar();}
    while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - 48; ch = getchar();}
    return x * f;
}

const int N = 2e5 + 5; 
int T, n, m, L, l[N], r[N], x[N], v[N], rk[N];
int ls[N << 3], tot, E, pos;
int b[N << 3], laspow[N << 3];
int st[N], top;
pii power[N];

bool check(int tim){
    E = 1, pos = 1;
    int add = 0, exp = 0;
    while(pos < tot){
        int des = upper_bound(ls + 1, ls + 1 + tot, ls[pos] + add + E) - ls - 1;
        int desadd = ls[pos] + add + E - ls[des];
        if(b[des]){
            int lef = l[b[des]];
            for(int i = laspow[pos] + 1; i <= laspow[lef]; i++) st[++top] = i;
        }
    }
}

signed main(){
    // freopen("1.out", "w", stdout);
    T = read();
    // (int i = 1; i <= 200; i++) printf("%d : %d\n", i, pre[i]);
    while(T--){
        n = read(), m = read(), L = read();
        ls[++tot] = 1, ls[++tot] = L;
        for(int i = 1; i <= n; i++){
            l[i] = read(), r[i] = read();
            ls[++tot] = l[i], ls[++tot] = r[i];
            ls[++tot] = l[i] - 1, ls[++tot] = r[i] + 1;
        }
        for(int i = 1; i <= m; i++){
            x[i] = read(), v[i] = read();
            ls[++tot] = x[i];
        }
        sort(ls + 1, ls + 1 + tot);
        tot = unique(ls + 1, ls + 1 + tot) - ls - 1;
        for(int i = 1; i <= n; i++){
            l[i] = lower_bound(ls + 1, ls + 1 + tot, l[i]) - ls;
            r[i] = lower_bound(ls + 1, ls + 1 + tot, r[i]) - ls;
            for(int j = l[i]; j <= r[i]; j++) b[j] = i;
        }
        for(int i = m; i >= 1; --i){
            x[i] = lower_bound(ls + 1, ls + 1 + tot, x[i]) - ls;
            for(int j = x[i]; j <= x[i+1] - 1; j++) laspow[j] = i;
            mkp(x[i], v[i]);
        }
        sort(power + 1, power + 1 + m);
        for(int i = 1; i <= m; i++) rk[power[i].second] = i;
        int l = 0, r = m + 1;
        while(l < r){
            int mid = (l + r) >> 1;
            if(check(mid)) r = mid;
            else l = mid + 1;
        }
    }
    return 0;
}