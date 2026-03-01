#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

const int MAXN = 1e6;

struct Tree{
	ll sum;
	int siz,l,r;
	ll lzadd;
}tree[MAXN*4+5];

int n,a[MAXN+5];
int m;
char op[8];
ll ans;

void build(int flag, int l, int r){
	if(l == r){
		tree[flag].l = l;
		tree[flag].r = r;
		tree[flag].sum = a[l];
		tree[flag].siz = 1;
		return;
	}
	int mid = ((l+r) >> 1);
	int numa = (flag << 1);
	int numb = (flag<<1) | 1;
	tree[numa].l = l, tree[numa].r = mid, tree[numa].siz = mid - l + 1;
	tree[numb].l = mid + 1, tree[numb].r = r, tree[numb].siz = r - mid;
	build(numa, l, mid);
	build(numb, mid+1, r);
	tree[flag].sum = tree[numa].sum + tree[numb].sum;
	tree[flag].siz = l - r + 1;
}

void add(int u, int st, int re, ll val){
	int l = tree[u].l, r = tree[u].r;
	if(l > re || r < st) return;
	if(l >= st && r <= re){
		tree[u].sum += val * (ll)tree[u].siz;
		tree[u].lzadd += val;
	}
	else{
		tree[u].sum += (min(r,re) - max(l,st) + 1) * val;
		if(l <= re)	add((u << 1), st, re, val);
		if(r >= st) add(((u << 1) | 1), st, re, val);
	}
}

void push_down(int u){
	int numa = (u << 1);
	int numb = (numa | 1);
	tree[numa].sum += tree[u].lzadd * (ll)tree[numa].siz;
	tree[numb].sum += tree[u].lzadd * (ll)tree[numb].siz;
	tree[numa].lzadd += tree[u].lzadd;
	tree[numb].lzadd += tree[u].lzadd;
	tree[u].lzadd = 0;
}

void ask(int u, int st, int re){
	int l = tree[u].l, r = tree[u].r;
	if(l > re || r < st) return;
	push_down(u);
	if(l >= st && r <= re){
		ans += tree[u].sum;		
	}
	else{
		if(l <= re) ask((u << 1), st, re);
		if(r >= st) ask(((u << 1) | 1), st, re);
	}
}

int main(){
	scanf("%d",&n);
	for(int i = 1; i <= n; i++){
		scanf("%d",&a[i]);
	}
	scanf("%d",&m);
	tree[1].l = 1;
	tree[1].r = n;
	tree[1].siz = n;
	build(1, 1, n);
	for(int i = 1;i <= m; i++){
		scanf("%s",op);
		if(op[1] == 'D'){
			int re, st;
			ll val;
			scanf("%d %d %lld", &st, &re, &val);
			add(1, st, re, val);
		}
		else{
			ans = 0;
			int pos;
			scanf("%d", &pos);
			ask(1, pos, pos);
			printf("%lld\n", ans);
		}
		for(int i = 0; i <= 4; i++){
			op[i] = 0;
		}
	}
	return 0;
} 
