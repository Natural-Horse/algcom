#include<bits/stdc++.h>          //weixin_3808253
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
	int ls, rs, mid, p;
}tr[N << 2];
int n, m;
int b[1000005];

void build(int u, int l, int r){
	tr[u].l = l, tr[u].r = r, tr[u].siz = r - l + 1;
	if(l != r){
		int na = u << 1, nb = na | 1, mid = (l + r) >> 1;
		build(na, l, mid), build(nb, mid + 1, r);
		return;
	}
}
int query_pos(){
	if(tr[1].ls == 0) return 1;
	int res = max(tr[1].ls - 1, max(tr[1].mid, n-tr[1].rs));
	if(res == tr[1].ls - 1) return 1;
	else if(res == tr[1].mid) return tr[1].p;
	else return n;
}
void push_back(int u){
	int na = u << 1, nb = na | 1;
	if(tr[na].ls == 0 || tr[nb].ls == 0) tr[u].ls = tr[na].ls + tr[nb].ls;//有一个是0,那么两个的和就
	                                                                      //是不是0的那个的值 
	else tr[u].ls = min(tr[na].ls, tr[nb].ls);
	tr[u].rs = max(tr[na].rs, tr[nb].rs);//右节点直接取最大,如果两个都是0,则说明两个小区间最右边都没有fairy,
	                                     //所以大区间右边肯定也是通的，所以直接取最大即可 
	int pa = tr[na].rs, pb = tr[nb].ls;
	if(pa && pb)
		tr[u].mid = max(tr[na].mid, max((pb-pa)>>1, tr[nb].mid));
	else if(pa) tr[u].mid = tr[na].mid;
	else if(pb) tr[u].mid = tr[nb].mid;
	else tr[u].mid = 0, tr[u].p = 0;
	if(tr[u].mid == tr[na].mid) tr[u].p = tr[na].p;
	else if(tr[u].mid == (pb-pa)>>1) tr[u].p = (pa + pb) >> 1;
	else tr[u].p = tr[nb].p;
}
void op_update(int u, int plc){
	int l = tr[u].l, r = tr[u].r;
	if(l > plc || r < plc) return;
	if(l == plc && r == plc){
		tr[u].ls = tr[u].rs = l;
		tr[u].mid = 0, tr[u].p = 0;
		return;
	}
	if(l != r){
		op_update(u << 1, plc), op_update(u << 1 | 1, plc);
		push_back(u);
	}
	return;
}
void op_delete(int u, int plc){
	int l = tr[u].l, r = tr[u].r;
	if(l > plc || r < plc) return;
	if(l == plc && r == plc){
		tr[u].ls = tr[u].rs = 0;
		tr[u].mid = 0, tr[u].p = 0;
		return;
	}
	if(l != r){
		op_delete(u << 1, plc), op_delete(u << 1 | 1, plc);		
		push_back(u);
	}
	return;
}

int main(){
	n = read(), m = read();
	build(1, 1, n);
	for(int i = 1, op, fab; i <= m; i++){
		op = read(), fab = read();
		if(op == 1){
			b[fab] = query_pos();
			op_update(1, b[fab]);
			printf("%d\n", b[fab]);
		}
		else if(op == 2){
			op_delete(1, b[fab]);
			b[fab] = 0;
		}
	}
	return 0;
}
