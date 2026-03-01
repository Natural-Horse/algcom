#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
#define ld long double
#define ull unsigned long long
using namespace std;

ll n, m, l;

inline ll qmul(ll x,ll y,ll p){
	ll z=(ld)x/p*y;
	ll res=(ull)x*y-(ull)z*p;
	return (res+p)%p;
}

ll qp(ll x, ll idx, ll mod){
	ll ans = 1, jud = x;
	while(idx){
		if(idx & 1) ans = qmul(ans, jud, mod);
		jud = qmul(jud, jud, mod);
		idx >>= 1;
	}
	return ans;
}

ll exgcd(ll a, ll b, ll &x, ll &y){
	if(b == 0){
		x = 1, y = 0;
		return a;
	}
	ll d = exgcd(b, a%b, x, y);
	ll jud = x;
	x = y, y = jud - (a / b) * y;
	return d;
}

int main(){
	scanf("%lld %lld %lld", &n, &m, &l);	
	ll a = qp(2, m, n+1);
	ll ansa = 0, ansb = 0;
	ll d = exgcd(a, n+1, ansa, ansb);
	ansa = qmul(ansa/d, l, n+1);
	ansa = (ansa + (n+1)) % (n+1);
	while(ansa <= 0){
		ansa += n+1;
	}
	ansa = ansa % (n+1);
	printf("%lld", ansa);
	return 0;
} 
