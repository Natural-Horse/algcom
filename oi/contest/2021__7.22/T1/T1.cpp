#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
#define int long long
using namespace std;

ll read(){
	ll x = 0,f = 1;char ch = getchar();
	while (ch < '0' || ch > '9'){if (ch == '-') f = -1; ch = getchar();}
	while (ch >= '0' && ch <= '9'){x = x*10 + ch - 48; ch = getchar();}
	return x * f;
}

const int N = 1e5 + 5;

struct Tree{
	int l, r, siz, c1;
	bool to1, to0, rev;
}tr[N << 5];
int m, op[N<<1], num, tot;
ll a[N<<1], b[N<<1], ls[N<<4], maxn;

void build(int u, int l, int r){
	tr[u].l = l, tr[u].r = r, tr[u].siz = r - l + 1;
	if(l != r){
		int na = u << 1, nb = na | 1, mid = (l + r) >> 1;
		build(na, l, mid), build(nb, mid + 1, r);
	}
	return;
}
void push_down(int u){
	int na = u << 1, nb = na | 1;
	if(tr[u].to0 == true){
		tr[na].c1 = tr[nb].c1 = 0;
		tr[na].to1 = tr[nb].to1 = false;
		tr[na].to0 = tr[nb].to0 = true;
		tr[u].to0 = false;
		tr[na].rev = tr[nb].rev = false;
	}
	if(tr[u].to1 == true){
		tr[na].c1 = tr[na].siz, tr[nb].c1 = tr[nb].siz;
		tr[na].to1 = tr[nb].to1 = true;
		tr[na].to0 = tr[nb].to0 = false;
		tr[u].to1 = false;
		tr[na].rev = tr[nb].rev = false;
	}
	if(tr[u].rev == true){
		tr[na].c1 = tr[na].siz - tr[na].c1;
		tr[nb].c1 = tr[nb].siz - tr[nb].c1;
		if(tr[na].to0) tr[na].to0 = false, tr[na].to1 = true;
		else if(tr[na].to1) tr[na].to1 = false, tr[na].to0 = true;
		if(tr[nb].to0) tr[nb].to0 = false, tr[nb].to1 = true;	
		else if(tr[nb].to1) tr[nb].to1 = false, tr[nb].to0 = true;
		if(!tr[na].to0 && !tr[na].to1) tr[na].rev ^= 1;
		if(!tr[nb].to0 && !tr[nb].to1) tr[nb].rev ^= 1;
		tr[u].rev = false;
	}
}
void push_back(int u){
	int na = u << 1, nb = na | 1;
	tr[u].c1 = tr[na].c1 + tr[nb].c1;
}
void op_dev(int u, int st, int re, int val){
	int l = tr[u].l, r = tr[u].r;
	if(l > re || r < st) return;
	if(l >= st && r <= re){
		if(val){
			tr[u].to0 = tr[u].rev = false;
			tr[u].to1 = true;
			tr[u].c1 = tr[u].siz;
		}
		else{
			tr[u].to1 = tr[u].rev = false;
			tr[u].to0 = true;
			tr[u].c1 = 0;
		}
		return;
	}
	if(l != r){
		push_down(u);
		op_dev(u<<1, st, re, val), op_dev(u<<1|1, st, re, val);
		push_back(u);
	}
	return;
}
void op_rev(int u, int st, int re){
	int l = tr[u].l, r = tr[u].r;
	if(l > re || r < st) return;
	if(l >= st && r <= re){
		tr[u].c1 = tr[u].siz - tr[u].c1;
		if(tr[u].to0) tr[u].to0 = false, tr[u].to1 = true;
		else if(tr[u].to1) tr[u].to1 = false, tr[u].to0 = true;
		if(!tr[u].to1 && !tr[u].to0) tr[u].rev ^= 1;
		return;
	}
	if(l != r){
		push_down(u);
		op_rev(u<<1, st, re), op_rev(u<<1|1, st, re);
		push_back(u);
	}
	return;
}
int query_fir0(int u, int st, int re){
	int l = tr[u].l, r = tr[u].r;
	int na = u << 1, nb = na | 1;
	if(l >= st && r <= re){
		if(!tr[u].c1) return l;
		if(l != r){
			push_down(u);
			push_back(u);
			if(!tr[u].c1) return l;
			else if(tr[na].c1 < tr[na].siz) return query_fir0(na, st, re);
			else if(tr[nb].c1 < tr[nb].siz) return query_fir0(nb, st, re);
		}
	}
	if(l != r){
		push_down(u);
		return min(query_fir0(na, st, re), query_fir0(nb, st, re));
	}
}

signed main(){
//	freopen("sample.in", "r", stdin);
//	freopen("print.out", "w", stdout);
	m = read();
	ls[++tot] = 1;
	for(int i = 1; i <= m; i++){
		op[i] = read(), a[i] = read(), b[i] = read();
		if(op[i] == 2) op[i] = 0;
		ls[++tot] = a[i], ls[++tot] = b[i];
		if(a[i]!=1) ls[++tot] = a[i]-1; ls[++tot] = a[i]+1;
		if(b[i]!=1) ls[++tot] = b[i]-1; ls[++tot] = b[i]+1;
	}
	sort(ls + 1, ls + 1 + tot);
	num = unique(ls + 1, ls + 1 + tot) - ls - 1;
	build(1, 1, num);
	for(int i = 1; i <= m; i++){
		int opl = lower_bound(ls + 1, ls + 1 + num, a[i]) - ls;
		int opr = lower_bound(ls + 1, ls + 1 + num, b[i]) - ls;
		if(op[i] == 1 || op[i] == 0) op_dev(1, opl, opr, op[i]);
		else op_rev(1, opl, opr);
		ll res = ls[query_fir0(1, 1, num)];
		printf("%lld\n", res);
	}
	return 0;
}
