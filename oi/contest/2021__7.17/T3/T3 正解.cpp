#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

ll read(){
	ll x = 0,f = 1;char ch = getchar();
	while (ch < '0' || ch > '9'){if (ch == '-') f = -1; ch = getchar();}
	while (ch >= '0' && ch <= '9'){x = x*10 + ch - 48; ch = getchar();}
	return x * f;
}

const int N = 1e5 + 5;

struct E{
	ll x, a;
	int id;
}d[N];
int n, k;
int now;
ll p[N], ln[N], tot, num;
int mx[N], f[N];

int lowbit(int x){return x & -x;} 
bool cmp(E aa, E bb){
	return aa.x < bb.x;
}
int query_mx(int u){
	int res = 0;
	for(int i = u; i; i -= lowbit(i)) res = max(res, mx[i]);
	return res;
}
void op_update(int u, int val){
	for(int i = u; i <= n; i += lowbit(i)) mx[i] = max(mx[i], val);
	return;
}
bool check(int t){
	memset(mx, 0, sizeof(mx));
	memset(p, 0, sizeof(p));
	memset(ln, 0, sizeof(ln));
	now = 0;
	for(int i = 1; i <= n; i++){
		ln[i] = p[i] = 2 * d[i].x + d[i].a * (ll)t * (ll)t;
	}
	sort(ln + 1, ln + 1 + n);
	num = unique(ln + 1, ln + 1 + n) - ln - 1;
	for(int i = 1; i <= n; i++){
		p[i] = lower_bound(ln + 1, ln + 1 + num, p[i]) - ln;
		int tmp = query_mx(p[i]-1); op_update(p[i], tmp+1); 
	}
	now = query_mx(n);
	return now >= k;
}

int fa[N][30], mn[N][30], ans[N];
pair<int, int> tr[N];

bool getmin(pair<int,int> aa, pair<int,int> bb){
	if(aa.first != bb.first) return aa.first < bb.first;
	int mina = aa.second, minb = bb.second, xx = aa.second, yy = bb.second;
	for(int i = 20; i >= 0; --i){
		if(fa[xx][i] != fa[yy][i]){
			mina = min(mina, mn[xx][i]), minb = min(minb, mn[yy][i]);
			xx = fa[xx][i], yy = fa[yy][i];
		}
	}
	return mina > minb;
}
pair<int,int> query_mx_(int u){
	pair<int,int> res = make_pair(0, 0);
	for(int i = u; i; i -= lowbit(i)) 
		if(getmin(res, tr[i])) res = tr[i];
	return res;
}
void op_update_(int u, pair<int,int> pr){
	for(int i = u; i <= n; i += lowbit(i))
		if(getmin(tr[i], pr)) tr[i] = pr;
}
void get_father(int u, int father){
	fa[u][0] = mn[u][0] = father;
	for(int i = 1; i <= 22; i++){
		fa[u][i] = fa[fa[u][i-1]][i-1];
		mn[u][i] = min(mn[u][i-1], mn[fa[u][i-1]][i-1]);
	} 
}

int main(){
	memset(mn, 0x3f, sizeof(mn));
	n = read(), k = read();
	for(int i = 1; i <= n; i++) d[i].x = read(), d[i].a = read(), d[i].id = i;
	sort(d + 1, d + 1 + n, cmp);
	int l = 1, r = 86400, tt = 1;
	while(l < r){
		int mid = (l + r + 1) >> 1;
		if(check(mid)) l = mid, tt = mid;
		else r = mid - 1;
	}
	check(tt);
	printf("%d\n", tt);
	if(now > k) {
		printf("-1");
		return 0;
	}
	for(int i = 1; i <= n; i++)
		ln[i] = p[i] = (ll)tt * (ll)tt * d[i].a + 2 * d[i].x;
	sort(ln + 1, ln + 1 + n);
	num = unique(ln + 1, ln + 1 + n) - ln - 1;
	for(int i = 1; i <= n; i++){
		p[i] = lower_bound(ln + 1, ln + 1 + n, p[i]) - ln;
		pair<int,int> jud = query_mx_(p[i]-1);
		get_father(d[i].id, jud.second);
		pair<int,int> fab = make_pair(jud.first + 1, d[i].id);
		op_update_(p[i], fab);
	}
	now = query_mx_(n).second;
	for(int i = 1; i <= k; i++){
		ans[i] = now;
		now = fa[now][0];
	}
	sort(ans + 1, ans + 1 + k);
	for(int i = 1; i <= k; i++) printf("%d\n", ans[i]);
	return 0;
}
