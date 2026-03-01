#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

ll read(){
	ll x = 0,f = 1;char ch = getchar();
	while (ch < '0' || ch > '9'){if (ch == '-') f = -1; ch = getchar();}
	while (ch >= '0' && ch <= '9'){x = x*10 + ch - 48; ch = getchar();}
	return x * f;
}

const int N = 1e3 + 5;

ll a[N << 1][N << 1], b[N << 1][N << 1], m[N][N];
int n, q;

int main(){
	n = read(), q = read();
	for(int i = 1; i <= q; i++){
		ll r, c, l, s;
		r = read(), c = read(), l = read(), s = read();
		a[r+l][c] -= s;
		b[r][c+1] -=s, b[r+l][c+l+1] += s;		
		b[r][c] += s, b[r+l+1][c+l+1] -= s;
	}
	for(int i = n; i >= 1; --i){
		int y = i;
		for(int j = 1; j <= n; j++){
			b[j][y] = b[j-1][y-1] + b[j][y];
			y++;
			if(y > n) break;
		}
	}
	for(int i = 2; i <= n; i++){
		int x = i;
		for(int j = 1; j <= n; j++){
			b[x][j] = b[x-1][j-1] + b[x][j];
			x++;
			if(x > n) break;
		}
	}
	ll res = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			a[i][j] += b[i][j];
			m[i][j] = m[i][j-1] + m[i-1][j] - m[i-1][j-1] + a[i][j];
//			printf("%d ", m[i][j]);
			res ^= m[i][j];
		}
		printf("\n");
	}
	printf("%lld", res);
	return 0;
}

