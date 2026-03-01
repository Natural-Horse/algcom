#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

inline int read(){
	int x = 0, f = 1; char ch = getchar();
	while(!isdigit(ch)){if(ch == '-') f = -1;ch = getchar();}
	while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - 48; ch = getchar();}
	return x * f;
}

const int N = 1e4 + 5;

int n, m, k, f[N], v[N], w[N], fa, val[N];

int main(){
	n = read(), m = read(), k = read();
	for(int i = 1; i <= k; i++) val[i] = read();
	for(int i = 1; i <= n; i++){
		w[i] = read(), fa = read();
		v[i] = val[fa];
	}
	for(int i = 1; i <= n; i++){
		for(int j = m; j; --j){
			for(int k = 1; k <= v[i]; k++){
				if(j - k >= 0) f[j] = max(f[j], f[j-k] + w[i]*k); 
			}
		}
		for(int j = 1; j <= m; j++) printf("%d ", f[j]);
		printf("\n");
	}
	int ans = 0;
	for(int i = 1; i <= m; i++) ans = max(ans, f[i]);
	printf("%d\n", ans);
	return 0;
}

