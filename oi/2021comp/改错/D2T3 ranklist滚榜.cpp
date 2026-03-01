#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

const int Maxn = 15;

int n, m, fir, plc;
int a[Maxn];
bool b[Maxn];
ll ans;

bool dfs(int cnt, int tot, int maxn, int top){
	if(cnt == n){
		if(tot == 0){
			ans++;
			return true;
		} 
		return false;
	}
	if(tot < 0) return false;
	for(int i = 1; i <= n; i++){
		if(b[i]) continue;
		b[i] = true;
		for(int j = max(maxn, top - a[i]); j <= tot / (n - cnt); j++){
			if(dfs(cnt + 1, tot - j, j, a[i] + j)){
				break;
			}
		}		
		b[i] = false;
	}
}

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		if(a[i] > fir){
			fir = a[i];
			plc = i;
		}
	}
	bool fab = dfs(0, m, 0, fir);
	printf("%lld", ans);
	return 0;
} 
