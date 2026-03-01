#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

const int Maxn = 2e5;

struct Tree{
	int l, r, siz;
	ll sum, add;
}tr[4 * Maxn + 5];

int n, m;
int a[Maxn + 5];
ll ans; 

void build(int u, int l, int r){
	tr[u].l = l, tr[u].r = r, tr[u].siz = r - l + 1;
	if(l == r){
		tr[u].sum = a[l];
	}
	else{		
		int na = (u << 1), nb = (na | 1);
		int mid = (l + r) >> 1;
		build(na, l, mid);
		build(nb, mid + 1, r);
		tr[u].sum = tr[na].sum + tr[nb].sum;
	}
}

void push_down(int u){
	int na = (u << 1), nb = (na | 1);
	tr[na].sum += tr[u].add * tr[na].siz;
	tr[nb].sum += tr[u].add * tr[nb].siz;
	tr[na].add += tr[u].add;
	tr[nb].add += tr[u].add;
	tr[u].add = 0;
}

void push_back(int u){
	int na = (u << 1), nb = (na | 1);
	tr[u].sum = tr[na].sum + tr[nb].sum;
}

void add(int u, int st, int re, int val){
	int l = tr[u].l, r = tr[u].r;
	if(l > re || r < st) return;
	if(l >= st && r <= re){
		tr[u].sum += val * (ll)tr[u].siz;
		tr[u].add += val;
	}
	else{
		push_down(u);
		if(l <= re) add((u << 1), st, re, val);
		if(r >= st) add(((u << 1) | 1), st, re, val);
		push_back(u);
	}
}

void ask(int u, int st, int re){
	int l = tr[u].l, r = tr[u].r;
	if(l > re || r < st) return;
	if(l >= st && r <= re){
		ans += tr[u].sum;
	}
	else{
		push_down(u);
		if(l <= re) ask((u << 1), st, re);
		if(r >= st) ask(((u << 1) | 1), st, re);
		push_back(u);
	}
}

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}
	build(1, 1, n);
	for(int i = 1; i <= m; i++){
		int op, st, re, val;
		scanf("%d", &op);
		if(op == 1){
			scanf("%d %d %d", &st, &re, &val);
			add(1, st, re, val);
		}
		if(op == 2){
			scanf("%d", &val);
			add(1, 1, 1, val);
		}
		if(op == 3){
			scanf("%d", &val);
			add(1, 1, 1, -val); 
		}
		if(op == 4){
			ans = 0;
			scanf("%d %d", &st, &re);
			ask(1, st, re);
			printf("%lld\n", ans);
		}
		if(op == 5){
			ans = 0;
			ask(1, 1, 1);
			printf("%lld\n", ans);
		}
	}
	return 0;
}
