#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
#define llu unsigned long long
using namespace std;

int read(){
	int x = 0,f = 1;char ch = getchar();
	while (ch < '0' || ch > '9'){if (ch == '-') f = -1; ch = getchar();}
	while (ch >= '0' && ch <= '9'){x = x*10 + ch - 48; ch = getchar();}
	return x * f;
}

int n, m;

ll gcd(llu x, llu y){
	return y == 0? y: gcd(y, x%y);
}

ll qp(int x, int idx){
	llu res = 1, jud = 1;
	while(idx){
		jud *= x;
		if(idx & 1) res *= jud;
		idx >>= 1;
	}
	return res;
}

int main(){
	n = read(), m = read();
	ll jud = qp(2, n);
	ll s = 1, t = 1;
	for(int i = jud; i > jud - m; --i) s *= i;
	for(int i = 1; i <= m; i++) t *= jud;
	ll d = gcd(t-s, t);
	ll a = (t-s)/d, b = t/d;
	printf("%lld %lld", a, b);
	return 0;
}

