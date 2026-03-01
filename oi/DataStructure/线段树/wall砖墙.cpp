#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

const int Maxn = 2000000;

struct Tree{
	int l, r, siz;
	int lup, ldown;
	int bu, bd;
}tr[Maxn * 4 + 5];

int n, m;
int a[Maxn + 5];
int ans[Maxn + 5];

void build(int u, int l, int r){
	tr[u].siz = r - l + 1;
	tr[u].lup = -inf;
	tr[u].ldown = inf;
	if(l == r){
		tr[u].l = l, tr[u].r = r;
		return;
	}
	int mid = (l + r) >> 1;
	int na = (u << 1), nb = (na | 1);
	tr[na].l = l, tr[na].r = mid;
	tr[nb].l = mid + 1, tr[nb].r = r;
	build(na, l, mid);
	build(nb, mid + 1, r);
}

void push_down(int u){
	int na = (u << 1), nb = (na | 1);
	if(tr[u].lup > tr[na].ldown){
		tr[na].ldown = tr[na].lup = tr[u].lup;
	}
	else if(tr[u].lup > tr[na].lup){
		tr[na].lup = tr[u].lup;
	}
	if(tr[u].lup > tr[nb].ldown){
		tr[nb].ldown = tr[nb].lup = tr[u].lup;
	}
	else if(tr[u].lup > tr[nb].lup){
		tr[nb].lup = tr[u].lup;
	}
	
	if(tr[u].ldown < tr[na].lup){
		tr[na].ldown = tr[na].lup = tr[u].ldown;
	}
	else if(tr[u].ldown < tr[na].ldown) tr[na].ldown = tr[u].ldown;
	if(tr[u].ldown < tr[nb].lup){
		tr[nb].ldown = tr[nb].lup = tr[u].ldown;
	}
	else if(tr[u].ldown < tr[nb].ldown) tr[nb].ldown = tr[u].ldown;
}

void push_back(int u){
//	int na = (u << 1), nb = (na | 1);
	tr[u].lup = min(tr[u<<1].lup, tr[u<<1|1].lup);
	tr[u].ldown = max(tr[u<<1].ldown, tr[u<<1|1].ldown);
}

void up_(int u, int st, int re, int val){
	int l = tr[u].l, r = tr[u].r;
	if(l > re || r < st) return;
	if(l >= st && r <= re){
		if(val < tr[u].lup) return;
		if(val > tr[u].ldown){
			tr[u].lup = tr[u].ldown = val;
		}
		else tr[u].lup = val;
	}
	else{
		push_down(u);
		if(l <= re) up_((u << 1), st, re, val);
		if(r >= st) up_(((u << 1) | 1), st, re, val);
		push_back(u);
	}
}

void down_(int u, int st, int re, int val){
	int l = tr[u].l, r = tr[u].r;
	if(l > re || r < st) return;
	if(l >= st && r <= re){
		if(val > tr[u].ldown) return;
		if(val < tr[u].lup){
			tr[u].ldown = tr[u].lup = val;
		}
		else tr[u].ldown = val;
	}
	else{
		push_down(u);
		if(l <= re) down_((u << 1), st, re, val);
		if(r >= st) down_(((u << 1) | 1), st, re, val);
		push_back(u);
	}
}

void dfs(int u){
	int na = (u << 1), nb = (na | 1);
	int l = tr[u].l, r = tr[u].r;
	if(l == r){
		ans[l] = tr[u].lup;
		if(tr[u].lup == -inf) ans[l] = 0;
		return;
	}
	push_down(u);
	dfs(na);
	dfs(nb);
}

int main(){
	scanf("%d %d", &n, &m);
	tr[1].l = 0, tr[1].r = n - 1;
	build(1, 0, n-1);
	for(int i = 1; i <= m; i++){
		int op, st, re, val;
		scanf("%d %d %d %d", &op, &st, &re, &val);
		if(op == 1){
			up_(1, st, re, val);
		}
		if(op == 2){
			down_(1, st, re, val);
		}
	}
	dfs(1);
	for(int i = 0; i < n; i++){
		printf("%d\n", ans[i]);
	}
	return 0;
}
