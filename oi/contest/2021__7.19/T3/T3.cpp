#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

int read(){
	int x = 0,f = 1;char ch = getchar();
	while (ch < '0' || ch > '9'){if (ch == '-') f = -1; ch = getchar();}
	while (ch >= '0' && ch <= '9'){x = x*10 + ch - 48; ch = getchar();}
	return x * f;
}

const int N = 1e5 + 5;
int n, q, len;
ll x[N];

int main(){
	n = read(), q = read();
	for(int i = 1; i <= n; i++) x[i] = read();
	for(int i = 1; i <= q; i++){
		len = read();
		ll l = 0, r = len, ans = 0;
		for(int j = 1; j <= n; j++){
			while(x[j] > r && j <= n){
				int dis = x[j] - r;
				l += dis, r += dis, ans += dis;
				j++;
			}
			while(x[j] < l && j <= n){
				int dis = l - x[j];
				l -= dis, r -= dis, ans += dis;
				j++;
			}
			while(l <= x[j] && r >= x[j] && j <= n){
				j++;
			}
			j--;
		}
		printf("%lld\n", ans);
	}
	return 0;
}

