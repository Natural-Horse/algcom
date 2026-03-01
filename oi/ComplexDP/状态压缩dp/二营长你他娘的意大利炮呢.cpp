#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

int n,m; 
char a[105][15];
ll state[1505],sum[1505],cnt;
ll jud[105],dp[105][1505][355];
ll ans;

void pre_work(){
	for(int i = 1;i <= n;i ++){
		jud[i] = (1 << m) - 1;
	}
	for(int i = 1;i <= n;i ++){
		for(int j = 1;j <= m;j ++){
			if(a[i][j] == 'H') jud[i] -= (1 << (j - 1));
		}
	}
	for(ll i = 0;i < (1 << m);i ++){
		if(((i << 1) & i) || ((i << 2) & i)) continue;
		state[++ cnt] = i;
		ll s = i;
		while(s){
			sum[cnt] ++;
			s -= (s & -s);
		}
	}	
}

void init(){
	for(int i = 1;i <= n;i ++){
		for(int j = 1;j <= cnt;j ++){
			if((state[j] & jud[i]) != state[j]) continue;
			dp[i][j] = sum[j];
		}
	}
	for(int i = 1;i <= cnt;i ++){
		ll cmp = 0;
		for(int j = 1;j <= cnt;j ++){
			if(state[i] & state[j]) continue;
			if((state[i] & jud[2]) != state[i]) continue;
			if((state[j] & jud[1]) != state[j]) continue;
			cmp = max(cmp,sum[j]);
		}
		dp[2][i] += cmp;
	}
}

int main(){
	scanf("%d %d",&n,&m);
	for(int i = 1;i <= n;i ++){
		scanf("\n");
		for(int j = 1;j <= m;j ++){
			char c;
			scanf("%c",&c);
			a[i][j] = c;
		}
	}
	pre_work();
	init();
	for(int l = 3;l <= n;l ++){
		for(int i = 1;i <= cnt;i ++){
			ll cmp = 0;
			for(int j = 1;j <= cnt; j++){
				for(int k = 1;k <= cnt;k ++){
					if(state[i] & state[k]) continue;
					if(state[i] & state[j]) continue;
					if(state[j] & state[k]) continue;
					if((state[i] & jud[l]) != state[i]) continue;
					if((state[j] & jud[l - 1]) != state[j]) continue;
					cmp = max(cmp,sum[j] + dp[l - 2][k]);
				}
			}
			dp[l][i] += cmp;
		}
	}
	for(int i = cnt;i >= 1;i --){
		ans = max(ans,dp[n][i]);
	}
	printf("%lld",ans);
	return 0;
}
