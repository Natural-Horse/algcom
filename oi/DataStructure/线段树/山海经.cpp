#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

const int MAXN = 1e6;

struct Tree{
	int l,r,sum;
	int lsum,rsum,insum;
	int lsuml,lsumr,rsuml,rsumr,insuml,insumr;
}tree[4*MAXN+5];

int n,m;
int a[MAXN+5];

void build(int flag, int l, int r){
	if(l == r){
		tree[flag].l = l;
		tree[flag].r = r;
		tree[flag].sum = a[l];
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
	build(numb, mid+1, r);
	tree[flag].sum = tree[numa].sum + tree[numb].sum;
}

void dfs(int u){
	int l = tree[u].l, r = tree[u].r;
	if(l == r){
		tree[u].insum = tree[u].lsum = tree[u].rsum = tree[u].sum;
		tree[u].lsuml=tree[u].lsumr=tree[u].rsuml=tree[u].rsumr=tree[u].insuml=tree[u].insumr=l;
		return;
	}
	int numa = (u << 1);
	int numb = (numa | 1);
	dfs(numa);
	dfs(numb);
	tree[u].lsuml = l;
	tree[u].rsumr = r;
	if(tree[numa].sum + tree[numb].lsum > tree[numa].lsum){
		tree[u].lsum = tree[numa].sum + tree[numb].lsum;
		tree[u].lsumr = tree[numb].lsumr;
	}
	else{
		tree[u].lsum = tree[numa].lsum;
		tree[u].lsumr = tree[numa].lsumr;		
	}
	if(tree[numb].rsum > tree[numa].rsum + tree[numb].sum){
		tree[u].rsum = tree[numb].rsum;
		tree[u].rsuml = tree[numb].rsuml;
	}
	else{
		tree[u].rsum = tree[numa].rsum + tree[numb].sum;
		tree[u].rsuml = tree[numa].rsuml;
	}
	tree[u].insum = tree[numa].rsum + tree[numb].lsum;
	tree[u].insuml = tree[numa].rsuml;
	tree[u].insumr = tree[numb].lsumr;
	if(tree[numa].insum >= tree[u].insum){
		tree[u].insum = tree[numa].insum;
		tree[u].insuml = tree[numa].insuml;
		tree[u].insumr = tree[numa].insumr;
	}
	if(tree[numb].insum > tree[u].insum){
		tree[u].insum = tree[numb].insum;
		tree[u].insuml = tree[numb].insuml;
		tree[u].insumr = tree[numb].insumr;
	}
}

ll ansl[5], ansr[5], anssum[5];
int last;

void ask(int u, int st, int re){
	int l = tree[u].l, r = tree[u].r;
	if(l > re || r < st) return;
	if(l >= st && r <= re){
		if(anssum[2] + tree[u].lsum > anssum[1]){
			anssum[1] = anssum[2] + tree[u].lsum;
			ansl[1] = ansl[2];
			ansr[1] = tree[u].lsumr;
		}
		if(tree[u].insum > anssum[1]){
			anssum[1] = tree[u].insum;
			ansl[1] = tree[u].insuml;
			ansr[1] = tree[u].insumr;
		}
		if(tree[u].rsum > anssum[2] + tree[u].sum){
			anssum[2] = tree[u].rsum;
			ansl[2] = tree[u].rsuml;
		}
		else anssum[2] += tree[u].sum;
	}
	else{
		if(l <= re) ask((u << 1), st, re);
		if(r >= st) ask(((u << 1) | 1), st, re);
	}
}

int main(){
	scanf("%d %d",&n,&m);
	for(int i = 1; i <= n; i++){
		scanf("%d",&a[i]);
	}
	tree[1].l = 1;
	tree[1].r = n;
	build(1, 1, n);
	dfs(1);
	for(int i = 1; i <= m; i++){
		anssum[1] = anssum[2] = -inf;
		ansl[1] = ansl[2] = ansr[1] = ansr[2] = 0;
		last = 0;
		int st, re;
		scanf("%d %d",&st, &re);
		ask(1, st, re);
		printf("%lld %lld %lld\n", ansl[1], ansr[1], anssum[1]);
	}
	return 0;
}
