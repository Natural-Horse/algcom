#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

int read(){
	int x = 0,f = 1;char ch = getchar();
	while (ch < '0' || ch > '9'){if (ch == '-') f = -1; ch = getchar();}
	while (ch >= '0' && ch <= '9'){x = x*10 + ch - 48; ch = getchar();}
	return x * f;
}

const int N = 1e3 + 5, Q = 3e5 + 5;

int n, q;
int sp[Q], c[Q], ln[Q], s[Q];
struct Tree{
	int l, r;
	ll add;
}tr[N][N<<2];

void build(int u, int l, int r, int lim){
	for(int i = 1; i <= lim; i++) tr[u][i].l = l, tr[u][i].r = r;
	if(l != r){
		int na = u << 1, nb = na | 1, mid = (l + r) >> 1;
		build(na, l, mid, lim), build(nb, mid + 1, r, lim);
	}
}
void push_down(int u, int lim){
	int na = u << 1, nb = na | 1;
	tr[na][lim].add += tr[u][lim].add, tr[nb][lim].add += tr[u][lim].add;
	tr[u][lim].add = 0;
}
void op_add(int u, int st, int re, ll val, int lim){
	int l = tr[u][lim].l, r = tr[u][lim].r;
	if(l > re || r < st) return;
	if(l >= st && r <= re){
		tr[u][lim].add += val; return;
	} 
	if(l != r){
		push_down(u, lim);
		op_add(u<<1, st, re, val, lim), op_add(u<<1|1, st, re, val, lim);
	}
}
ll query_xor(int u, int l, int r, int lim, bool fab){
	if(l != r){
		for(int i = 1; i <= lim; i++) push_down(u, i);
		int mid = (l + r) >> 1, na = u << 1, nb = na | 1;
		return query_xor(na, l, mid, lim, fab) ^ query_xor(nb, mid+1, r, lim, fab);	
	}
	else{
		ll res = 0;
		if(fab){
			if((n - tr[u][lim].l + 1) % 2 == 0) res = tr[u][lim].add;
			else res = 0;
		} 
		else {
			for(int i = 1; i <= lim; i++){
				res ^= tr[u][i].add;
				printf("%d ", tr[u][i].add);
			}
			printf("\n");
		}
		return res;
	}
}

int main(){
	n = read(), q = read();
	if(q == 0){
		printf("0");
		return 0;
	}
	bool check = true;
	for(int i = 1; i <= q; i++){
		sp[i] = read(), c[i] = read(), ln[i] = read(), s[i] = read();
		if(sp[i] + ln[i] != n + 1 || c[i] != 1) check = false;
	}
	if(check == true){
		build(1, 1, n, 1);
		for(int i = 1; i <= q; i++){
			op_add(1, sp[i], sp[i]+ln[i]-1, s[i], 1);
		}
		ll ans = query_xor(1, 1, n, 1, true);
		printf("%lld", ans);
		return 0;
	}
	else{
		build(1, 1, n, n);
		for(int i = 1; i <= q; i++){
			int num = 0;
			for(int j = sp[i]; j < sp[i] + ln[i]; j++){
				op_add(1, c[i], min(c[i]+num,n), s[i], j);
				num++;
			}
		}
		ll ans = query_xor(1, 1, n, n, false);
		printf("%lld", ans);
		return 0;
	}
}
