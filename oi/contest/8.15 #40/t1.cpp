#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

inline int read(){
	int x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9'){if(ch == '-') f = -1; ch = getcha();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch = 48; ch = getchar();}
	return x * f;
}

const int N = 1e6 + 5;

struct Tree{
	int l, r;
	ll mx, add;
}tr[N << 2]; 
int n, m, w[N], c[N];
int las[N], slas[N];
ll ans;

void build(int u, int l, int r){
	tr[u].l = l, tr[u].r = r;
	if(l != r)
		build(u<<1, l, (l+r)>>1), build(u<<1|1, ((l+r)>>1)+1, r);
	return;
} 

void push_down(int u){
	int na = u << 1, nb = na | 1;
	tr[na].mx += tr[u].add, tr[na].add += tr[u].add;
	tr[nb].mx += tr[u].add, tr[nb].add += tr[u].add;
	tr[u].add = 0;
}
void push_back(int u){
	tr[u].mx = max(tr[u<<1].mx, tr[u<<1|1].mx);
}
void op_add(int u, int st, int re, int val){
	int l = tr[u].l, r = tr[u].r;
	if(l > re || r < st) return;
	if(l >= st && r <= re){
		tr[u].mx += val, tr[u].add += val;
		return;
	}
	if(l != r){
		push_down(u);
		op_add(u<<1, st, re, val), op_add(u<<1|1, st, re, val);
		push_back(u);
	}
	return;
}
ll qr_mx(int u, int st, int re){
	int l = tr[u].l, r = tr[u].r;
	if(l > re || r < st) return 0;
	if(l >= st && r <= re) return tr[u].mx;
	if(l != r){
		push_down(u);
		return max(qr_mx(u<<1, st, re), qr_mx(u<<1|1, st, re));
	}
	return 0;
}

int main(){
	n = read(), m = read();
	for(int i = 1; i <= n; i++) c[i] = read();
	for(int i = 1; i <= m; i++) w[i] = read();
	for(int i = 1; i <= n; i++){
		if(las[c[i]]) op_dev(1, slas[c[i]]+1, las[c[i]], -w[c[i]]);
		op_dev(1, las[c[i]]+1, i, w[c[i]]);
		ans = max(ans, qr_mx(1, 1, i));
	}
	printf("%lld\n", ans);
	return 0;
}


