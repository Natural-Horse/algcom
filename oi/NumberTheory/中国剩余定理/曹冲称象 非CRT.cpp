#include<bits/stdc++.h>
#define inf 0x3f3f3f3f3f3f3f3f
#define ll long long
using namespace std;

const int Maxn = 15;

int n;
ll a[Maxn], b[Maxn];
ll g, ans;

ll gcd(ll aa, ll bb){
	return bb == 0? aa: gcd(bb, aa%bb);
}

int main(void){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%lld %lld", &a[i], &b[i]);
	}
	g = a[1];
	ans = b[1];
	for(int i = 2; i <= n; i++){
		while(ans % a[i] != b[i]) ans += g;
		g = a[i] / gcd(a[i], g) * g;
	}
	printf("%lld", ans);
	return 0;
}
