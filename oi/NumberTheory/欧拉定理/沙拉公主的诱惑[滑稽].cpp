#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

const int Maxn = 1e7+5;

int t;
ll n, m, r;
ll p[Maxn], cnt;
bool b[Maxn], pm[Maxn];
ll fi[Maxn];
ll mul[Maxn];
ll ans;

void Prime(ll x){
	for(int i = 2; i <= x; i++){
		if(!b[i]){
			p[++cnt] = i;
			pm[i] = true;
		}
		for(int j = 1; j <= cnt && i*p[j] <= x; j++){
			b[i*p[j]] = true;
			if(i % p[j] == 0){
				break;
			}
		}
	}
	fi[0] = 1;
	for(ll i = 1; i <= x; i++){
		if(!pm[i]) fi[i] = fi[i-1] * i % r;
		else fi[i] = fi[i-1] * (i-1) % r;
	}
	mul[0] = 1;
	for(ll i = 1; i <= x; i++){
		mul[i] = mul[i-1] * i % r;
	}
}

ll rapid(ll x, ll idx){
	ll ans = 1, jud = x;
	while(idx != 0){
		int pos = idx & 1;
		if(pos) ans = ans * jud % r;
		jud = jud * jud % r;
		idx >>= 1;
	}
	return ans % r;
}

int main(){
//	freopen("P2155_2.in", "r", stdin);
//	freopen("1", "w", stdout);
	scanf("%d %lld", &t, &r);
	Prime(Maxn);
	for(int ii = 1; ii <= t; ii++){
		scanf("%lld %lld", &n, &m);		
		ans = fi[m] * mul[n] % r * rapid(mul[m], r-2) % r;
		printf("%lld\n", ans);
	}
	return 0;
}
