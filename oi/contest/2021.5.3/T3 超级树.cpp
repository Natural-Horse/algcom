#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
#define rl register long long
using namespace std;

const int Maxn = 305;

ll n, mod;
ll f[Maxn][Maxn];

int main(){
	scanf("%lld %lld", &n, &mod);
	f[1][0] = f[1][1] = 1;
	for(rl i = 1; i <= n; i++){
		for(rl fab = 0; fab <= n; fab++) f[i-1][fab] %= mod;
		ll jud = n - i + 2;
		for(rl j = 0; j <= jud; j++){
			for(rl k = 0; j + k <= jud; k++){
				rl jud = f[i-1][j] * f[i-1][k] % mod;
				f[i][j+k] += jud;                
				f[i][j+k+1] += jud;            
				f[i][j+k] += (ll)2 * (j + k) * jud;    
				f[i][j+k-1] += (j + k) * (j + k - 1) % mod * jud;  
			}
		}
	}
	printf("%lld", f[n][1] % mod);
	return 0;
} 
