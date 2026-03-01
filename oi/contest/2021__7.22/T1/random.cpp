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

int T = 10000005;

int main(){
	freopen("sample.in", "w", stdout);
	srand(time(0));
	int n = 5;
	printf("%d\n", n);
	for(int i = 1; i <= n; i++){
		int op = rand() % 3 + 1;
		int l = rand() % 10 + 1, r = rand() % 10 + 1;
		if(l > r) swap(l, r);
		printf("%d %d %d\n", op, l, r);
	}
	return 0;
}

