#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

const int Maxn = 1e6 + 5;

int n;
ll a[Maxn];
ll cnt[Maxn], p[Maxn], q[Maxn];
ll sum = 1, ans, tot;
set<ll> s;

ll qp(ll x, ll idx){
	ll res = 1, jud = x;
	while(idx){
		if(idx & 1) res *= jud;
		idx >>= 1;
		jud *= jud;
	}
	return res;
}

void div(ll x){
	for(int i = 2; i <= 1000; i++){
		if(x % i == 0){
			p[++tot] = i;
			cnt[i] = 0;
			while(x % i == 0){
				x /= i;
				cnt[tot]++;
			}
		}
	}
	if(x > 1) p[++tot] = x, cnt[tot] = 1;
}

ll gcd(ll aa, ll bb){
	return bb == 0? aa: gcd(bb, aa % bb);
}

bool check(ll x, ll y, ll qq){
	if(x % y != 0) return false;
	x /= y;
	while(x % qq == 0){
		x /= qq;
	}
	if(x == 1) return true;
	else return false;
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		q[i] = 1;
	}
	for(int i = 1; i <= n; i++){
		scanf("%lld", &a[i]);
		if(a[i] == a[i-1]) sum++, ans = max(ans, sum);
		else sum = 1;
		if(i >= 2){
			tot = 0;
			ll x = max(a[i], a[i-1]), y = min(a[i], a[i-1]);
			if(x % y != 0){
//				q[i - 1] = 0;
				continue;
			} 
			div(x / y);
			ll jud = cnt[1];
			for(int j = 2; j <= tot; j++){
				if(jud == 1){
					break;
				} 
				jud = gcd(jud, cnt[j]);
			}
			for(int j = 1; j <= tot; j++){
				q[i - 1] *= qp(p[j], cnt[j] / jud);
//				cnt[j] = 0;
//				if(q[i - 1] > 10){
//					q[i - 1] = 0;
//					break;
//				}
			}
		}
	}
	for(int i = 2; i <= n; i++){
		if(q[i - 1]){
			if(q[i - 1] == 1) continue;
			s.clear();
			s.insert(a[i - 1]), s.insert(a[i]);
			for(ll j = i + 1; j <= n; j++){
				if(s.count(a[j])){
					break;
				}
				ll x = max(*--s.end(), a[j]);
				ll y = min(*--s.end(), a[j]);
				if(check(x, y, q[i - 1])){
					s.insert(a[j]);
				} 
				else break;
			}
			ll add = s.size();
			ans = max(ans, add);
		}		
	}
	printf("%lld", ans);
	return 0;
}
