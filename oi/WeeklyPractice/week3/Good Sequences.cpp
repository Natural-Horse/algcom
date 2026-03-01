#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

const int Maxn = 1e5 + 5;

int a[Maxn], n;
int f[Maxn];
int ans;

void fab(int x){
	int jud = x, res = 0;
	int q = sqrt(x);
	for(int i = 2; i <= q; i++){
		if(x % i == 0) res = max(max(res, f[i]), f[x/i]);
	}
	res = max(res, f[x]);
	x = jud;
	res++;
	for(int i = 2; i <= q; i++){
		if(x % i == 0) f[i] = f[x/i] = res;		
		while(x % i == 0){			
			x /= i;
		}
	}
	f[x] = res;
	ans = max(ans, res);
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		int jud = sqrt(a[i]);
	}
	for(int i = 1; i <= n; i++){
		fab(a[i]);
	}
	printf("%d", ans);
	return 0;
}
