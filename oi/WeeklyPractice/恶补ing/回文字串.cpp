#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

const int Maxn = 1005;

char a[Maxn], b[Maxn];
int f[Maxn][Maxn]; 

int main(){
	scanf("%s", a + 1);
	int n = strlen(a + 1);
	for(int i = n; i >= 1; --i) b[n-i+1] = a[i];
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(a[i] == b[j]) f[i][j] = f[i-1][j-1] + 1;
			else f[i][j] = max(f[i-1][j], f[i][j-1]);
		}
	}
	int ans = n - f[n][n];
	printf("%d", ans);
	return 0;
}
