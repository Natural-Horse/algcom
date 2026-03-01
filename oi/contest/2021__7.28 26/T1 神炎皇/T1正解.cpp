#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll unsigned long long
using namespace std;

ll read(){
	ll x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9'){if(ch == '-') f = -1; ch = getchar();}
	while (ch >= '0' && ch <= '9'){x = x*10 + ch - 48; ch = getchar();}
	return x * f;
}

const int N = 1e7 + 5;

ll n, fi[N], p[N], cnt, ans;
bool b[N], pm[N];

void Prime(){
	for(int i = 2; i <= sqrt(n); i++){
		if(!b[i]) p[++cnt] = i, pm[i] = true, fi[i] = i-1;
		for(int j = 1; j <= cnt && i * p[j] <= sqrt(n); j++){
			b[i*p[j]] = true; fi[i*p[j]] = (p[j]-1) * fi[i];
			if(i % p[j] == 0){
				fi[i*p[j]] = fi[i] * p[j];
				break;
			} 
		}
	}
} 

int main(){
	n = read();
	Prime();
	for(ll i = 2; i <= sqrt(n); i++){
		ll k = n / (i*i);
		ans += fi[i] * k;
	}
	printf("%llu\n", ans);
	return 0;
}

