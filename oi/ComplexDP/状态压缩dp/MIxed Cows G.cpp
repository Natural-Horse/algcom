#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

int n,lim;
int num[20];
ll dp[1 << 16][20];
ll ans;

int main(){
	scanf("%d %d",&n,&lim);
	for(int i = 1;i <= n;i ++){
		scanf("%d",&num[i]);
	}
	int jud=0;
	for(ll i = 1;i < (1 << n);i = (i << 1)){
		dp[i][++ jud] = 1;
	}
	for(ll i = 1;i < (1 << n);i ++){          // i 本次情况 
		for(ll j = i;j;j -= (j & -j)){        // j 找本次情况的1 
			ll t = (i & ~(j & -j));           // t 上次情况（本次情况除去一个1） 
			int posa = log2(j & -j) + 1;      //posa 本次情况队头 
			for(ll k = t;k;k -= (k & -k)){    // k 找上次情况的1 
				int posb = log2(k & -k) + 1;  // posb 上次情况队头 
				if(abs(num[posa]-num[posb]) <= lim) continue;
				dp[i][posa] += dp[t][posb];
			}
		}
	}
	for(int i = 1;i <= n;i ++){
		ans += dp[(1 << n) - 1][i];
	}
	printf("%lld",ans);
	return 0;
}
