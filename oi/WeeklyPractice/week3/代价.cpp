#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

const int Maxn = 1e6 + 5;

int n;
int a[Maxn];
int d[Maxn], minn[Maxn], cnt = 1;
ll ans;

int main(){
	scanf("%d", &n);
	memset(minn, 0x3f, sizeof(minn));
	d[0] = 0;
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		if(a[i] == 1){
			d[cnt] = i;
			cnt++;
		}
		else minn[cnt] = min(minn[cnt], a[i]);
	}
	d[cnt] = n + 1;
	for(int i = 1; i <= cnt; i++){
		if(minn[i] != inf) ans += minn[i];
	} 	
	for(int i = 0; i < cnt; i++){
		for(int j = d[i] + 1; j <= d[i+1] - 2; j++){
			ans += (ll)a[j] * a[j+1];
		}
	}
	ans += cnt - 1;
	printf("%lld", ans);
	return 0;
} 
