#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int Maxn = 105;

int n, cnt;
ll s[Maxn];
ll inf;
ll ask;

bool cmp(ll a, ll b){
	return a > b;
}

void init(){
	s[1] = 1;
	s[2] = 2;
	for(int i = 3; ; i++){
		s[i] = s[i-1] + s[i-2];
		if(s[i] >= inf){
			cnt = i;
			break;
		} 
	}
}

ll d[Maxn], pt;
ll f[Maxn][3];

ll bi_ser(ll x){
	int l = 0, r = cnt;
	while(l < r){
		int mid = (l + r) >> 1;
		if(s[mid] > x) r = mid - 1;
		else r = mid;
	}
	return l;
} 

void div(ll x){
	for(int i = cnt; i >= 1; --i){
		if(s[i] <= x){
			d[++pt] = i;
			x -= s[i];
		}
		if(x == 0) break;
	}
	d[++pt] = 0;
}

int main(){
	inf = 1e18 + 5;
	init();
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		pt = 0;
		scanf("%lld", &ask);
		div(ask);
		memset(f, 0, sizeof(f));
		f[pt][0] = 1;
		for(int i = pt - 1; i >= 1; --i){
			int len = d[i] - d[i+1];
			f[i][0] += f[i+1][0] + f[i+1][1];
			f[i][1] +=(len-1)/2 * f[i+1][0] + len/2 * f[i+1][1];
		}
		printf("%lld\n", f[1][0] + f[1][1]);
	}
	return 0;
} 
