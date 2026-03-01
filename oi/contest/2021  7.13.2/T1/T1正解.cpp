#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

int read(){
	int x = 0,f = 1;char ch = getchar();
	while (ch < '0' || ch > '9'){if (ch == '-') f = -1; ch = getchar();}
	while (ch >= '0' && ch <= '9'){x = x*10 + ch - 48; ch = getchar();}
	return x * f;
}
const int N = 1e5 + 5;

struct Tree{
	int l, r, siz;
	ll add, maxn;
}tr[N<<3];

int n, a[N], b[N], fab[N<<1], tot, num;

int bi_ser(ll x){
	int l = 1, r = tot;
	while(l < r){
		int mid = (l + r + 1) >> 1;
		if(x < fab[mid]) r = mid - 1;
		else l = mid;
	}
	return l;
}

void build(int u, int l, int r){
	tr[u].l = l, tr[u].r = r, tr[u].siz = r - l + 1;
	if(l != r){
		int na = u << 1, nb = na | 1, mid = (l + r) >> 1;
		build(na, l, mid), build(nb, mid + 1, r);
		tr[u].maxn = max(tr[na].maxn, tr[nb].maxn);
	}
	else tr[u].maxn = 0;
}
void push_back(int u){
	int na = u << 1, nb = na | 1;
	tr[u].maxn = max(tr[u].maxn, max(tr[na].maxn, tr[nb].maxn));
}
void push_down(int u){
	int na = u << 1, nb = na | 1;
	tr[na].maxn += tr[u].add, tr[nb].maxn += tr[u].add;
	tr[na].add += tr[u].add, tr[nb].add += tr[u].add;
	tr[u].add = 0;
}
void op_add(int u, int st, int re, ll val){
	int l = tr[u].l, r = tr[u].r;
	if(l > re || r < st) return;
	if(l >= st && r <= re){
		tr[u].maxn += val;
		tr[u].add += val;
		return;
	}
	if(l != r){
		push_down(u);
		op_add(u<<1, st, re, val), op_add(u<<1|1, st, re, val);
		push_back(u);
	}
}
void op_modify(int u, int plc, ll val){
	if(tr[u].l == tr[u].r && tr[u].l == plc){
		tr[u].maxn = max(tr[u].maxn, val);
		return;
	}
	else{
		if(tr[u].l > plc || tr[u].r < plc) return;
		if(tr[u].l <= plc && tr[u].r >= plc){
			push_down(u);
			op_modify(u<<1, plc, val), op_modify(u<<1|1, plc, val);
			push_back(u);
		}
	}
}
int query_maxn(int u, int st, int re){
	int l = tr[u].l, r = tr[u].r;
	if(l > re || r < st) return 0;
	if(l >= st && r <= re){
		return tr[u].maxn;
	}
	else if(l != r){
		push_down(u);
		return max(query_maxn(u<<1, st, re), query_maxn(u<<1|1, st, re));
	}
}

int main(){
	n = read();
	for(int i = 1; i <= n; i++) 
		a[i] = read(), b[i] =read(), fab[++num] = a[i], fab[++num] = b[i];
	sort(fab + 1, fab + 1 + num);
	tot = unique(fab + 1, fab + 1 + num) - fab - 1;
	for(int i = 1; i <= n; i++)
		a[i] = bi_ser(a[i]), b[i] = bi_ser(b[i]);
		build(1, 1, tot);
	for(int i = 1; i <= n; i++){
		if(a[i] > b[i]){
			ll tmp = query_maxn(1, a[i], tot);
			op_add(1, b[i]+1, a[i], 1);
			op_modify(1, a[i], tmp + 1);
		}
		else{
			ll tmp = query_maxn(1, b[i]+1, tot);
			op_modify(1, a[i], tmp + 1);
		}
	}
	printf("%lld", tr[1].maxn);
	return 0;
}

