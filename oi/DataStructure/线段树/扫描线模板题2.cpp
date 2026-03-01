#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
#define le 1e-19
using namespace std;

const int Maxn = 1000005;

struct Line{
	int x, ya, yb, k;	
}line[2 * Maxn];

struct Tree{
	int l, r;
	ll add; 
	ll siz, len;
	ll md;
}tree[8 * Maxn];

int n;
ll rel[2 * Maxn], tot;
ll sp[2 * Maxn]; 
int num;
ll ans;

bool cmp(Line a, Line b){
	return a.x <= b.x;
}

int unq(){
	int a = tot;
	int jud = 1;
	for(int i = 2; i <= tot; i++){
		while(rel[i]+le>rel[i-1] && rel[i]-le<rel[i-1]){
			a--;
			i++;
		}
		rel[++jud] = rel[i];
	}	
	return a;
} 

int bi_ser(int x){
	int l = 1, r = num;
	while(l < r){
		int mid = (l + r) >> 1;
		if(x > rel[mid]) l = mid + 1;
		else r = mid;
	}
	return l;
}

void build(int flag, int l, int r){
	if(l == r){
		tree[flag].l = l;
		tree[flag].r = r;
		tree[flag].siz = sp[l];
		return;
	}
	int numa = (flag << 1), numb = (numa | 1);
	int mid = (l + r) >> 1;
	tree[numa].l = l, tree[numa].r = mid;
	tree[numb].l = mid + 1, tree[numb].r = r;
	build(numa, l, mid);
	build(numb, mid + 1, r);
	tree[flag].siz = tree[numa].siz + tree[numb].siz;
}

void push_back(int u){
	int numa = (u << 1), numb = (numa | 1);
	tree[u].len = tree[numa].len + tree[numb].len;
}

void dev(int u, int st, int re, int val){
	int l = tree[u].l, r = tree[u].r;
	if(l > re || r < st) return;	
	if(l >= st && r <= re){		
		tree[u].md += val;
		if(tree[u].md > 0) tree[u].len = tree[u].siz;
		else push_back(u);
	}
	else{
		if(l <= re) dev((u << 1), st, re, val);
		if(r >= st) dev(((u << 1) | 1), st, re, val);
		if(tree[u].md > 0) tree[u].len = tree[u].siz;
		else push_back(u);
	}
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		int xa, ya, xb, yb;
		scanf("%d %d %d %d", &xa, &ya, &xb, &yb);
		line[++tot].x = xa;
		line[tot].ya = ya, line[tot].yb = yb;
		line[tot].k = 1;
		rel[tot] = ya;
		line[++tot].x = xb;
		line[tot].ya = ya, line[tot].yb = yb;
		line[tot].k = -1;
		rel[tot] = yb;
	}
	sort(line + 1, line + 1 + tot, cmp);
	sort(rel + 1, rel + 1 + tot);
	num = unq();
	for(int i = 1; i <= num-1; i++){
		sp[i] = rel[i+1] - rel[i];
	}
	tree[1].l = 1, tree[1].r = num-1;
	build(1, 1, num-1);
	for(int i = 1; i < tot; i++){
		int ya = line[i].ya, yb = line[i].yb, k = line[i].k;
		int plca = bi_ser(ya);
		int plcb = bi_ser(yb);
		dev(1, plca, plcb-1, k);		
		ans += tree[1].len * (ll)(line[i + 1].x - line[i].x);
	}
	printf("%lld", ans);
	return 0;
}
