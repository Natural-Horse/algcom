#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

const int Maxn = 55;

int n, c;
int x[Maxn], w[Maxn], pre[Maxn];
int f[Maxn][Maxn][3];

int main(){
	scanf("%d %d", &n, &c);
	memset(f, inf, sizeof(f));
	for(int i = 1; i <= n; i++){
		scanf("%d %d", &x[i], &w[i]);
		pre[i] = pre[i-1] + w[i];
	} 
	f[c][c][1] = f[c][c][0] = 0;
	for(int k = 2; k <= n; k++){
		for(int l = 1; l <= n - k + 1; l++){
			int r = l + k - 1;
			f[l][r][0] = min(f[l][r][0], f[l+1][r][0] + (x[l+1] - x[l]) * (pre[n] - pre[r] + pre[l]));
			f[l][r][0] = min(f[l][r][0], f[l+1][r][1] + (x[r] - x[l]) * (pre[n] - pre[r] + pre[l]));
			f[l][r][1] = min(f[l][r][1], f[l][r-1][0] + (x[r] - x[l]) * (pre[n] - pre[r-1] + pre[l-1]));
			f[l][r][1] = min(f[l][r][1], f[l][r-1][1] + (x[r] - x[r-1]) * (pre[n] - pre[r-1] + pre[l-1]));
		}
	}
	printf("%d", min(f[1][n][1], f[1][n][0]));
	return 0;
}
