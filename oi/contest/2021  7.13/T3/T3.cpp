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
const int N = 1e7 +5;
int n, m;
int d[N];

int main(){
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= sqrt(i); j++){
			if(i % j == 0){
				d[i]++;
				if(i / j != j) d[i]++;
			} 
		}
	}
	int ans = 0; 
	n = read(), m = read();
	for(int i = 1; i <= n; i++){
		int res = 0;
		for(int j = 1; j <= m; j++){
			res += d[i*j];
		}
		if(res % 2 == 0) ans += 1;
		else ans -= 1;
	}
	printf("%d", ans);
}

