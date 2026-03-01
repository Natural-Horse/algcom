#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

const int Maxn = 5e4;

int n, m;
int a[Maxn + 5];
int fx[Maxn + 5][50];
int fn[Maxn + 5][50];
int ans;

void pre_work(){
	for(int i = 1; i <= n; i++){
		fx[i][0] = fn[i][0] = a[i];
	}
	int t = log2(n);
	for(int j = 1; j <= t; j++){
		for(int i = 1; i <= n - (1 << j) + 1; i++){
			fx[i][j] = max(fx[i][j - 1], fx[i + (1 << (j-1))][j - 1]);
			fn[i][j] = min(fn[i][j - 1], fn[i + (1 << (j-1))][j - 1]);
		}
	}
}

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n ; i++){
		scanf("%d", &a[i]);
	}
	pre_work();
	for(int i = 1, st, re; i<= m; i++){
		scanf("%d %d", &st, &re);
		int k = log2(re - st + 1);
		ans = max(fx[st][k], fx[re - (1 << k) + 1][k]) - min(fn[st][k], fn[re - (1 << k) + 1][k]);
		printf("%d\n", ans);
	}
	return 0;
}
