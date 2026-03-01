#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

inline int read(){
	int x = 0, f = 1; char ch = getchar();
	while(!isdigit(ch)){if(ch == '-') f = -1; ch = getchar();}
	while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - 48; ch = getchar();}
	return x * f;
}

const int N = 1e5 + 5;
int n, q, val[N], a[N];
struct Tr{
	int l, r, val;
}tr[N << 4];

int build(int u, int l, int r){
	if(l == r){tr[u].val = a[l]; return a[l];}
	int mid = (l + r) >> 1, na = u << 1, nb = (u << 1) | 1;
	int lv = build(na, l, mid);
	int rv = build(nb, mid + 1, r);
	if(lv != rv || (lv == -1) && (rv == -1)) return -1;
	else{tr[u].val = lv; return lv;}
}

int query_sm(int u, int st, int re){
	int l = tr[u].l, r = tr[u].r;
	if(l > re|| r < st) return 0;
	if(l >= st && r <= re) return tr[u].val;
	int lv = query_sm(u << 1, st, re);
	int rv = query_sm((u << 1) | 1, st, re);
	if(lv == -1 || rv == -1 || (lv > 0 && rv > 0 && lv != rv)) return -1;
	else return lv == 0? rv : lv;
}

int main(){
	n = read(), q = read();
	for(int i = 1; i <= n; i++) a[i] = read();
	build(1, 1, n);
	for(int i = 1; i <= q; i++){
		int st = read(), re = read();
		int ans = query_sm(1, st, re);
		if(ans == -1)  printf("Yes\n");
		else printf("No\n");
	}
	return 0;
	
}
