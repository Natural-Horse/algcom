#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

const int Maxn = 1e5 + 5;

struct Tree{
	ll x, h;
}tr[Maxn];

int n;
int dp[Maxn][3];
int ans;

bool cmp(Tree a, Tree b){
	return a.x < b.x;
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%lld %lld", &tr[i].x, &tr[i].h);
	}
	sort(tr + 1, tr + 1 + n, cmp);
	dp[1][1] = dp[1][2] = 1;
	for(int i = 2; i <= n; i++){
		// ²»µ¹
		dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
		if(tr[i - 1].h + tr[i - 1].x < tr[i].x){
			dp[i][0] = max(dp[i][0], dp[i - 1][2]);
		}
		// Ïò×óµ¹
		if(tr[i].h + tr[i - 1].x < tr[i].x){
			dp[i][1] = max(dp[i - 1][0] + 1, dp[i - 1][1] + 1);
		} 
		if(tr[i].h + tr[i - 1].h + tr[i - 1].x < tr[i].x){
			dp[i][1] = max(dp[i][1], dp[i - 1][2] + 1);
		}
		// ÏòÓÒµ¹
		dp[i][2] = max(dp[i - 1][1] + 1, dp[i - 1][0] + 1);
		if(tr[i - 1].x + tr[i - 1].h < tr[i].x){
			dp[i][2] = max(dp[i][2], dp[i - 1][2] + 1);
		} 
	}
	ans = max(dp[n][0], max(dp[n][1], dp[n][2]));
	printf("%d", ans);
	return 0;
}
