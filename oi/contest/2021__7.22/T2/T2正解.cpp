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
	int fab;
}tr[N << 5];

int n, m, k, a[N], b[N], c[N], w[N], fa, fb, cnta, cntb, cntc;
ll ls[N<<3], tot, num;
bool ba[N], bb[N], bc[N];

void build(int u, int l, int r){
	tr[u].l = l, tr[u].r = r, tr[u].siz = r - l + 1;
	if(l != r){
		int na = u << 1, nb = na | 1, mid = (l + r) >> 1;
		build(na, l, mid), build(nb, mid + 1, r);
	}
}
void push_back(int u){
	tr[u].fab = tr[u<<1].fab + tr[u<<1|1].fab;
}
void op_insert(int u, int val){
	int l = tr[u].l, r = tr[u].r;
	if(l > val || r < val) return;
	if(l == val && r == val){
		tr[u].fab++;
		return;
	}
	if(l != r){
		op_insert(u<<1, val), op_insert(u<<1|1, val);
		push_back(u);
	}
}
int 

int main(){
	n = read(), m = read(), k = read();
	for(int i = 1; i <= n; i++) w[i] = read();
	fa = read();
	for(int i = 1, juda; i <= fa; i++){
		juda = read();
		ls[++tot] = juda;
		if(juda!=1) ls[++tot] = juda-1; ls[++tot] = juda+1;
		ba[juda] = true;
	}
	fb = read();
	for(int i = 1, judb; i <= fb; i++){
		judb = read();
		if(ba[judb]) bc[judb] = true, ba[judb] = false, c[++cntc] = judb;
		else bb[judb] = true, b[++cntb] = judb;
		ls[++tot] = judb;
		if(judb!=1) ls[++tot] = judb-1; ls[++tot] = judb+1;
	}	
	for(int i = 1; i <= n; j++){
		if(ba[i]) a[++cnta] = i;
		if(!ba[i]&&!bb[i]&&!bc[i])
	}
	sort(ls + 1, ls + 1 + tot);
	num = unique(ls + 1, ls + 1 + tot) - ls - 1;
	for(int i = 0; i <= min(k, cntc); i++){
		
	}
}

