#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

const int Maxn = 1e7+5;

int t;
ll p;
bool b[Maxn];
ll pr[Maxn], cnt;

void Prime(int x){
	for(int i = 2; i <= sqrt(x); i++){
		if(b[i] == 0) pr[++cnt] = i;
		for(int j = 1; j <= cnt && pr[j]*i <= sqrt(x); j++){
			b[i*pr[j]] = 1;
			if(!i % pr[j]) break;
		}
	}
}

ll euler(ll x){
	ll aa = x;
	for(int i = 1; i <= cnt && pr[i] <= sqrt(x); i++){
		if(x % pr[i] == 0) aa = aa / pr[i] * (pr[i]-1);
		while(x % pr[i] == 0) x /= pr[i];
	}
	if(x > 1) aa = aa / x * (x-1);
	return aa;
}

ll gcd(ll a, ll b){
	return b? gcd(b, a%b): a;
}

ll rapid(ll x, ll idx, ll mod){
	ll ans = 1;
	while(idx){		
		if((idx&1) == 1){
			ans = ans * x % mod;
		}
		idx >>= 1;
		x = x*x % mod;
	}
	ans %= mod;
	return ans;
}

ll dfs(ll x){
	ll mod = euler(x);
	if(mod == 1){
		return 2;
	}
	ll aa = 1, idx = dfs(mod);
	aa = rapid(2, idx, mod);
	aa = aa % mod + mod;
	return aa;
}

int main(){
	scanf("%d", &t);
	Prime(Maxn);
	for(int ii = 1; ii <= t; ii++){
		scanf("%lld", &p);
		ll aa = dfs(p);
		ll ans = rapid(2, aa, p);
		printf("%lld\n", ans);
	}
	return 0;
} 
