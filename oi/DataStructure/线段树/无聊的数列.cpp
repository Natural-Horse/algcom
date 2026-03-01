#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

const int Maxn = 1e6;

struct Tree{
	int l, r, siz;
	ll sum;
	ll add;
}tr[4 * Maxn + 5];

int n, m;
int a[Maxn + 5];
ll ans;

void build(int u, int l, int r){
	tr[u].siz = r - l + 1;
	if(l == r){
		tr[u].l = l, tr[u].r = r;
		tr[u].sum = 0;
		return;
	}
	int mid = (l + r) >> 1;
	int numa = (u << 1), numb = (numa | 1);
	tr[numa].l = l, tr[numa].r = mid;
	tr[numb].l = mid + 1, tr[numb].r = r;
	build(numa, l, mid);
	build(numb, mid + 1, r);
	tr[u].sum = tr[numa].sum + tr[numb].sum;
}

void push_down(int u){
	int numa = (u << 1), numb = (numa | 1);
	tr[numa].sum += tr[u].add * (ll)tr[numa].siz;
	tr[numb].sum += tr[u].add * (ll)tr[numb].siz;
	tr[numa].add += tr[u].add;
	tr[numb].add += tr[u].add;
	tr[u].add = 0;
}

void push_back(int u){
	int numa = (u << 1), numb = (numa | 1);
	tr[u].sum = tr[numa].sum + tr[numb].sum;
}

void add(int u, int st, int re, ll val){
	int l = tr[u].l, r = tr[u].r;
	if(l > re || r < st) return;
	if(l >= st && r <= re){
		tr[u].sum += val * (ll)tr[u].siz;
		tr[u].add += val;
	}
	else{
		push_down(u);
		if(l <= re) add((u << 1), st, re, val);
		if(r >= st) add(((u << 1) | 1), st, re, val);
		push_back(u);
	}
}

void ask(int u, int st, int re){
	int l = tr[u].l, r = tr[u].r;
	if(l > re || r < st) return;
	if(l >= st && r <= re){
		ans += tr[u].sum;
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
		scanf("%d", &a[i]);
	}
	tr[1].l = 1, tr[1].r = n;
	build(1, 1, n);
	for(int i = 1; i <= m; i++){
		int op;
		scanf("%d", &op);
		if(op == 1){
			int st, re;
			ll k, d;
			scanf("%d %d %lld %lld", &st, &re, &k, &d);
			add(1, st, st, k);
			add(1, st+1, re, d);
			add(1, re+1, re+1, -k-(re-st)*d);
		}
		if(op == 2){
			ans = 0;
			int pos;
			scanf("%d", &pos);
			ask(1, 1, pos);
			ans += (ll)a[pos];
			printf("%lld\n", ans);
		}
	}
	return 0;
}
