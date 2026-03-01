#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

const int Maxn = 1e6 + 5;

int n;
ll a[Maxn];
ll r, jud, len = 1, ans;
ll p[63][Maxn], f[63][Maxn], plc = 1;

ll get(ll x){
	ll res = 0;
	while(x != 1 && x % r == 0){
		x /= r;
		res++;
	}
	if(x != 1) return 0;
	else return res;	 
}

ll find(ll x, int pos){
	ll res = x, cnt = 0;
	for(int i = 2; i <= 1000; i++){
		while(x != 1 && x % i == 0){
			x /= i;
			cnt++;
		}
		if(x != 1){
			cnt = 0;
			x = res;
		}
		else{
			int cntt = 0;
			if(a[pos] > a[pos+1]) cnt = -cnt;
			res = a[pos];
			while(res % i == 0){
				res /= i;
				cntt++;
			}
			f[pos][plc] = cntt;
			f[pos + 1][plc] = cntt + cnt;
			p[cntt][plc] = pos;
			p[cntt + cnt][plc] = pos + 1;
			return i;
		}
	}
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%lld", &a[i]);
	}
	for(int i = 2; i <= n; i++){
		if(max(a[i], a[i-1]) % min(a[i], a[i-1]) != 0){
			plc++;
			len = 1;
			r = 0;
			continue;
		}
		ll s = max(a[i], a[i-1]) / min(a[i], a[i-1]);
		if(r != 0){
			ll jud = get(s);
			if(a[i] < a[i-1]) jud = -jud;
			if(jud == 0){
				len = 2;
				plc++;
				r = find(s, i - 1);
				continue;
			}
			f[i][plc] = f[i - 1][plc] + jud;
			if(p[f[i][plc]][plc] != 0){
				plc++;				
				f[i][plc] = f[i][plc - 1];
				f[p[f[i][plc]][plc]][plc] = f[i][plc-1];
				i = p[f[i][plc-1]][plc-1] + 1;
				p[f[i][plc]][plc] = p[f[i][plc-1]][plc-1];
				len = 1;
			}
			else{
				p[f[i][plc]][plc] = i;
				len++;
				ans = max(ans, len);
			}
		}
		else{
			r = find(s, i - 1);
			len++;
			ans = max(ans, len);
		}
	}
	printf("%lld", ans);
	return 0;
} 
