#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

int read(){
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9'){if(ch == '-') f = -1; ch = getchar();}
	while (ch >= '0' && ch <= '9'){x = x*10 + ch - 48; ch = getchar();}
	return x * f;
}

const int N = 5005;

struct Edge{
	int nxt, to;
}ed[N << 1];

int n, f[N][N], b[N], c[N];

void prework(){
	b[1] = 1, b[2] = 1;
	for(int i = 3; i <= n; i++){
		b[i] = b[i-1] + b[i-2];
		c[i] = c[i-1] + i;
	}
}

int main(){
	n = read();
	prework();
	f[3][2] = 1;
	for(int i = 4; i <= n; i++){
		for(int j = 1; j <= i-2; j++){
			for(int k = 1; k <= (n<<1); k++){
				f[i][k] += f[j][k];
			}
		}
		for(int j = i-2; j; --j){
			for(int k = j-1; k; --k){
				for(int l = 1; l <= j-2; l++){
					for(int m = 1; m <= k-2; m++){
						f[i][l+1+m+1+3] += b[l] * b[m];
					}
				}
			}
		}
		for(int j = 1; j <= i-2; j++){
			for(int k = j+1; k <= i-2; k++){
				f[i][(k-j)*2+1]++;
			}
		}
	}
	for(int i = 1; i <= (n << 1); i++){
		printf("%d ", f[n][i]);
	}
	return 0;
}

