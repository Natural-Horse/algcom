#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

inline int read(){
	int x = 0, f = 1; char ch = getchar();
	while(!isdigit(ch)){if(ch == '-') f = -1;ch = getchar();}
	while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - 48; ch = getchar();}
	return x * f;
}

const int N = 1e2 + 5;

int n1, n2, n3, f[N][N][N];
char s1[N], s2[N], s3[N];
string ans[N][N][N];

int main(){
	scanf("%s %s %s", s1+1, s2+1, s3+1);
	n1 = strlen(s1+1), n2 = strlen(s2+1), n3 = strlen(s3+1);
	for(int i = 1; i <= n1; i++){
		for(int j = 1; j <= n2; j++){
			for(int k = 1; k <= n3; k++){
				if(s1[i] == s2[j] && s2[j] == s3[k]){
					if(f[i][j][k] < f[i-1][j-1][k-1] + 1){
						f[i][j][k] = f[i-1][j-1][k-1] + 1;
						ans[i][j][k] = ans[i-1][j-1][k-1] + s1[i];
					}
				}
				else{
					if(f[i][j][k] < f[i-1][j][k]){
					 	f[i][j][k] = f[i-1][j][k];
					 	ans[i][j][k] = ans[i-1][j][k];
					}
					if(f[i][j][k] < f[i][j-1][k]){
					 	f[i][j][k] = f[i][j-1][k];
					 	ans[i][j][k] = ans[i][j-1][k];
					}
					if(f[i][j][k] < f[i][j][k-1]){
					 	f[i][j][k] = f[i][j][k-1];
					 	ans[i][j][k] = ans[i][j][k-1];
					}
				}
			}
		}
	}
	cout << ans[n1][n2][n3];
	return 0;
}

