#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

int n,k;
ll dp[10][15005][80];
ll state[100005],king[100005],cnt;
ll ans;

void init(){
	for(int i = 0;i < (1 << n);i ++){
		if(!((i << 1) & i)){
			state[++ cnt] = i;
			int t = i;
			while(t){
				king[cnt] ++;
				t -= (t & -t);
			}
		}
	}
}

int main(){
	scanf("%d %d",&n,&k);
	init();
	for(int i = 1;i <= cnt;i ++){
		if(king[i] <= k){
			dp[1][i][king[i]] = 1;
		}
	}
	for(int i = 2;i <= n;i ++){
		for(int j = 1;j <= cnt;j ++){
			for(int t = 1;t <= cnt;t ++){
				if((state[j] & state[t]) || ((state[j] << 1) & state[t]) || ((state[j] >> 1) & state[t])) continue;
				for(int q = 1;q <= k - king[j];q ++){
					dp[i][j][q + king[j]] +=dp[i - 1][t][q];
				}
			}
		}
	}
	for(int i = 1;i <= n;i ++){
		for(int j = 1;j <= cnt;j ++){
			ans += dp[i][j][k];
		}
	}
	printf("%lld",ans);
	return 0;
}
