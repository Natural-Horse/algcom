#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

const int Maxn = 1e6;

struct Tree{
	ll l, r, siz;
	ll sum;
	ll maxn;	
}tr[4 * Maxn + 5];

int n, m;
ll a[Maxn + 5];
ll ans;

void build(int u, int l, int r){
	tr[u].siz = r - l + 1;
	if(l == r){
		tr[u].l = l;
		tr[u].r = r;
		tr[u].sum = a[l];
		tr[u].maxn = a[l];
		return;
	}
	int mid = (l + r) >> 1;
	int na = (u << 1), nb = (na | 1);
	tr[na].l = l, tr[na].r = mid;
	tr[nb].l = mid + 1, tr[nb].r = r;
	build(na, l, mid);
	build(nb, mid + 1, r);
	tr[u].sum = tr[na].sum + tr[nb].sum;
	tr[u].maxn = max(tr[na].maxn, tr[nb].maxn);
}

void push_back(int u){
	int na = (u << 1), nb = (na | 1);
	tr[u].sum = tr[na].sum + tr[nb].sum;
	tr[u].maxn = max(tr[na].maxn, tr[nb].maxn);
}

void sq(int u, int st, int re){
	int l = tr[u].l, r = tr[u].r;
	if(l > re || r < st) return;
	if(tr[u].maxn <= 1) return;
	if(l >= st && r <= re){
		if(l == r){
			tr[u].sum = sqrt(tr[u].sum);
			tr[u].maxn = sqrt(tr[u].maxn);
			return;
		}
		sq((u << 1), st, re);
		sq(((u << 1) | 1), st, re);
		push_back(u);
		return;
	}
	else{		
		if(l <= re) sq((u << 1), st, re);
		if(r >= st) sq(((u << 1) | 1), st, re);
		push_back(u);
	}
}

void ask(int u, int st, int re){
	int l = tr[u].l, r = tr[u].r;
	if(l > re || r < st) return;
	if(l >= st && r <= re){
		ans += tr[u].sum;
		return;
	}
	else{		
		if(l <= re) ask((u << 1), st, re);
		if(r >= st) ask(((u << 1) | 1), st, re);
		push_back(u);
	}
}

int main(){
//	freopen("P4145_6.in", "r", stdin);
//	freopen("1", "w", stdout);
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%lld", &a[i]);
	}
	tr[1].l = 1, tr[1].r = n;
	build(1, 1, n);
	scanf("%d", &m);
	for(int i = 1; i <= m; i++){
		int op, st, re;		
		scanf("%d %d %d", &op, &st, &re);
		if(st > re) swap(st, re);
		if(op == 2) sq(1, st, re);
		if(op == 1){
			ans = 0;
			ask(1, st, re);
			printf("%lld\n", ans);
		} 
	}
	return 0;
}
