// T1 pair
#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

int n;
int a[200005];
int cnt[500005];
int maxn;
int ans;

int main(){
//	freopen("pair.in", "r", stdin); 
//	freopen("pair.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		maxn = max(maxn, a[i]);
		cnt[a[i]]++;
	}
	for(int i = 1; i <= maxn; i++){
		ans += cnt[i] * (cnt[i]-1);
		for(int j = 1; j*j <= i; j++){
			if(i % j == 0 && i != j){
				ans += cnt[i] * cnt[j];
				if(j * j != i && j != 1) ans += cnt[i] * cnt[i/j];
			} 
		}
	}
	printf("%d", ans);
	return 0;
} 
