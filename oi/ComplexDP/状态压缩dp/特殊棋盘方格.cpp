#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

ll n,m;
ll jud[22];
ll dp[1 << 20];

int main(){
	scanf("%lld %lld",&n,&m);
	for(int i = 1;i <= n;i ++){
		jud[i] = (1 << n) - 1;
	}
	for(int i = 1,x,y;i <= m; i ++){
		scanf("%d %d",&x,&y);
		jud[x] -= (1 << (y - 1));
	}
	dp[0]=1;
	for(int i = 0;i < (1 << n);i ++){
		int cnt=0;
		for(int j = i;j;j -= (j & -j)) cnt ++;
		for(int j = i;j;j -= (j & -j)){
			if(((j & -j) & jud[cnt]) != (j & -j)) continue;
			dp[i] += dp[i & ~(j & -j)];
		}
	}
	ll ans=dp[(1 << n) - 1];
	printf("%lld",ans);
	return 0;
}
