#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

const int MAXN = 1e5;

struct Tree{
	int l, r;
	int show;
}tree[4 * MAXN + 5];

struct Post{
	int l, r;
}p[MAXN + 5];

int n, m;
bool b[10000005], check[MAXN + 5];
int ans;
int tmp[2 * MAXN + 5], cnt; 

void build(int flag, int l, int r){
	if(l == r){
		tree[flag].l = l;
		tree[flag].r = r;
		return;
	}
	int mid = ((l + r) >> 1);
	int numa = (flag << 1), numb = (numa | 1);
	tree[numa].l = l, tree[numa].r = mid;
	tree[numb].l = mid + 1, tree[numb].r = r;
	build(numa, l, mid);
	build(numb, mid + 1, r);
}

void edit(int u, int st, int re, int col){
	int l = tree[u].l, r = tree[u].r;
	if(l > re || r < st) return;
	if(l >= st && r <= re){
		tree[u].show = col;
		if(l == r) return;
	}	
	if(l <= re) edit((u << 1), st, re, col);
	if(r >= st) edit(((u << 1) | 1), st, re, col);
	
}

void ask(int u){
	int l = tree[u].l, r = tree[u].r;
	if( l == r){
		if(!check[tree[u].show] && tree[u].show){
			check[tree[u].show] = true;
			ans++;
		}
		return;		
	}
	ask(u << 1);
	ask((u << 1) | 1);
}

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= m; i++){
		scanf("%d %d", &p[i].l, &p[i].r);
		tmp[++cnt] = p[i].l;
		tmp[++cnt] = p[i].r;
		tmp[++cnt] = p[i].r + 1;
	}	
	sort(tmp + 1, tmp + cnt + 1);
	while(tmp[cnt - 1] == tmp[cnt]){
		cnt--;
	}
	cnt--;
	int num = unique(tmp + 1, tmp + 1 + cnt) - tmp - 1;
	tree[1].l = 1;
	tree[1].r = num;
	build(1, 1, num);	
	for(int i = 1; i <= m; i++){
		int st = lower_bound(tmp + 1, tmp + 1 + num, p[i].l) - tmp;
		int re = lower_bound(tmp + 1, tmp + 1 + num, p[i].r) - tmp;
		edit(1, st, re, i);
	}
	ask(1);
	printf("%d", ans);
	return 0;
}
