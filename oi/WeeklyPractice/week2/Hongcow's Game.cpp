#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

const int Maxn = 1e3 + 5;

int n, tot;
int op[Maxn];
ll ans[Maxn];
bool b[Maxn];

int main(){
	b[1] = b[2] = b[4] = b[8] = b[16] = b[32] = b[64] = b[128] = b[256] = b[512] = b[1024] = true;
	memset(ans, 0x3f, sizeof(ans));
	scanf("%d", &n);
	if(!b[n]) tot = log2(n) + 1;
	else tot = log2(n);
	int jud = 1;	
	for(int i = 1; i <= tot; i++){
		int k = 0;
		for(int j = 0; j < n; j++){
			if(j & jud){
				op[++k] = j + 1;
			}
		}
		printf("%d\n", k);
		fflush(stdout);
		for(int j = 1; j <= k; j++){
			printf("%d ", op[j]);
			fflush(stdout);
		}
		for(int j = 0; j < n; j++){
			ll d;
			scanf("%lld", &d);
			if(!(j & jud)) ans[j+1] = min(ans[j+1], d);
		}
		jud <<= 1;
	}
	jud = 1;
	for(int i = 1; i <= tot; i++){
		int k = 0;
		for(int j = 0; j < n; j++){
			if(!(j & jud)){
				op[++k] = j + 1;
			}
		}
		printf("%d\n", k);
		fflush(stdout);
		for(int j = 1; j <= k; j++){
			printf("%d ", op[j]);
			fflush(stdout);
		}
		for(int j = 0; j < n; j++){
			ll d;
			scanf("%lld", &d);
			if(j & jud) ans[j+1] = min(ans[j+1], d);
		}
		jud <<= 1;
	}
	printf("-1\n");
	fflush(stdout);
	for(int i = 1; i <= n; i++){
		printf("%lld ", ans[i]);
		fflush(stdout);
	}
	return 0;
}
