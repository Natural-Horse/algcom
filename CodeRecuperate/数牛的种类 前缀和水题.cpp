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

const int N = 1e5 + 5;

int n, q, pre[N][3];

int main(){
	n = read(), q = read();
	for(int i = 1; i <= n; i++){
		int a = read();
		for(int j = 1; j <= 3; j++){
			if(j == a) pre[i][j] = pre[i-1][j] + 1;
			else pre[i][j] = pre[i-1][j];
		}
	}
	for(int i = 1, l, r; i <= q; i++){
		l = read(), r = read();
		for(int j = 1; j <= 3; j++){
			printf("%d ", pre[r][j]-pre[l-1][j]);
		}
		printf("\n");
	}
	return 0;
}

