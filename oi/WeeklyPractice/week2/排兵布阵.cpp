#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

const int Maxn = 2e4 + 5; 

int s, n, m;
ll f[Maxn];
int a[105][105];  // 
int v[105][105], w[105][105];  // 第i个城堡的第j个价格

int main(){
	scanf("%d %d %d", &s, &n, &m);
	for(int i = 1; i <= s; i++){
		for(int j = 1; j <= n; j++){
			scanf("%d", &a[j][i]);
		}
	}
	for(int i = 1; i <= n; i++){
		sort(a[i] + 1, a[i] + 1 + s);
//		a[i][s+1] = 0;
		a[i][0] = -1;
		int jud = 0;
		for(int j = 1; j <= s+1; j++){
							
			v[i][jud] = 2 * a[i][j-1] + 1;
			w[i][jud] = (j - 1) * i;
			jud++;
			
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = m; j >= 0; --j){
			for(int k = 1; k <= s; k++){
				if(j-v[i][k] >= 0) f[j] = max(f[j], f[j-v[i][k]] + w[i][k]);
			}
		}
	}
	printf("%d", f[m]);
	return 0;
} 
