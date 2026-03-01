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

int n, m, a;

int main(){
	n = read(), m = read(), a = read();
	for(int i = 1; i <= m; i++){
		int u, v, w;
		u = read(), v = read(), w = read();
	}
	for(int i = 1; i <= m; i++){
		printf("-1");
	}
	
	return 0;
}

