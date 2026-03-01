#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

const int Maxn = 1e3+5;

int n, m;
char in[Maxn*2][Maxn*2];
int a[Maxn][Maxn];
int l[Maxn][Maxn], r[Maxn][Maxn], up[Maxn][Maxn];
ll ans;
char cc;
int main(){
	scanf("%d %d", &n, &m);
	getchar();
	for(int i = 1; i <= n; i++){		
		for(int j = 1; j <= m; j++){
			cin >>in[i][j];
		}	
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j ++){
			if(in[i][j] == 'R') a[i][j] = 0;
			else a[i][j] = 1;
			l[i][j] = r[i][j] = j;
			up[i][j] = 1;
		}
	}
//	for(int i = 1; i <= n; i++){
//		for(int j = 1; j <= m; j++){
//			printf("%d ", a[i][j]);
//		}
//		printf("\n");
//	}
	for(int i = 1; i <= n; i++){
		for(int j = 2; j <= m; j++){
			if(a[i][j] == a[i][j - 1] && a[i][j] == 1) l[i][j] = l[i][j - 1];
		}
		for(int j = m - 1; j >= 1; --j){
			if(a[i][j] == a[i][j + 1] && a[i][j] == 1) r[i][j] = r[i][j + 1];
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(a[i][j] == 1){
				if(a[i][j] == a[i - 1][j]){
					up[i][j] += up[i - 1][j];
					l[i][j] = max(l[i - 1][j], l[i][j]);
					r[i][j] = min(r[i][j], r[i - 1][j]);			
				}
				ll le = r[i][j] - l[i][j] + 1;
				ll he = up[i][j];
				ans = max(ans, le * he);
			}			
		}
	}
	printf("%lld", ans * (ll)3);
	return 0;
}
