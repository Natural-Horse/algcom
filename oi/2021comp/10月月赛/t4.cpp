#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

ll read(){
	ll x = 0,f = 1;char ch = getchar();
	while (ch < '0' || ch > '9'){if (ch == '-') f = -1; ch = getchar();}
	while (ch >= '0' && ch <= '9'){x = x*10 + ch - 48; ch = getchar();}
	return x * f;
}

const int N = 5e3 + 5, mod = 1e9 + 7;

char a[N];
int pre[N], tmp[26];
ll f[N][N], n, ans; 

int main(){
	scanf("%s", a + 1);
	n = strlen(a + 1);
	for(int i = 0; i <= n; i++){
	    f[i][0] = 1;
	    pre[i] = tmp[a[i]-'a'], tmp[a[i]-'a'] = i;
    } 
	for(ll i = 1; i <= n; i++){
		for(ll j = 1; j <= i; j++)
			if(!pre[i]) f[i][j] = ((f[i-1][j] + f[i-1][j-1]) % mod + mod) % mod;
			else f[i][j] = (((f[i-1][j] + f[i-1][j-1]) % mod - f[pre[i]-1][j-1]) % mod +mod) % mod;
	}
	for(int i = 1; i <= n; i++){
	    ans = (ans + f[n][i] * ((1<<(n-i))%mod)%mod) % mod;
    }
	printf("%lld", ans % mod);
	return 0;
}
