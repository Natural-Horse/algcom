#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

const int Maxn = 1e4+5;

int n, m, k;
int x[Maxn], y[Maxn];
int low[Maxn], high[Maxn];
int dp[2][Maxn];
int jud, ans = inf, cnt;
bool check[Maxn];

int main(){
	scanf("%d %d %d", &n, &m, &k);
	for(int i = 0; i < n; i++){
		scanf("%d %d", &x[i], &y[i]);
		high[i + 1] = m + 1;
		low[i + 1] = 0;
	}
	for(int i = 1; i <= k; i++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		low[a] = b, high[a] = c;
		check[a] = true;
	}
	memset(dp, 0x3f, sizeof(dp));
	for(int i = 1; i <= m; i++){
		dp[0][i] = 0;
	}
	int k = 0;
	for(int i = 1; i <= n; i++){
		k = (k ^ 1);
		jud = k;
		int p = i - 1;
		bool con = false;
		bool once = false;
		for(int j = x[p] + 1; j <= m + x[p]; j++){
			dp[k][j] = min(dp[k][j - x[p]], dp[k ^ 1][j - x[p]]) + 1;
//			if(dp[k][j] != inf && j > low[i] && j < high[i] && !con){
//				con = true;
//				cnt++;
//			} 
		}
		for(int j = m; j >= 1; --j){
			dp[k][j] = min(dp[k][j], dp[k ^ 1][j + y[p]]);
//			if(dp[k][j] != inf && j > low[i] && j < high[i] && !con){
//				con = true;
//			} 
		}
		for(int j = m + 1; j <= m + x[p]; j++){
			if(dp[k][j] != inf) dp[k][m] = min(dp[k][m], dp[k][j]);
			dp[k][j] = inf;
		}
		for(int j = high[i]; j <= m + 1; j++){
			dp[k][j] = inf;
		}
		for(int j = low[i]; j >= 0; --j){
			dp[k][j] = inf;
		}		
		for(int j = 1; j <= m + x[i]; j++){
			if(dp[k][j] != inf){
				con = true;
				if(check[i] && !once){
					cnt++;
					once = true;
				} 
			}
			dp[k^1][j] = inf;
		}
		if(con == false){
			printf("0\n%d", cnt);
			return 0;
		}
//		printf("%d: ", k);
//		for(int j = 1; j <= m; j++){
//			printf("%d ", dp[k][j]);
//		}
//		printf("\n");
	}
	for(int i = 1; i <= m; i++){
		ans = min(ans, dp[jud][i]);
	}
	printf("1\n%d", ans);
	return 0;
} 
