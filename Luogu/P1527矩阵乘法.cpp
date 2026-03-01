// clang-format off
#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
#define db double
using namespace std;

inline int read(){
	int x = 0, f = 1; char ch = getchar();
	while(!isdigit(ch)){if(ch == '-') f = -1; ch = getchar();}
	while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - 48; ch = getchar();}
	return x * f;
}

const int N = 5e2 + 5, Q = 4e5 + 5;

struct Query{
	int x1, y1, x2, y2, rk, id;
	bool typ;
}q[Q], q1[Q], q2[Q];
int n, qtot, tr[N][N], ls[N*N], tot, a[N][N], ans[Q], c[N][N];

int lb(int x){return x & -x;}
void op_add(int x1, int y1, int val){
	for(int i = x1; i <= n; i += lb(i)){
		for(int j = y1; j <= n; j += lb(j)) tr[i][j] += val;
	}
}
int qr_pre(int x1, int y1){
	int res = 0;
	for(int i = x1; i; i -= lb(i)){
		for(int j = y1; j; j -= lb(j)) res += tr[i][j];
	}
	return res;
}
int qr_cnt(int x1, int y1, int x2, int y2){
	return qr_pre(x2, y2) - qr_pre(x1-1, y2) - qr_pre(x2, y1-1) + qr_pre(x1-1, y1-1);
}

void solve(int l, int r, int ql, int qr){
	if(ql > qr) return;
	if(l == r){
		for(int i = ql; i <= qr; i++){
			if(q[i].typ) ans[q[i].id] = ls[l];
		}
		return;
	}
	int mid = (l + r) >> 1;
	int p1 = 0, p2 = 0;
	for(int i = ql; i <= qr; i++){
		if(!q[i].typ){
			if(c[q[i].x1][q[i].y1] <= mid){
				op_add(q[i].x1, q[i].y1, 1);
				q1[++p1] = q[i];
			}
			else q2[++p2] = q[i];
		}
		else{
			int jud = qr_cnt(q[i].x1, q[i].y1, q[i].x2, q[i].y2);
			if(q[i].rk <= jud) q1[++p1] = q[i];
			else{
				q[i].rk -= jud;
				q2[++p2] = q[i];
			}
		}
	}
	for(int i = ql; i <= qr; i++){
		if(!q[i].typ && c[q[i].x1][q[i].y1] <= mid) op_add(q[i].x1, q[i].y1, -1);
	}
	for(int i = 1; i <= p1; i++) q[ql+i-1] = q1[i];
	for(int i = 1; i <= p2; i++) q[ql+p1+i-1] = q2[i];
	solve(l, mid, ql, ql + p1 - 1);
	solve(mid + 1, r, ql + p1, qr);
}

int main(){
	// int fab = -1;
	// cout << (fab >> 1) << endl;
	// cout << (~fab) << endl;
	n = read(), qtot = read();
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			a[i][j] = read();
			ls[++tot] = a[i][j];
			q[(i-1)*n+j] = {i, j, i, j, 0, 0, 0};
		}
	}
	sort(ls + 1, ls + 1 + tot);
	tot = unique(ls + 1, ls + 1 + tot) - ls - 1;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			c[i][j] = lower_bound(ls + 1, ls + 1 + tot, a[i][j]) - ls;
	for(int i = 1, x1, y1, x2, y2, rk; i <= qtot; i++){
		x1 = read(), y1 = read(), x2 = read(), y2 = read(), rk = read();
		q[n*n+i] = {x1, y1, x2, y2, rk, i, 1};
	}
	solve(1, tot, 1, qtot + n * n);
	for(int i = 1; i <= qtot; i++) printf("%d\n", ans[i]);
	return 0;
}