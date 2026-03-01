#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

int k,n;
int w[20], c[100005];
ll pre[100005];
int dp[1 << 16][20];
int ans = -1;

inline int bi_search(int posa, ll val){
	int l = 1, r = n;
	while(l < r){
		int mid = ((l + r + 1) >> 1);
		if(pre[mid]-pre[posa] > val) r = mid - 1;
		else l = mid;
	}
	return r;
}

inline int get_ans(ll state){
	int sum = 0;
	if(!(state & 1)) sum += w[1];
	for(int i = 2; i <= k; i++){
		state = (state >> 1);
		if(!(state & 1)) sum += w[i];
	}
	return sum;
}

int main(){
	scanf("%d %d", &k, &n);
	for(int i = 1; i <= k; i++){
		scanf("%d", &w[i]);
	}
	for(int i = 1; i <= n; i++){
		scanf("%d", &c[i]);
		pre[1] = c[1];
		pre[i] = pre[i - 1] + c[i];
	}
	for(int i = 1; i <= k; i++){
		dp[1<<(i-1)][i] += bi_search(0, w[i]);
		if(dp[1<<(i-1)][i] == n) ans = max(ans, get_ans(1<<(i-1)));
	}
	for(int i = 1; i < (1 << k); i++){                // i 本次情况 
		for(int j = i; j; j -= (j & -j)){             // j 本次情况的1
			int posa = log2(j & -j) + 1;              // posa本次情况队头 
			int t = i & ~(j & -j);                    // t 上次情况
			for(int p = t; p; p -= (p & -p)){         // k 上次情况的1 
				int posb = log2(p & -p) + 1;          // posb上次情况队头 
				dp[i][posa] = max(dp[i][posa], bi_search(dp[t][posb], w[posa]));
				if(dp[i][posa] == n) ans = max(ans, get_ans(i));								 
			}
		}
	}
	printf("%d",ans);
	return 0;
}
