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

const int N = 2e5 + 5;

struct Tree{
	int l, r, siz;
	int mx, pre, val;
}tr[N << 2];
int n, p[N], w[N], f[N];

void build(int u, int l, int r){
	tr[u].l = l, tr[u].r = r;
	int mid = (l + r) >> 1;
	if(l != r)
		build(u<<1, l, mid), build(u<<1|1, mid+1, r);
	return;
}
int calc(int u, int lim){
	int l = tr[u].l, r = tr[u].r;
	if(l == r) return tr[u].mx > lim? f[tr[u].mx]: inf;
	if(tr[u<<1|1].mx <= lim) return calc(u << 1, lim);
	else return min(tr[u].pre, calc(u << 1 | 1, lim));
}
void insert(int u, int plc, int id, int val){
	int l = tr[u].l, r = tr[u].r;
	if(l > plc || r < plc) return;
	if(l == plc && r == plc){
		f[id] = val, tr[u].mx = id;
		return;
	}
	insert(u << 1, plc, id, val), insert(u << 1 | 1, plc, id, val);
	tr[u].mx = max(tr[u<<1].mx, tr[u<<1|1].mx);
	tr[u].pre = calc(u<<1, tr[u<<1|1].mx);
}
int id, v;
void query_all(int u, int plc){
	int r = tr[u].r, l = tr[u].l;
	if(l > plc) return;
	if(r <= plc){
		v = min(v, calc(u, id)), id = max(id, tr[u].mx);
		return;	
	}
	query_all(u << 1, plc);
	query_all(u << 1 | 1, plc);
}

int main(){
//	freopen("sample.in", "r", stdin);
//	freopen("output.out", "w", stdout);
	n = read();
	build(1, 1, n);
	for(int i = 1; i <= n; i++) p[i] = read(), f[i] = inf;
	for(int i = 1; i <= n; i++) w[i] = read();
	for(int i = 1; i <= n; i++){
		id = 0, v = inf;
		query_all(1, p[i]);
		insert(1, p[i], i, (v<inf?v:0)+w[i]);
	}
	int ans = inf;
	for(int i = n, num = 0; i; --i){
		if(p[i] > num) num = p[i], ans = min(ans, f[i]);
	}
	printf("%d", ans);
	return 0;
}

