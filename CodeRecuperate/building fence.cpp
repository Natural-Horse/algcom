#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

inline int read(){
	int x = 0, f = 1; char ch = getchar();
	while(!isdigit(ch)){if(ch == '-') f = -1; ch = getchar();}
	while(isdigit(ch)){x = (x << 1) + (x << 3) + ch - 48; ch = getchar();}
	return x * f;
}

const int N = 2e3 + 505;

int n;
ll f[10][N], pre[10][N];

int main(){
	n = read();
	f[0][0] = 1;
	for(int i = 0; i <= n; i++) pre[0][i] = 1;
	for(int i = 1; i <= 4; i++){
		for(int j = 1; j <= n; j++){
			if(j - ((n-1)>>1) < 0) f[i][j] = pre[i-1][j-1];
			else f[i][j] = pre[i-1][j-1] - pre[i-1][j-((n-1)>>1)-1];
			pre[i][j] = pre[i][j-1] + f[i][j];
		}
	}
	printf("%lld", f[4][n]);
	return 0;
}

