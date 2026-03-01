#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

const int MAXN = 1e6;

struct Tree{
	int l, r, siz;
	ll sum;
	ll lzadd, lzmul;
}tree[4 * MAXN + 5];

int n, m;
ll p;
int a[MAXN + 5];
ll ans;

void build(int flag, int l, int r){
	tree[flag].siz = r - l + 1;
	tree[flag].lzmul = 1;
	if(l == r){
		tree[flag].l = l, tree[flag].r = r;
		tree[flag].sum = a[l];
		return;
	}
	int mid = (l + r) >> 1;
	int numa = (flag << 1), numb = (numa | 1);
	tree[numa].l = l, tree[numa].r = mid;
	tree[numb].l = mid + 1, tree[numb].r = r;
	build(numa, l, mid);
	build(numb, mid + 1, r);
	tree[flag].sum = tree[numa].sum + tree[numb].sum; 
}

void push_down(int u){
	int numa = (u << 1), numb = (numa | 1);
	tree[numa].sum *= tree[u].lzmul;
	tree[numb].sum *= tree[u].lzmul;
	tree[numa].sum += tree[u].lzadd *(ll)tree[numa].siz;
	tree[numb].sum += tree[u].lzadd *(ll)tree[numb].siz;
	tree[numa].lzadd = tree[numa].lzadd * tree[u].lzmul + tree[u].lzadd;
	tree[numb].lzadd = tree[numb].lzadd * tree[u].lzmul + tree[u].lzadd;
	tree[numa].lzmul *= tree[u].lzmul;
	tree[numb].lzmul *= tree[u].lzmul;
	tree[numa].sum %= p;
	tree[numb].sum %= p;
	tree[numa].lzadd %= p;
	tree[numb].lzadd %= p;
	tree[numa].lzmul %= p;
	tree[numb].lzmul %= p;
	tree[u].lzadd = 0;
	tree[u].lzmul = 1;
}

void mul(int u, int st, int re, ll val){
	int l = tree[u].l, r = tree[u].r;
	if(l > re || r < st) return;
	if(l >= st && r <= re){
		tree[u].sum *= val, tree[u].sum %= p;
		tree[u].lzmul *= val, tree[u].lzmul %= p;
		tree[u].lzadd *= val, tree[u].lzadd %= p;
	}
	else{
		push_down(u);
		if(l <= re) mul((u << 1), st, re, val);
		if(r >= st) mul(((u << 1) | 1), st, re, val);
		tree[u].sum = tree[u<<1].sum + tree[(u<<1)|1].sum;
	}
}

void add(int u, int st, int re, ll val){
	int l = tree[u].l, r = tree[u].r;
	if(l > re || r < st) return;
	if(l >= st && r <= re){
		tree[u].sum += val * (ll)tree[u].siz, tree[u].sum %= p;
		tree[u].lzadd += val, tree[u].lzadd %= p;
	}
	else{
		push_down(u);
		if(l <= re) add((u << 1), st, re, val);
		if(r >= st) add(((u << 1) | 1), st, re, val);
		tree[u].sum = tree[u << 1].sum + tree[(u << 1) | 1].sum;
	}
}

void ask(int u, int st, int re){
	int l = tree[u].l , r = tree[u].r;
	if(l > re || r < st) return;
	push_down(u);
	if(l >= st && r <= re){
		ans += tree[u].sum;
		ans %= p;
	}
	else{
		if(l <= re) ask((u << 1), st, re);
		if(r >= st) ask(((u << 1) | 1), st, re);
	}
}

int main(){
	scanf("%d %d %lld", &n, &m, &p);
	for(int i = 1; i <= n; i++){
		scanf("%d",&a[i]);
		a[i] %= p;
	}
	tree[1].l = 1, tree[1].r = n;
	build(1, 1, n);
	for(int i = 1; i <= m; i++){
		int op;
		scanf("%d", &op);
		if(op == 1){
			int st, re; 
			ll val;
			scanf("%d %d %lld", &st, &re, &val);
			mul(1, st, re, val);
		}
		if(op == 2){
			int st, re;
			ll val;
			scanf("%d %d %lld", &st, &re, &val);
			add(1, st, re, val);
		}
		if(op == 3){
			int st, re;
			ans = 0;
			scanf("%d %d", &st, &re);
			ask(1, st, re);
			ans %= p;
			printf("%lld\n", ans);
		}
	}
	return 0;
}
