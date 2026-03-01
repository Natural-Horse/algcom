#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long 
using namespace std;

int n, k;
ll dev[20000005], cnt;

int main(){
	scanf("%d %d", &n, &k);
	for(int i = 1; i <= n; i++){
		ll x;
		scanf("%lld", &x);
		for(ll j = 1; j * j <= x; j++){
			if(x % j == 0){
				dev[++cnt] = j;
				dev[++cnt] = x/j;
			}
		}
	}
	sort(dev + 1, dev + 1 + cnt);
	int tot = 1;
	for(int i = cnt; i >= 1; --i){
		if(dev[i] == dev[i+1]) tot++;
		else tot = 1;
		if(tot == k){
			printf("%d", dev[i]);
			return 0;
		}
		
	}
} 
