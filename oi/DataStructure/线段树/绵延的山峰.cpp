#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

const int MAXN = 1e6;

struct Tree{
	int l,r;
	int maxh;
}tree[4*MAXN+5];

int n,q;
int h[MAXN+5];
int ans; 

void build(int flag, int l, int r){
	if(l == r){
		tree[flag].l = l;
		tree[flag].r = r;
		tree[flag].maxh = h[l];
		return;
	}
	int mid = (l + r) >> 1;
	int numa = (flag << 1);
	int numb = (numa | 1);
	tree[numa].l = l;
	tree[numa].r = mid;
	tree[numb].l = mid + 1;
	tree[numb].r = r;
	build(numa, l, mid);
	build(numb, mid + 1, r);
	tree[flag].maxh = max(tree[numa].maxh, tree[numb].maxh);
}

void ask(int u, int st, int re){
	int l = tree[u].l;
	int r = tree[u].r;
	if(l > re || r < st) return;
	if(l >= st && r <= re){
		ans = max(ans, tree[u].maxh);
		return;
	}
	else{
		if(l <= re) ask((u << 1), st, re);
		if(r >= st) ask(((u << 1) | 1), st, re);
	}
}

int main(){
	scanf("%d",&n);
	for(int i = 0; i <= n; i++){
		scanf("%d",&h[i]);
	}
	tree[1].l = 0;
	tree[1].r = n;
	build(1, 0, n);
	scanf("%d",&q);
	for(int i = 1; i <= q; i++){
		int st, re;
		ans = 0;
		scanf("%d %d", &st, &re);
		ask(1, st, re);
		printf("%d\n",ans);
	}
	return 0;
}
