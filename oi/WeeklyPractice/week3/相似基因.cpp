#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

const int Maxn = 105;

int n, m;
char a[Maxn], b[Maxn];
int f[Maxn][Maxn];
int p[205][205];

int main(){
	scanf("%d", &n);
	scanf("%s", a + 1);
	scanf("%d", &m);
	scanf("%s", b + 1);
	memset(f, -inf, sizeof(f));
	p['A']['A'] = p['C']['C'] = p['G']['G'] = p['T']['T'] = 5;
	p['A']['C'] = p['C']['A'] = p['A']['T'] = p['T']['A'] = p['T'][0] = p[0]['T'] = -1;
	p['A']['G'] = p['G']['A'] = p['C']['T'] = p['T']['C'] = p['G']['T'] = p['T']['G'] = p['G'][0] = p[0]['G'] = -2;
	p['C']['G'] = p['G']['C'] = p['A'][0] = p[0]['A'] = -3;
	p['C'][0] = p[0]['C'] = -4;
	f[0][0] = 0;
	for(int i = 1; i <= n; i++){
		f[i][0] = f[i-1][0] + p[a[i]][0];
	}
	for(int j = 1; j <= m; j++){
		f[0][j] = f[0][j-1] + p[0][b[j]];
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			f[i][j] = max(max(f[i][j], f[i-1][j-1] + p[a[i]][b[j]]), max(f[i-1][j] + p[a[i]][0], f[i][j-1] + p[0][b[j]]));
		}
	}
	printf("%d", f[n][m]);
	return 0;
} 
