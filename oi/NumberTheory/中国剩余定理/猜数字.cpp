#include <bits/stdc++.h>
#define inf 0x3f3f3f3f3f3f3f3f
#define ll long long
using namespace std;

const int Maxn = 15;

int n;
ll a[Maxn], b[Maxn];
ll ans, g;

ll gcd(ll aa, ll bb){
	return bb == 0? aa: gcd(bb, aa%bb);
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%lld", &a[i]);
	}
	for(int i = 1; i <= n; i++){
		scanf("%lld", &b[i]);
	}
	g = b[1], ans = a[1];
	for(int i = 2; i <= n; i++){
		while(ans % b[i] != a[i]) ans += g;
		g = g / gcd(b[i], g) * b[i];
	}
	printf("%lld", ans);
	return 0;
}
