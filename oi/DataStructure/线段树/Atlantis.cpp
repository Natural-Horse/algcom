#include<bits/stdc++.h>
#define d double
#define inf 0x3f3f3f3f
#define le 1e-19
using namespace std;

const int Maxn = 1e6;

struct Line{
	d x, ya, yb;
	int k;
}ln[Maxn * 2 + 5];

struct Tree{
	int l, r;
	int md;
	d len,siz;
}tr[Maxn * 8 + 5];

int n, tot;
d rel[2*Maxn + 5];
d sp[2*Maxn + 5];
int num;
d ans;
int nidaye;

void init(){
	memset(tr, 0, sizeof(tr));
	tot = 0;
	ans = 0;
	nidaye++;
	num = 0;
}

bool cmp(Line a, Line b){
	return a.x < b.x;
}

void build(int u, int l, int r){
	if(l == r){
		tr[u].l = l;
		tr[u].r = r;
		tr[u].siz = sp[l];
		return;
	}
	int mid = (l + r) >> 1;
	int numa = (u << 1), numb = (numa | 1);
	tr[numa].l = l, tr[numa].r = mid;
	tr[numb].l = mid + 1, tr[numb].r = r;
	build(numa, l, mid);
	build(numb, mid + 1, r);
	tr[u].siz = tr[numa].siz + tr[numb].siz;
}

int bi_ser(d x){
	int l = 1, r = num;
	while(l < r){
		int mid = (l + r) >> 1;
		if(x > rel[mid]) l = mid + 1;
		else r = mid;
	}
	return l;
}

void push_back(int u){
	int numa = (u << 1), numb = (numa | 1);
	if(tr[u].md > 0) tr[u].len = tr[u].siz;
	else tr[u].len = tr[numa].len + tr[numb].len;
}

void dev(int u, int st, int re, int val){
	int l = tr[u].l, r = tr[u].r;
	if(l > re || r < st) return;
	if(l >= st && r <= re){
		tr[u].md += val;
		push_back(u);
	}
	else{
		if(l <= re) dev((u << 1), st, re, val);
		if(r >= st) dev(((u << 1) | 1), st, re, val);
		push_back(u);
	}
}

int main(){
	scanf("%d", &n);
	do{
		init();
		for(int i = 1; i <= n; i++){
			d xa, ya, xb, yb;
			scanf("%lf %lf %lf %lf", &xa, &ya, &xb, &yb);
			ln[++tot].x = xa, ln[tot].ya = ya, ln[tot].yb = yb;
			ln[tot].k = 1;
			rel[tot] = ya;
			ln[++tot].x = xb, ln[tot].ya = ya, ln[tot].yb = yb;
			ln[tot].k = -1;
			rel[tot] = yb;
		}
		sort(ln + 1, ln + 1 + tot, cmp);
		sort(rel + 1, rel + 1 + tot);
		num = unique(rel + 1, rel + 1 + tot) - rel - 1;
		for(int i = 1; i < num; i++){
			sp[i] = rel[i+1] - rel[i];
		}
		tr[1].l = 1, tr[1].r = num-1;
		build(1, 1, num-1);
		for(int i = 1; i < tot; i++){
			d ya = ln[i].ya, yb = ln[i].yb;
			int k = ln[i].k;
			int plca = lower_bound(rel + 1, rel + 1 + num, ya) - rel;
			int plcb = lower_bound(rel + 1, rel + 1 + num, yb) - rel;
			dev(1, plca, plcb-1, k);
			ans += tr[1].len * (ln[i+1].x - ln[i].x);
		}
		printf("Test case #%d\n", nidaye);
		printf("Total explored area: %.2lf\n", ans);
		printf("\n");
		scanf("%d", &n);
	}while(n != 0);
	return 0;
} 
