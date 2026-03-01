#include<bits/stdc++.h>
#define inf 100000000
#define ll long long
using namespace std;

int n,m;
int a[15][15];
int state[5005],sum[5005],cnt;
int jud[15];
ll ans;
ll dp[15][5005];

void pre_work(){
	for(int i = 1;i <= m;i ++){
		jud[i] = (1 << n) - 1;
	}
	for(int i = 1;i <= m;i ++){
		for(int j = 1;j <= n;j ++){
			if(!a[i][j]) jud[i] -= (1 << (j - 1));
		}
	}
	for(int i = 0;i < (1 << n);i ++){
		if(i & (i << 1)) continue;
		state[++ cnt] = i;
		int s = i;
		while(s){
			sum[cnt] ++;
			s -= (s & -s);
		}
	}
}

void init(){
	for(int i = 1;i <= cnt;i ++){
		if((state[i] & jud[1]) != state[i]) continue;
		dp[1][i] = 1;
	}
}

int main(){
	scanf("%d %d",&m,&n);
	for(int i = 1;i <= m;i ++){
		for(int j = 1;j <= n;j ++){
			scanf("%d",&a[i][j]);
		}
	}
	pre_work();
	init();
	for(int l = 2;l <= m;l ++){
		for(int i = 1;i <= cnt;i ++){
			for(int j = 1;j <= cnt;j ++){
				if((state[i] & jud[l]) != state[i]) continue;
				if(state[i] & state[j]) continue;
				dp[l][i] += dp[l - 1][j];
				dp[l][i] %= inf;
			}
		}
	}
	for(int i = 1;i <= cnt;i ++){
		ans += dp[m][i];
		ans %= inf;
	}
	printf("%lld",ans);
	return 0;
}
