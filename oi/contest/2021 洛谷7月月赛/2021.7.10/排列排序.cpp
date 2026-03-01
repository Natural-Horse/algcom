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

const int N = 1e6 + 5;
int n, T;
int a[N], plc[N];

int main(){
	T = read();
	for(int ii = 1; ii <= T; ii++){
		n = read();
		for(int i = 1; i <= n; i++) a[i] = read(), plc[i] = a[i];
		int l = 1, r = 1, ans = 0;
		for(int i = 1; i <= n; i++){
			l = r = i;
			int j;
			for(j = l; j <= r; j++){
				if(plc[j] > r) r = plc[j];
			}
			ans += (r - l + 1) * (r != l);
			i = j - 1;
		}
		printf("%d\n", ans);
	}
}

