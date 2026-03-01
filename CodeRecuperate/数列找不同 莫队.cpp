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

const int N = 1e5 + 5;

struct Q{
	int l, r, p;
}qr[N];
int n, q, a[N], len, L, R, chk[N], cnt;
bool ans[N];

bool cmp(Q sa, Q sb){
	return (sa.l / len) == (sb.l / len)? sa.r < sb.r: sa.l < sb.l;
}

int main(){
	n = read(), q = read();
	len = sqrt(n);
	for(int i = 1; i <= n; i++) a[i] = read();
	for(int i = 1; i <= q; i++){
		qr[i].l = read(), qr[i].r = read();
		qr[i].p = i;
	}
	sort(qr + 1, qr + 1 + q, cmp);
	L = 1, R = 1, chk[a[1]] = 1, cnt = 1;
	for(int i = 1; i <= q; i++){
		while(L < qr[i].l){if(chk[a[L]] == 1) cnt--; chk[a[L++]]--;}
		while(R > qr[i].r){if(chk[a[R]] == 1) cnt--; chk[a[R--]]--;}
		while(L > qr[i].l){if(chk[a[--L]] == 0) cnt++; chk[a[L]]++;}
		while(R < qr[i].r){
			if(chk[a[++R]] == 0) cnt++; 
			chk[a[R]]++;
		}
		cnt == (R - L + 1)? ans[qr[i].p] = true: ans[qr[i].p] = false;
	}
	for(int i = 1;i <= q; i++){
		if(ans[i]) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}

