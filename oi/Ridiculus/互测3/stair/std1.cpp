// 202831352
#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
#define low(a, b) lower_bound(vec[a].begin(), vec[a].end(), b)
#define upp(a, b) upper_bound(vec[a].begin(), vec[a].end(), b)
#define R register
using namespace std;

inline int read(){
	int x = 0, f = 1; char ch = getchar();
	while(!isdigit(ch)){if(ch == '-') f = -1; ch = getchar();}
	while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - 48; ch = getchar();}
	return x * f;
}

const int N = 1e5 + 5, M = 405;

int n, m, a[N], ls[N], tot, num;
int bl[N], S;
ll val[N], ans, tmp, las, k, cnt[M][N];
vector<int> vec[M];

inline int lb(int x){return x & -x;}
inline ll qr_val(int u){int res=0; for(R int i=u;i;i-=lb(i)) res+=val[i]; return res;}
inline void op_add(int u, ll v){for(R int i=u;i<=n;i+=lb(i)) val[i]+=v;}

inline void change(int l, int r){
	 if(bl[l] != bl[r]){
        vec[bl[l]].erase(low(bl[l],a[l])), vec[bl[l]].insert(upp(bl[l],a[r]), a[r]);
        vec[bl[r]].erase(low(bl[r],a[r])), vec[bl[r]].insert(upp(bl[r],a[l]), a[l]);
    	cnt[bl[l]][a[l]]--, cnt[bl[l]][a[r]]++;
    	cnt[bl[r]][a[r]]--, cnt[bl[r]][a[l]]++;
    }
    swap(a[l], a[r]);
}

inline int get(int l, int r, int val){
	int res = 0; tmp = 0;
	if(l > r) return 0;
	if(bl[l] == bl[r]){
		for(R int i = l; i <= r; i++){
			res += (a[i] < val);
			tmp += (a[i] == val);
		}
	}
	else{
		for(R int i = l; i <= min(n,bl[l]*S); i++) res += (a[i] < val), tmp += (a[i] == val);
		for(R int i = (bl[r]-1)*S+1; i <= r; i++) res += (a[i] < val), tmp += (a[i] == val);
		for(R int i = bl[l]+1; i < bl[r]; i++){
			res += low(i, val)-vec[i].begin();
			tmp += cnt[i][val];
		}
	}
	return res;
}
//
int main(){
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
	n = read(), m = read(), k = read();
	S = sqrt(n);
	for(R int i = 1; i <= n; i++) a[i] = read(), ls[++tot] = a[i];
	sort(ls + 1, ls + 1 + tot);
	num = unique(ls + 1, ls + 1 + tot) - ls - 1;
	for(R int i = 1; i <= n; i++){
	    a[i] = lower_bound(ls + 1, ls + 1 + num, a[i]) - ls;
		int tmp = qr_val(a[i]);
		ans += i - 1 - tmp; op_add(a[i], 1);
		bl[i] = ( i - 1 ) / S + 1;
		vec[bl[i]].push_back(a[i]);
		cnt[bl[i]][a[i]]++;
	}
	
	printf("%lld\n", ans);
	las = ans;
	for(R int i = 1; i <= bl[n]; i++) sort(vec[i].begin(), vec[i].end());
	for(R int i = 1, l, r; i <= m; i++){
		l = read(), r = read(); 
		ll faba = l, fabb = r;
		l = ((faba^(las*k%n)) + fabb*k%n - 1) % n + 1;
		r = ((fabb^(las*k%n)) + faba*k%n - 1) % n + 1;
		if(l == r){printf("%lld\n", ans); continue;}
		if(l > r) swap(l, r);
		ll len = r - l - 1;
		ll x1 = get(l+1,r-1,a[l]), y1 = len - tmp - x1;
		ll x2 = get(l+1,r-1,a[r]), y2 = len - tmp - x2;
		ans += x2 + y1 - x1 - y2;
		if(a[l] > a[r]) ans--;
		else if(a[l] < a[r]) ans++;
		printf("%lld\n", ans);
		las = ans;
		change(l, r);
	}
	return 0;
}
