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

int n, m, k;

int main(){
	n = read(), m = read(), k = read();
	for(int i = 1, x, y; i <= k; i++) x = read(), y = read();
	double ans = n/2;
	printf("%lf", ans);
	return 0;
}

