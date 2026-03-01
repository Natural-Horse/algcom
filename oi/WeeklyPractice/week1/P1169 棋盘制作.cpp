#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

const int Maxn = 2e3 + 5;

int a[Maxn][Maxn], l[Maxn][Maxn], r[Maxn][Maxn], up[Maxn][Maxn];
int n, m;
int ansa, ansb;

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++){
			scanf("%d", &a[i][j]);
			l[i][j] = r[i][j] = j;
			up[i][j] = 1;
		}
	for(int i = 1; i <= n; i++){
		for(int j = 2; j <= m; j++){
			if(a[i][j] != a[i][j - 1]) l[i][j] = l[i][j - 1];			
		}			
	}
	for(int i = 1; i <= n; i++){
		for(int j = m-1; j >= 1; --j){
			if(a[i][j] != a[i][j + 1]) r[i][j] = r[i][j + 1];
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1;j <= m; j++){			
			if(i > 1 && a[i][j] != a[i-1][j]){			
				l[i][j] = max(l[i][j], l[i - 1][j]);
				r[i][j] = min(r[i][j], r[i - 1][j]);
				up[i][j] = up[i - 1][j]+1;
			}
			int le = r[i][j] - l[i][j] + 1;
			int he = min(le, up[i][j]);
			ansa = max(ansa, he * he);
			ansb = max(ansb, le * up[i][j]);
		}
	}		
	printf("%d\n%d",ansa,ansb);
	return 0;
}
