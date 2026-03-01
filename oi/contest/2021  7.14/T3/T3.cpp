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
const int N = 1e5 + 5;
//struct Tree{
//	int l, r, siz;
//	int maxl, maxr, maxn, p;
//}tr[N<<2];
int n, m;
bool b[N];
int p[1000005];
int ra, lb;
//int l[N], r[N], len[N], plc[N];
//
//void build(int u, int l, int r){
//	tr[u].l = l, tr[u].r = r, tr[u].siz = r - l + 1;
//	if(l != r){
//		int na = u << 1, nb = na | 1, mid = (l + r) >> 1;
//		build(na, l, mid), build(nb, mid + 1, r);
//	}
//	else tr[u].maxl = 0, tr[u].maxr = n+1, tr[u].maxn = n+2, tr[u].p = l;
//}
//
//void push_back(int u){
//	int na = u << 1, nb = na | 1;
//	if(tr[])
//}

int main(){
	n = read(), m = read();
//	for(int i = 1; i <= n; i++){
//		l[i] = 0, r[i] = n + 1;
//	}
	ra = n-1, lb = n;
	for(int i = 1, op, fab; i <= m; i++){
		op = read(), fab = read();
		if(op == 1){
			int l = 0, r = 0, len = 0, plc = 1;
			bool check = true;
			if(b[1]) l = 0;
			for(int j = 1; j <= n; j++){
				if(b[j]) check = false;
				else {
					while(!b[j] && j <= n){
						if(!check) l = j, check = true;
						if(r != n+lb) r = j;
						j++;
					}
					if(r == n) r = n + lb;
					if(l == 0){
						l = -ra;
					}
					if(l == -ra && r == lb) len = 2 * n, plc = 1;
					else if(r - l + 1 > len){
						len = r - l + 1;
						plc = (r + l + 1) >> 1;
					}
					j--;
				}
			}
			b[plc] = true;
			p[fab] = plc;
			ra = min(ra, plc-1);
			lb = min(lb, n-plc);
			printf("%d\n", plc);
		}
		if(op == 2){
			b[p[fab]] = false;
		}
	}
	return 0;
}

