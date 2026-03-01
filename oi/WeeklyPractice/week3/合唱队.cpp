#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

const int Maxn = 1e3 + 5;
const int wcr = 19650827;

int n;
int a[Maxn];
ll f[Maxn][Maxn][3];

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for(int i = 1; i <= n; i++) f[i][i][0] = 1;
	for(int k = 2; k <= n; k++){
		for(int l = 1; l <= n - k + 1; l++){
			int r = l + k - 1;
			if(a[l] < a[r]) f[l][r][0] = (f[l][r][0] + f[l+1][r][1]) % wcr;
			if(a[l] < a[l+1]) f[l][r][0] = (f[l][r][0] + f[l+1][r][0]) % wcr;
			if(a[r] > a[r-1]) f[l][r][1] = (f[l][r][1] + f[l][r-1][1]) % wcr;
			if(a[r] > a[l]) f[l][r][1] = (f[l][r][1] + f[l][r-1][0]) % wcr;
		}
	}
	ll ans = (f[1][n][0] + f[1][n][1]) % wcr;
	printf("%lld", ans);
	return 0;
}
