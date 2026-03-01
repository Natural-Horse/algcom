#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

const int Maxn = 1e6; 

struct Tree{
	int l, r, siz;
	int sum;
	int tag;
}tree[4 * Maxn + 5];

int n, m;
int a[Maxn + 5];
int ans;

void build(int flag, int l, int r){
	tree[flag].siz = r - l + 1;
	if(l == r){
		tree[flag].l = l;
		tree[flag].r = r;
		if(a[l] == 1) tree[flag].sum = 1;
		return;
	}
	int numa = (flag << 1), numb = (numa | 1);
	int mid = (l + r) >> 1;
	tree[numa].l = l, tree[numa].r = mid;
	tree[numb].l = mid + 1, tree[numb].r = r;
	build(numa, l, mid);
	build(numb, mid + 1, r);
	tree[flag].sum = tree[numa].sum + tree[numb].sum;
}

void push_down(int u){
	int numa = (u << 1), numb = (numa | 1);
	if(!tree[u].tag) return;
	tree[numa].tag = 1 - tree[numa].tag;
	tree[numb].tag = 1 - tree[numb].tag;
	tree[numa].sum = tree[numa].siz - tree[numa].sum;
	tree[numb].sum = tree[numb].siz - tree[numb].sum;
	tree[u].tag = 0;
}

void push_back(int u){
	int numa = (u << 1), numb = (numa | 1);
	tree[u].sum = tree[numa].sum + tree[numb].sum;
}

void dev(int u, int st, int re){
	int l = tree[u].l, r = tree[u].r;
	if(l > re || r < st) return;
	if(l >= st && r <= re){
		tree[u].sum = tree[u].siz - tree[u].sum;
		tree[u].tag = 1 - tree[u].tag;
	}
	else{
		push_down(u);
		if(l <= re) dev((u << 1), st, re);
		if(r >= st) dev(((u << 1) | 1), st, re);
		push_back(u);
	}
}

void ask(int u, int st, int re){
	int l = tree[u].l, r = tree[u].r;
	push_down(u);
	if(l > re || r < st) return;
	if(l >= st && r <= re){
		ans += tree[u].sum;
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
		a[i] = 0;
	}
	tree[1].l = 1, tree[1].r = n;
	build(1, 1, n);	
	for(int i = 1, op, st, re; i <= m; i++){
		scanf("%d %d %d", &op, &st, &re);
		if(op == 0) dev(1, st, re);
		if(op == 1){
			ans = 0;
			ask(1, st, re);
			printf("%d\n", ans);
		}
	}
	return 0;
}
