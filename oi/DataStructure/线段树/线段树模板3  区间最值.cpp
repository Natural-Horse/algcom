#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

const int Maxn = 5e5 + 5;

int read(){
	int x = 0,f = 1;char ch = getchar();
	while (ch < '0' || ch > '9'){if (ch == '-') f = -1; ch = getchar();}
	while (ch >= '0' && ch <= '9'){x = x*10 + ch - 48; ch = getchar();}
	return x * f;
}

struct Tree{
	int l, r, siz;
	ll maxn, maxh;
	ll add, add_, addh, addh_;
	ll sum, cnt, sec;
}tr[Maxn * 4];

int n, m;
ll a[Maxn];

ll max_(ll x1, ll x2){
	return x1 >= x2? x1: x2;
}

void push_up(int u){
	int na = u << 1, nb = na | 1;
	if(tr[na].maxn == tr[nb].maxn){
		tr[u].maxn = tr[na].maxn;
		tr[u].cnt = tr[na].cnt + tr[nb].cnt;
		tr[u].sec = max_(tr[na].sec, tr[nb].sec);
	}
	else{
		if(tr[na].maxn >= tr[nb].maxn){
			tr[u].maxn = tr[na].maxn;
			tr[u].cnt = tr[na].cnt;
			tr[u].sec = max_(tr[nb].maxn, tr[na].sec);
		}
		else{
			tr[u].maxn = tr[nb].maxn;
			tr[u].cnt = tr[nb].cnt;
			tr[u].sec = max_(tr[na].maxn, tr[nb].sec);
		}
	}
	tr[u].maxh = max_(tr[na].maxh, tr[nb].maxh);
	tr[u].sum = tr[na].sum + tr[nb].sum;
}

void build(int u, int l, int r){
	tr[u].l = l, tr[u].r = r, tr[u].siz = r - l + 1;
	if(l != r){
		int na = u << 1, nb = na | 1, mid = (l + r) >> 1;
		build(na, l, mid);
		build(nb, mid + 1, r);
		tr[u].maxn = max(tr[na].maxn, tr[nb].maxn);
		tr[u].sum = tr[na].sum + tr[nb].sum;
		push_up(u);
	}
	else{
		tr[u].maxh = tr[u].maxn = a[l];
		tr[u].sum = a[l];
		tr[u].cnt = 1, tr[u].sec = -inf;
	}
}
// 最大值加的数，历史最值加的数，非最值加的数，历史非最值加的数  
void update(int u, ll x1, ll x2, ll x3, ll x4){
	tr[u].sum += x1 * (ll)tr[u].cnt + x3 * (ll)(tr[u].siz - tr[u].cnt);
	tr[u].maxh = max_(tr[u].maxh, tr[u].maxn + x2);
	tr[u].addh = max_(tr[u].addh, tr[u].add + x2);	
	tr[u].addh_ = max_(tr[u].addh_, tr[u].add_ + x4);
	tr[u].maxn += x1;
	tr[u].add += x1;
	tr[u].add_ += x3;
	if(tr[u].sec != -inf) tr[u].sec += x3;
}

void push_down(int u){
	int na = u << 1, nb = na | 1;
	ll maxn = max_(tr[na].maxn, tr[nb].maxn);
	if(tr[na].maxn == maxn) update(na, tr[u].add, tr[u].addh, tr[u].add_, tr[u].addh_);
	else update(na, tr[u].add_, tr[u].addh_, tr[u].add_, tr[u].addh_);
	if(tr[nb].maxn == maxn) update(nb, tr[u].add, tr[u].addh, tr[u].add_, tr[u].addh_);
	else update(nb, tr[u].add_, tr[u].addh_, tr[u].add_, tr[u].addh_);
	tr[u].add = tr[u].add_ = tr[u].addh = tr[u].addh_ = 0;
}

void dev(int u, int st, int re, ll val){
	int l = tr[u].l, r = tr[u].r;
	int na = (u << 1), nb = na | 1;
	if(l > re || r < st || val >= tr[u].maxn) return;
	if(l >= st && r <= re && val > tr[u].sec){
		update(u, val - tr[u].maxn, val - tr[u].maxn, 0, 0);
		return;
	}
	push_down(u);
	dev(na, st, re, val);
	dev(nb, st, re, val);
	push_up(u);
}

void add(int u, int st, int re, ll val){
	int l = tr[u].l, r = tr[u].r;
	if(l > re || r < st) return;
	if(l >= st && r <= re){
		update(u, val, val, val, val);
		return;
	}
	push_down(u);
	add((u << 1), st, re, val);
	add(((u << 1) | 1), st, re, val);
	push_up(u);
}

ll query_sum(int u, int st, int re){
	int l = tr[u].l, r = tr[u].r;
	if(l > re || r < st) return 0;
	if(l >= st && r <= re){
		return tr[u].sum;
	}
	push_down(u);
	return query_sum((u << 1), st, re) + query_sum(((u << 1) | 1), st, re);
}

ll query_maxn(int u, int st, int re){
	int l = tr[u].l, r = tr[u].r;
	if(l > re || r < st) return -inf;
	if(l >= st && r <= re){
		return tr[u].maxn;
	}
	push_down(u);
	return max_(query_maxn((u << 1), st, re), query_maxn(((u << 1) | 1), st, re));
}

ll query_maxh(int u, int st, int re){
	int l = tr[u].l, r = tr[u].r;
	if(l > re || r < st) return -inf;
	if(l >= st && r <= re){
		return tr[u].maxh;
	}
	push_down(u);
	return max_(query_maxh((u << 1), st, re), query_maxh(((u << 1) | 1), st, re));
}

int main(){
//	freopen("P6242_2.in", "r", stdin);	
	n = read(), m = read();
	for(int i = 1; i <= n; i++) a[i] = read();
	build(1, 1, n);
	for(int i = 1, op; i <= m; i++){
		op = read();
		int st, re;
		ll val, ans;
		st = read(), re = read();
		if(op == 1){
			val = read();
			add(1, st, re, val);
		}
		if(op == 2){
			val = read();
			dev(1, st, re, val);
		}
		if(op == 3){
			ans = query_sum(1, st, re);
			printf("%lld\n", ans);
		}
		if(op == 4){
			ans = query_maxn(1, st, re);
			printf("%lld\n", ans);
		}
		if(op == 5){
			ans = query_maxh(1, st, re);
			printf("%lld\n", ans);
		}
	}
	return 0;
}
