#include<cstdio>
#include<cctype>
#include<cstring>
#include<algorithm>

using namespace std;

inline int read() {
	char c = getchar(); int x = 0, f = 1;
	while(!isdigit(c)) {if(c == '-') f = -1; c = getchar();}
	do {x = x * 10 + (c ^ 48); c = getchar();} while(isdigit(c));
	return x * f;
}

const int N = 4e5 + 29;
struct dat {
	int l, r, k, id, type; 
} opt[N], q1[N], q2[N];
int a[N], b[N], c[N], bit[N], ans[N], ch[N];
int n, m, cnt;

void add(int x, int v) {
	while(x <= n) {
		bit[x] += v;
		x += x & -x;
	}
}

int sum(int x) {
	int res = 0;
	while(x) {
		res += bit[x];
		x -= x & -x;
	}
	return res;
}

void solve(int sb, int se, int l, int r) {
	if(sb > se) return;
	if(l == r) {
		for(int i = sb; i <= se; ++i)
			if(opt[i].type) ans[opt[i].id] = l;
		return;
	}
	int mid = (l + r) >> 1, cur = 0;
	int cnt1 = 0, cnt2 = 0;
	for(int i = sb; i <= se; ++i) {
		if(!opt[i].type) {
			if(opt[i].k <= mid) {
				add(opt[i].id, 1);
				ch[++cur] = opt[i].id;
				q1[++cnt1] = opt[i];
			} else q2[++cnt2] = opt[i];
		} else {
			int tmp = sum(opt[i].r) - sum(opt[i].l - 1);
			if(opt[i].k <= tmp) q1[++cnt1] = opt[i];
			else {
				opt[i].k -= tmp;
				q2[++cnt2] = opt[i];
			}
		}
	}
	for(int i = 1; i <= cur; ++i) add(ch[i], -1);
	for(int i = 1; i <= cnt1; ++i)
		opt[sb + i - 1] = q1[i];
	for(int i = 1; i <= cnt2; ++i)
		opt[sb + i - 1 + cnt1] = q2[i];
	solve(sb, sb + cnt1 - 1, l, mid);
	solve(sb + cnt1, se, mid + 1, r);
}

int main() {
	n = read(), m = read();
	for(int i = 1; i <= n; ++i) {
		a[i] = read(); b[i] = a[i];
	}
	sort(b + 1, b + n + 1);
	int tot = unique(b + 1, b + n + 1) - b - 1;
	for(int i = 1; i <= n; ++i) {
		int p = lower_bound(b + 1, b + tot + 1, a[i]) - b;
		c[p] = a[i]; a[i] = p;
		opt[++cnt] = (dat) {0, 0, p, i, 0};
	}
	for(int i = 1; i <= m; ++i) {
		int left = read(), right = read(), k = read();
		opt[++cnt] = (dat) {left, right, k, i, 1};
	}
	solve(1, cnt, 1, tot);
	for(int i = 1; i <= m; ++i)
		printf("%d\n", c[ans[i]]);
	return 0;
}