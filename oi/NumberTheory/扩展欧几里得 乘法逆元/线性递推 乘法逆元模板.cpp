#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long 
using namespace std;

ll n, p;
ll inv[3000005];

int main(){
	scanf("%lld %lld", &n, &p);
	inv[1] = 1;
	printf("1\n");
	for(int i = 2; i <= n; i++){
		inv[i] = (-((p/i) * inv[p%i]) % p + p )% p; 
		printf("%lld\n", inv[i]);
	}
	return 0;
} 
