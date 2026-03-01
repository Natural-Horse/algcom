#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

ll a, b;
ll f[15][15];
ll lim[15];

void pre_work(){
	for(int i = 0; i <= 9; i++){
		f[1][i] = 1;
	}
	for(int i = 2; i <= 10; i++){
		for(int j = 0; j <= 9; j++){
			for(int k = 0; k <= 9; k++){
				if(abs(j-k) >= 2) f[i][j] += f[i-1][k];
			}
		}
	}
//	f[1][0] = 0;
}

ll get(ll x){
	ll ans = 0, len = 0;
	memset(lim, 0, sizeof(lim));
	while(x){
		lim[++len] = x % 10;
		x /= 10;
	}
	for(int i = 1; i < len; i++){
		for(int j = 1; j <= 9; j++) ans += f[i][j];
	}
	for(int i = 1; i < lim[len]; i++) ans += f[len][i];
	for(int i = len-1; i >= 1; --i){
		for(int j = 0; j < lim[i]; j++){
			if(abs(j-lim[i+1]) >= 2) ans += f[i][j];
		}
		if(abs(lim[i]-lim[i+1]) < 2) break;
	}
	
	return ans;
}

int main(){
	scanf("%lld %lld", &a, &b);
	pre_work();
	ll ansa = get(a), ansb = get(b+1);
	printf("%lld", ansb - ansa);
	return 0;
}
