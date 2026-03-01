#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

const int Maxn = 105;

ll n, k;
ll a[Maxn];
ll ans, N;

int main(){
	scanf("%lld %lld", &n, &k);
	for(ll i = 1; i <= n; i++){
		scanf("%lld", &a[i]);
		N += a[i];
	} 
	N += k;
	ll d = 0;
	while(1){
		if(N / (d+1) <= 0) break;
		d = N / (N / (d + 1));
		ll jud = 0;
		for(ll i = 1; i <= n; i++){
			jud += ((ll)(a[i] % d != 0) + a[i] / d) * d;
		}
		if(jud <= N) ans = d;
	}
	printf("%lld", ans);
	return 0;
}
