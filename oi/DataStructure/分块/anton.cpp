#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
#define db double
#define low(a, b) lower_bound(vec[a].begin(), vec[a].end(), b)
#define upp(a, b) upper_bound(vec[a].begin(), vec[a].end(), b)
#define int long long
using namespace std;

inline int read(){
	int x = 0, f = 1; char ch = getchar();
	while(!isdigit(ch)){if(ch == '-') f = -1; ch = getchar();}
	while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - 48; ch = getchar();}
	return x * f;
}

const int N = 2e5 + 5;

int n, k, a[N], S;
int bl[N], ans;
vector<int> vec[N];

void op_chg(int l, int r){
    if(bl[l] != bl[r]){
        vec[bl[l]].erase(low(bl[l],a[l])), vec[bl[l]].insert(upp(bl[l],a[r]), a[r]);
        vec[bl[r]].erase(low(bl[r],a[r])), vec[bl[r]].insert(upp(bl[r],a[l]), a[l]);
    }
    swap(a[l], a[r]);
}
int qr_cnt(int l, int r, int val){
    int res = 0;
    if(l > r) return 0;
    if(bl[l] == bl[r]){
        for(int i = l; i <= r; i++){
            if(a[i] < val) res++;
        }
    }
    else{
        for(int i = l; i <= min(n,bl[l]*S); i++) if(a[i] < val) res++;
        for(int i = (bl[r]-1)*S+1; i <= r; i++) if(a[i] < val) res++;
        for(int i = bl[l]+1; i < bl[r]; i++) res += low(i, val) - vec[i].begin();
    }
    return res;
}

signed main(){
    n = read(), k = read(); S = sqrt(n);
    for(int i = 1; i <= n; i++){
        a[i] = i;
        bl[i] = (i-1)/S + 1;
        vec[bl[i]].push_back(i);
    }
    for(int i = 1, l, r; i <= k; i++){
        l = read(), r = read();
        if(l > r) swap(l, r);
        if(l == r) {printf("%d\n", ans); continue;}
        int faba = qr_cnt(l+1, r-1, a[l]), fabb = qr_cnt(l+1, r-1, a[r]);
        ans += (fabb - faba) * 2;
        if(a[l] < a[r]) ans++;
        else ans--;
        op_chg(l, r);
        printf("%lld\n", ans);
    }
    return 0;
}

