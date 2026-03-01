#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
#define db double
using namespace std;

inline int read(){
	int x = 0, f = 1; char ch = getchar();
	while(!isdigit(ch)){if(ch == '-') f = -1; ch = getchar();}
	while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - 48; ch = getchar();}
	return x * f;
}

const int N = 2e3 + 5, mod = 998244353;

ll n, inv[N<<1], f[N][N<<1]; 

int main(){
    freopen("eat.in", "r", stdin);
    freopen("eat.out", "w", stdout);
    n = read();
    inv[1] = 1;
    for(int i = 2; i <= n<<1; i++) inv[i] = mod - mod/i*inv[mod%i]%mod;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i+((n-i)<<1); j++){
            f[i][j] = (i*inv[j]%mod*f[i-1][j+1]%mod + (j-i)*inv[j]%mod*f[i][j-1]%mod + 1) % mod;
        }
    }
    printf("%lld\n", f[n][n]);
    return 0;
}

