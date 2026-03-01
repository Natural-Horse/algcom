#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;

int dp[105][105][105];
int jud[105],state[1005],sum[1005],cnt; 
int n,m;
char a[105][15];
int ans;

void pre_work(){
	for(int i = 1;i <= n;i ++){
		jud[i] = (1 << m) - 1;
	}
	for(int i = 1;i <= n;i ++){
		for(int j = 1;j <= m;j ++){
			if(a[i][j] == 'H') jud[i] -= (1 << (j - 1));
		}
	}
	for(int i = 0;i < (1 << m);i ++){
		if(((i << 1) & i) || ((i << 2) & i)) continue;
		state[++ cnt] = i;
		int s = i;
		while(s){
			sum[cnt] ++;
			s -= (s & -s);
		}
	}	
}

void init(){
	for(int i = 1;i <= 2;i ++){
		for(int j = 1;j <= cnt;j ++){
			for(int k = 1;k <= cnt;k ++){
				if(state[j] & jud[i]) continue;
				if(state[k] & jud[i - 1]) continue;
				dp[i][j][k] = sum[j] + sum[k];
			}
		}
	}
}

int main(){
	scanf("%d %d",&n,&m);
	for(int i = 1;i <= n;i ++){
		scanf("%s",a[i] + 1);
	}
	pre_work();
	init();
	for(int l = 1;l <= n;l ++){		
		for(int i = 1;i <= cnt;i ++){
			for(int j = 1;j <= cnt;j ++){
				int cmp = 0;
				for(int k = 1;k <= cnt;k ++){
					if(state[i] & state[k]) continue;
					if(state[i] & state[j]) continue;
					if(state[j] & state[k]) continue;
					if((state[i] & jud[l]) != state[i]) continue;
					cmp = max(cmp,dp[l - 1][j][k] + sum[i]);
				}
				dp[l][i][j] = cmp;
			}
		}
	}
	for(int i = 1;i <= cnt;i ++){
		for(int j = 1;j <= cnt;j ++){
			ans = max(ans,dp[n][i][j]);
		}
	}
	printf("%d",ans);
	return 0;
}
