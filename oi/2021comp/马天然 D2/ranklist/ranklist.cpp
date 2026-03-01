#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

int n, m;
int a[15];
int ans, maxn;

void dfs(int pos, int sum){
	if(sum > m){
		if(pos < n) return;
		if(pos >= n){
			ans++;
			return;
		} 
	}
	for(int i = maxn + 1 - a[pos]; i <= m; i++){
		dfs(pos + 1, sum + i);
	}
}

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		maxn = max(maxn, a[i]);
	}
	dfs(1, 0);
	printf("%d", ans);
	return 0;
}
