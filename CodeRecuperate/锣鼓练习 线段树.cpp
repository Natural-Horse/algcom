#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

inline int read(){
	int x = 0, f = 1; char ch = getchar();
	while(!isdigit(ch)){if(ch == '-') f = -1;ch = getchar();}
	while(isdigit(ch)){x = (x << 1) + (x << 3) + ch - 48; ch = getchar();}
	return x * f;
}

const int N = 2e5 + 5;

struct Tr{
	int l, r, val, dev;
	ll len, pre;
}tr[N << 2];
int c, q;

void build(int u, int l, int r){
	tr[u].l = l, tr[u].r = r, tr[u].dev = -1;
	if(l == r) return;
}

void push_down(int u){
	int na = u << 1, nb = na | 1;
	if(tr[u].dev != -1){
		tr[na].val = tr[na].dev = tr[u].dev;
		tr[nb].val = tr[nb].dev = tr[u].dev;
	}
	tr[u].dev = -1;
	tr[u].val = max(tr[na].val, tr[nb].val);
}

void op_add(int u, int pos, int val){
	if(tr[u].l > pos || tr[u].r < pos) return;
	if(tr[u].l == pos && tr[u].r == pos){
		tr[u].dev = -1, tr[u].val = val, tr[u].len = val;
		return;
	}
	op_add(u << 1, pos, val), op_add((u << 1) | 1, pos, val);
	return;
}

void op_del(int u, int st, int re, int val){
	int l = tr[u].l, r = tr[u].r;
	if(l > re || r < st) return 0;
	if(l >= st && r <= re){
		if(tr[u].len > val) tr[u] -= val
	}
}

int main(){
	c = read(), q = read();
	
}

