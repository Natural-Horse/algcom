#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

const int Maxn = 1e6, Maxm = 2e7;

int n, m;
int a[Maxn + 5];
int st[2 * Maxn + 5][100];

void pre_work(){
	for(int i = 1; i <= n; i++){
		st[i][0] = a[i];
	}
	int t = log2(n) + 1;
	for(int j = 1; j < t; j++){
		for(int i = 1; i <= n - (1 << j) + 1; i++){
			st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
		}
	}
}

int query(int l, int r){
	int k = log2(r - l + 1);
	int val = max(st[l][k], st[r - (1 << k) + 1][k]);
	return val;
}

int main(){
	scanf("%d %d", &n, &m); 
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}
	pre_work();
	for(int i = 1; i <= m; i++){
		int l, r;
		scanf("%d %d", &l, &r);
		int ans = query(l, r);
		printf("%d\n", ans);
	}
	return 0;
} 
