#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

const int Maxn = 1e4+5;

int n, m, k;
int x[Maxn], y[Maxn];
int low[Maxn], high[Maxn];
int dp[2][Maxn];
int jud, ans = inf, cnt, cntt;
bool check[Maxn];

int main(){
	scanf("%d %d %d", &n, &m, &k);
	for(int i = 0; i < n; i++){
		scanf("%d %d", &x[i], &y[i]);
	}
	for(int i = 1; i <= k; i++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		check[a] = true;
		low[a] = b, high[a] = c;
	}
	memset(dp, inf, sizeof(dp));
	for(int i = 1; i <= m; i++){
		dp[0][i] = 0;
	}
	int k = 0;
	for(int ii = 1; ii <= n; ii++){
		k = (k ^ 1);
		int i = ii - 1;
		bool con = false, add = false;
		for(int j = x[i] + 1; j <= m + x[i]; j++){
			dp[k][j] = min(dp[k][j-x[i]], dp[k^1][j-x[i]]) + 1;
			if(check[ii]){
				if(j <= low[ii] || j >= high[ii]) dp[k][j] = inf;
			}
			if(dp[k][j] != inf){
				con = true;
				if(check[ii]){
					cntt++;
					add = true;
				}
			} 
		}
		for(int j = m - y[i]; j >= 1; --j){
			dp[k][j] = min(dp[k][j], dp[k^1][j+y[i]]);
			if(check[ii]){
				if(j <= low[ii] || j >= high[ii]) dp[k][j] = inf;
			}
			if(dp[k][j] != inf){
				con = true;
				if(check[ii] && !add){
					cntt++;
					add = true;
				}
			} 
		}
		for(int j = m + 1; j <= m + x[i]; j++){
			dp[k][j] = inf;
		}
		if(con == false){
			printf("0\n%d", cntt);
			return 0;
		}
		if(i == n) jud = k;
	}
	for(int i = 1; i <= n; i++){
		ans = min(ans, dp[jud][i]);
	}
	printf("1\n%d", ans);
	return 0;
} 
