#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
#define low(a, b) lower_bound(vec[a].begin(), vec[a].end(), b)
#define upp(a, b) upper_bound(vec[a].begin(), vec[a].end(), b)
using namespace std;

inline int read(){
	int x = 0, f = 1; char ch = getchar();
	while(!isdigit(ch)){if(ch == '-') f = -1; ch = getchar();}
	while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - 48; ch = getchar();}
	return x * f;
}

const int N = 1e5 + 5, M = 1e5 + 5, mod = 1e9;

int main(){
	freopen("9.in", "w", stdout);
	srand(time(0));
	int n = 100000, m = 100000, k = rand() % 10;
	printf("%d %d %d\n", n, m, k);
	for(int i = 1; i <= n; i++){
		int a = rand() % mod + 1;
		printf("%d ", a);
	}
	printf("\n");
	for(int i = 1; i <= m; i++){
		ll l = rand() % n + 1, r = rand() % n + 1;
		printf("%lld %lld\n", l, r);
	}
	return 0;
}

