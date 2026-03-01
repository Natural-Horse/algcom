#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

const int Maxn = 1e6 + 5;

int n, k;
int a[Maxn];
ll pre[Maxn];
int cnt, ans[Maxn];

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		pre[i] = pre[i-1] + (ll)a[i];
	} 
	scanf("%d", &k);
	int pta = 1, ptb = 1;
	ll flag = pta;
	while(ptb <= n && pta <= n && pre[pta] <= k){
		while(pre[pta] > pre[ptb] - pre[pta] && ptb <= n){
			ptb++;
		}
		if(ptb > n){
			for(int j = pre[pta]; j <= k; j++){
				ans[++cnt] = j;
			}
		}
		else{
			for(int j = max(flag, pre[pta]); j < pre[ptb] - pre[pta]; j++){
				 if(j <= k){
				 	ans[++cnt] = j;
				 	flag = j + 1;
				 } 
			}
		}
		pta++;
	}
	printf("%d\n", cnt);
	for(int i = 1; i <= cnt; i++){
		printf("%d ", ans[i]);
	}
	return 0;
}
