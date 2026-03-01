#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
#define db double
#define low(a, b) lower_bound(vec[a].begin(), vec[a].end(), b)
#define upp(a, b) upper_bound(vec[a].begin(), vec[a].end(), b)
using namespace std;

inline int read(){
	int x = 0, f = 1; char ch = getchar();
	while(!isdigit(ch)){if(ch == '-') f = -1; ch = getchar();}
	while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - 48; ch = getchar();}
	return x * f;
}

const int N = 2e4 + 5, M = 205;

int n, m, bl[N], a[N], ls[N], tot, num, S;  
ll ans, val[N], tmp, cnt[M][N];
vector<int> vec[N];

int lb(int x){return x & -x;}
void op_add(int u, ll v){for(int i=u;i<=num;i+=lb(i)) val[i]+=v;}
ll qr_val(int u){int res=0; for(int i=u;i;i-=lb(i)) res+=val[i]; return res;}

void change(int l, int r){
    if(bl[l] != bl[r]){
        vec[bl[l]].erase(low(bl[l],a[l])), vec[bl[l]].insert(upp(bl[l],a[r]), a[r]);
        vec[bl[r]].erase(low(bl[r],a[r])), vec[bl[r]].insert(upp(bl[r],a[l]), a[l]);
    }
    swap(a[l], a[r]);
}
ll get(int l, int r, int val){
    int res = 0, jud = 0, all = 0; tmp = 0;
    if(l > r) return 0;
    if(bl[l] == bl[r])
        for(int i = l; i <= r; i++){
            res += (a[i] > val);
            if(jud += )
        } 
    else{
        for(int i = l; i <= S*bl[l]; i++) res += (a[i] > val), tmp += (a[i] < val);
        for(int i = S*(bl[r]-1)+1; i <= r; i++) res += (a[i] > val), tmp += (a[i] < val);
        for(int i = l+1; i < r; i++){
            ll sz = vec[i].size();
            res += low(i, val-1) - vec[i].begin();
            tmp += sz - (upp(i, val-1) - vec[i].begin());
        } 
    }
    return res;
}

int main(){
    n = read(); S = sqrt(n);
    for(int i = 1; i <= n; i++) a[i] = read(), ls[++tot] = a[i];
    sort(ls + 1, ls + 1 + tot);
    num = unique(ls + 1, ls + 1 + n) - ls - 1;
    for(int i = 1; i <= n; i++) a[i] = lower_bound(ls + 1, ls + 1 + num, a[i]) - ls;
    for(int i = 1; i <= n; i++){
        ans += i - 1 - qr_val(a[i]);
        op_add(a[i], 1);
        bl[i] = (i-1) / S + 1;
        vec[bl[i]].push_back(a[i]), cnt[bl[i]][a[i]]++;
    }
    m = read();
    printf("%lld\n", ans);
    for(int i = 1; i <= bl[n]; i++) sort(vec[i].begin(), vec[i].end());
    for(int i = 1, l, r; i <= m; i++){
        l = read(), r = read();
        if(l > r) swap(l, r);
        if(l == r){printf("%lld\n", ans); continue;}
        ll len = r - l + 1;
        ll x1 = get(l+1, r-1, a[l]), y1 = tmp;
        ll x2 = get(l+1, r-1, a[r]), y2 = tmp;
        ans += (x1 + y2 - x2 - y1);
        if(a[l] < a[r]) ans++;
        else if(a[l] > a[r]) ans--;
        change(l, r);
        printf("%lld\n", ans);
    }
    return 0;
}

