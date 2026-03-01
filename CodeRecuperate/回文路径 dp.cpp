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

const int N = 5e2 + 5, mod = 1e9 + 7;

ll f[N][N], p[N][N], ans, n;
char a[N][N];

int main(){
	n = read();
	for(int i = 1; i <= n; i++) scanf("%s", a[i] + 1);
	f[1][1] = 1;
	for(int i = 3; i <= n+1; i++){
		for(int j = 1; j <= i-1; j++){
			for(int k = 1; k <= i-1; k++){
				bool chk = false;
				if(a[j][i-j] == a[n-(k-1)][n-(i-k-1)]){
					char s1 = a[j-1][i-j], s2 = a[j][i-j-1];
					char s3 = a[n-(k-1)+1][n-(i-k-1)], s4 = a[n-(k-1)][n-(i-k-1)+1];
					if(j-1 && k-1 && s1 == s3) p[j][k] = (p[j][k] + f[j-1][k-1]) % mod, chk = true;
					if(k-1 && s2 == s3) p[j][k] = (p[j][k] + f[j][k-1]) % mod, chk = true;
					if(j-1 && s1 == s4) p[j][k] = (p[j][k] + f[j-1][k]) % mod, chk = true;
					if(s2 == s4) p[j][k] = (p[j][k] + f[j][k]) % mod, chk = true;		
				}			
			}
		}
		for(int j = 1; j <= i-1;j++){
			for(int k = 1; k <= i-1; k++){
				f[j][k] = p[j][k], p[j][k] = 0;
				if(i == n+1 && j+k == n+1) ans = (ans + f[j][k]) % mod;
			} 
		}		
	}
	printf("%lld\n", ans);
	return 0;
	
	double ans = 0;
	for(int i = 1; i <= 100; i++){
		if(i & 1) ans += (1/i);
		else ans -= (1/i);
	}
	
}

