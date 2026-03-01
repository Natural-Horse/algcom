#include<bits/stdc++.h>
#define inf 0x7ffffff 
#define ll long long
using namespace std;

const int MAXN = 1e6;

struct Tree{
	int l,r;
	int minh;
}tree[4*MAXN+5];

int m,n;
int h[MAXN+5];
int ans = inf; 

void build(int flag, int l, int r){
	if(l == r){
		tree[flag].l = l;
		tree[flag].r = r;
		tree[flag].minh = h[l];
		return;
	}
	int mid = ((l + r) >> 1);
	int numa = (flag << 1);
	int numb = (numa | 1);
	tree[numa].l = l;
	tree[numa].r = mid;
	tree[numb].l = mid + 1;
	tree[numb].r = r;
	build(numa, l, mid);
	build(numb, mid + 1, r);
	tree[flag].minh = min(tree[numa].minh, tree[numb].minh);
}

void ask(int u, int st, int re){
	int l = tree[u].l;
	int r = tree[u].r;
	if(l > re || r < st) return;
	if(l >= st && r <= re){
		ans = min(ans, tree[u].minh);
		return;
	}
	else{
		if(l <= re) ask((u << 1), st, re);
		if(r >= st) ask(((u << 1) | 1), st, re);
	}
}

int main(){
	scanf("%d %d", &m, &n);
	for(int i = 1; i <= m; i++){
		scanf("%d",&h[i]);
	}
	tree[1].l = 1;
	tree[1].r = m;
	build(1, 1, m);
	for(int i = 1; i <= n; i++){
		int st, re;
		ans = inf;
		scanf("%d %d", &st, &re);
		ask(1, st, re);
		printf("%d ",ans);
	}
	return 0;
}
