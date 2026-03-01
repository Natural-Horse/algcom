#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

const int maxn = 1e6;

struct Tree{
	int l,r;
	ll sum;
	ll lzadd;
	int siz;
}tree[4 * maxn +5];

int n,m;
int a[maxn + 5];
ll ans;

void build(int l, int r, int flag){
	int mid = (l + r) / 2;
	if(l == r){
		tree[flag].l = l, tree[flag].r = r;
		tree[flag].sum = a[l];
		return;
	}
	int numa = flag * 2, numb = numa + 1;	
	tree[numa].l = l, tree[numa].r = mid, tree[numa].siz = mid - l +1;
	tree[numb].l = mid + 1, tree[numb].r = r, tree[numb].siz = r - mid;
	build(l, mid, numa);
	build(mid + 1, r, numb);
	tree[flag].sum += tree[numa].sum + tree[numb].sum;
}

void add(int u, int st, int re, ll val){
	int l = tree[u].l;
	int r = tree[u].r;
	if(l > re || r < st) return;
	if(l >= st && r <= re){
		tree[u].lzadd += val;
		tree[u].sum += val * (ll)tree[u].siz;
	}
	else {
		tree[u].sum += (ll)(min(re,r) - max(st,l) + 1) * val;
		if(r >= st){
			add(u * 2 + 1, st, re, val);
		} 
		if(l <= re){
			add(u * 2, st, re, val);
		}
	}
}

void push_down(int u){
	tree[u * 2].lzadd += tree[u].lzadd;
	tree[u * 2].sum += tree[u].lzadd * (ll)tree[u * 2].siz;
	tree[u * 2 + 1].lzadd += tree[u].lzadd;
	tree[u * 2 + 1].sum += tree[u].lzadd * (ll)tree[u * 2 + 1].siz;
	tree[u].lzadd = 0;
}

void ask(int u, int st, int re){
	int l = tree[u].l, r = tree[u].r;
	if(l > re || r < st) return;
	push_down(u);
	if(l >= st && r <= re){		
		ans += tree[u].sum;
		tree[u].lzadd = 0;
	}
	else{
		if(r >= st) ask(u * 2 + 1, st, re);
		if(l <= re) ask(u * 2, st, re);
	}
}

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++){
		scanf("%d",&a[i]);
	}
	tree[1].l = 1;
	tree[1].r = n;
	tree[1].siz = n;
	build(1, n, 1);
	for(int i = 1, op; i <= m; i++){
		scanf("%d",&op);
		if(op == 1){
			int u, v;
			ll w;
			scanf("%d %d %lld", &u, &v, &w);
			add(1, u, v, w);
		}
		if(op == 2){
			int u, v;
			scanf("%d %d", &u, &v);
			ans = 0;
			ask(1, u, v);
			printf("%lld\n",ans);
		}
	}
	return 0;
}
