#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
#define d double
using namespace std;

const int Maxn = 1e6;

struct Tree{
	int l, r;
	int show;
	int lz;
}tr[Maxn * 4 +5];

int n, m;
d rel[Maxn + 5];
d que[Maxn + 5];
int num, tot;
bool check[Maxn +5];
int ans;

int bi_ser(d x){
	int l = 1, r = num;
	while(l < r){
		int mid = (l + r) >> 1;
		if(x > rel[mid]) l = mid + 1;
		else r = mid;
	}
	return l;
}

void build(int u, int l, int r){
	if(l == r){
		tr[u].l = l, tr[u].r = r;
		return;
	}
	int na = (u << 1), nb = (na | 1);
	int mid = (l + r) >> 1;
	tr[na].l = l, tr[na].r = mid;
	tr[nb].l = mid + 1, tr[nb].r = r;
	build(na, l, mid);
	build(nb, mid + 1, r);
}

void push_down(int u){
	int na = (u << 1), nb = (na | 1);
	if(tr[u].lz != 0){
		tr[na].show = tr[nb].show = tr[u].lz;
		tr[na].lz = tr[nb].lz = tr[u].lz;
		tr[u].lz = 0;
	}
}

void dev(int u, int st, int re, int val){
	int l = tr[u].l, r = tr[u].r;
	if(l > re || r < st) return;
	if(l >= st && r <= re){
		tr[u].show = val;
		tr[u].lz = val;
	}
	else{
		push_down(u);
		if(l <= re) dev((u << 1), st, re, val);
		if(r >= st) dev(((u << 1) | 1), st, re, val); 
	}
}

void dfs(int u){
	int l = tr[u].l, r = tr[u].r; 
	if(l == r){
		if(!check[tr[u].show] && tr[u].show != 0){
			ans++;
			check[tr[u].show] = true;
		}
		return;
	}
	push_down(u);
	dfs(u << 1), dfs(u << 1 | 1);
}

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= m; i++){
		int x, y;
		scanf("%d %d", &x, &y);
		d inc = (d)y/(d)x;
		rel[++tot] = inc;
		que[++tot] = inc;
	}
	sort(rel + 1, rel + 1 + n);
	num = unique(rel + 1, rel + 1 + n) - rel - 1;
	tr[1].l = 1, tr[1].r = num;
	build(1, 1, num);
	for(int i = 1; i <= tot; i++){
		d re = que[i];
		int plc = bi_ser(re);
		dev(1, 1, plc, i);
	}
	dfs(1);
	printf("%d", ans);
	return 0;
}
