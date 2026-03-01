#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
#define db double
using namespace std;

inline int read() {
	int x = 0, f = 1;
	char ch = getchar();
	while(!isdigit(ch)) {
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(isdigit(ch)) {
		x = (x << 3) + (x << 1) + ch - 48;
		ch = getchar();
	}
	return x * f;
}

const int N = 2e5 + 5;  

struct Nd {
	int x, y, z, id, cnt, f;
} a[N], b[N];
int n, m, mx, val[N], f[N], ans[N];

bool cmpx(Nd aa, Nd bb) {
	if(aa.x == bb.x) {
		if(aa.y == bb.y) return aa.z < bb.z;
		return aa.y < bb.y;
	}
	return aa.x < bb.x;
}
bool cmpy(Nd aa, Nd bb) {
	if(aa.y == bb.y) return aa.z < bb.z;
	return aa.y < bb.y;
}
int lb(int x) {
	return x & -x;
}
void op_add(int u, int v) {
	for(int i=u; i<=mx; i+=lb(i)) val[i]+=v;
}
int qr_val(int u) {
	int res=0;
	for(int i=u; i; i-=lb(i)) res+=val[i];
	return res;
}

void cdq(int l, int r) {
	if(l == r) return;
	int mid = (l + r) >> 1;
	printf("l:%d r:%d\n", l, r);
	cdq(l, mid);
	cdq(mid+1, r);
	sort(a + l, a + mid + 1, cmpy);
	sort(a + 1 + mid, a + r + 1, cmpy);
	int i = l, j = mid+1;
	for( ; j <= r; j++) {
		while(a[i].y <= a[j].y && i <= mid) op_add(a[i].z, a[i].cnt), i++;
		a[j].f += qr_val(a[j].z);  
	}
	for(int k = l; k < i; k++) op_add(a[k].z, -a[k].cnt);
	return;
}

int main() {
//	freopen("P3810_1.in", "r", stdin);
	freopen("1.out", "w", stdout);
	m = read(), mx = read();
	for(int i = 1; i <= m; i++) b[i].x = read(), b[i].y = read(), b[i].z = read(), b[i].id = i;
	sort(b + 1, b + 1 + m, cmpx);
	for(int i = 1; i <= m; i++) {
		if(b[i].x == b[i-1].x && b[i].y == b[i-1].y && b[i].z == b[i-1].z) a[n].cnt++;
		else a[++n] = b[i], a[n].cnt = 1;
	}
	cdq(1, n);
	for(int i = 1; i <= n; i++) ans[a[i].f+a[i].cnt-1] += a[i].cnt;
	for(int i = 0; i < m; i++) printf("%d\n", ans[i]);
	return 0;
}
