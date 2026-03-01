#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

const int MAXN = 1e6;

struct Tree{
	int l , r, siz;
	ll sum;
}tree[MAXN * 4 + 1];

int n,m;
int a[MAXN + 5];
char op[5];
ll ans;

void build(int flag, int l, int r){
	if(l == r){
		tree[flag].l = l;
		tree[flag].r = r;
		tree[flag].sum = a[l];
		return;
	}
	int mid = ((l + r) >> 1);
	int numa = (flag<<1), numb = ((flag<<1) | 1);
	tree[numa].l = l;
	tree[numa].r = mid;
	tree[numb].l = mid + 1;
	tree[numb].r = r;
	build(numa, l, mid);
	build(numb, mid + 1, r);
	tree[flag].sum += tree[numa].sum + tree[numb].sum;
}

void edit(int u, int pos, ll val){
	int l = tree[u].l;
	int r = tree[u].r;
	if(r < pos || l > pos) return;
	else{
		tree[u].sum += val;
		edit((u<<1), pos, val);
		edit(((u<<1)|1), pos, val);
	}
}

void ask(int u, int st, int re){
	int l = tree[u].l, r = tree[u].r;
	if(l > re || r < st) return;
	if(r <= re && l >= st){
		ans += tree[u].sum;
	}
	else{
		if(l <= re) ask(((u<<1)|1), st, re);
		if(r >= st) ask((u<<1),st,re);
	}
}

int main(){
	scanf("%d", &n);
	if(n == 0) return 0;
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}
	scanf("%d", &m);
	tree[1].l = 1;
	tree[1].r = n;
	build(1, 1, n);
	for(int i = 1; i <= m; i++){
		scanf("%s",op);
		if(op[0] == 'A'){
			int pos;
			ll val;
			scanf("%d %lld",&pos, &val);
			edit(1, pos, val);
		} 
		else{
			int st, re;
			scanf("%d %d",&st, &re);
			ans = 0;
			ask(1, st, re);
			printf("%lld\n",ans);
		}
		for(int i = 0; i <= 2; i++){
			op[i] = 0;
		} 
//		scanf("\n");
	}
	return 0;
} 
