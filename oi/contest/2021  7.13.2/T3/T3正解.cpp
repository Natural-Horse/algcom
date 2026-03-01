#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
#define mod 998244353
using namespace std;

ll read(){
	ll x = 0,f = 1;char ch = getchar();
	while (ch < '0' || ch > '9'){if (ch == '-') f = -1; ch = getchar();}
	while (ch >= '0' && ch <= '9'){x = x*10 + ch - 48; ch = getchar();}
	return x * f;
}

const int N = 3e3 + 5;
char a[N];
ll f[N][N], l, n; 

int main(){
	scanf("%s", a + 1);
	n = strlen(a + 1);
	l = read();
	for(int i = 0; i <= n; i++) f[i][0] = 1;
	for(ll i = 1; i <= n; i++){
		ll plc = 0;
		for(ll j = i - 1; j >= 1; --j)
			if(a[j] == a[i]){plc = j; break;}
		for(ll j = 1; j <= min(i, l); j++)
			if(!plc) f[i][j] = ((f[i-1][j] + f[i-1][j-1]) % mod + mod) % mod;
			else f[i][j] = (((f[i-1][j] + f[i-1][j-1]) % mod - f[plc-1][j-1]) % mod +mod);
	}
	printf("%lld", (f[n][l] + mod) % mod);
	return 0;
}
