#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

const int Maxn = 2e5+5;

int n;
int a[Maxn];
int ans;

int main(){
//	freopen("mod.in", "r", stdin);
//	freopen("mod.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}
	for(int i = 1; i < n; i++){
		for(int j = i+1; j <= n; j++){
			for(int k = 1; k <= n; k++){
				if(k != i && k != j) ans = max(ans, (a[i]+a[j])%a[k]);
			}
		}
	}
	printf("%d", ans);
	return 0;
} 
