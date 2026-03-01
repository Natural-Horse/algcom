#include<bits/stdc++.h>
#define inf 0x3f3f3f3f3f3f3f3f
#define ll long long
using namespace std;

const int Maxn = 105;

ll n,k;
ll a[Maxn], h[Maxn];
ll l, r;
ll maxn;

bool check(ll x){
	ll le = k, cnt = 0;
	for(int i = 1; ; i++){
		for(int j = 1; j <= n; j++){
			if(h[j] == 0 && i != 1) continue;
			h[j] += x;
			if(h[j] > a[j]){
				le -= (h[j] - a[j]);
				h[j] = 0;
				cnt++;
			}
		}
		if(cnt == n) break;
	}
	if(le >= 0) return true;
	else return false;
}

int main(){
	scanf("%lld %lld", &n, &k);
	for(int i = 1; i <= n; i++){
		 scanf("%lld", &a[i]);
		 maxn = max(maxn, a[i]);
	} 
	ll jud = 0;
	r = maxn;
	for(int i = 1; i <= n; i++){
		jud += maxn - a[i];
	}
	r += (k - jud) / n;
	for(int i = )
		ll mid = ((l + r) >> 1);
		if(check(mid)) l = mid + 1;
		else r = mid;
	}
	printf("%lld", l);
	return 0;
}
