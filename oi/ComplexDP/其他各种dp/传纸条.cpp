#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
#define db double
using namespace std;

inline int read(){
	int x = 0, f = 1; char ch = getchar();
	while(!isdigit(ch)){if(ch == '-') f = -1; ch = getchar();}
	while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - 48; ch = getchar();}
	return x * f;
}

const int N = 55;

int n, m, a[N][N], f[N<<1][N<<1][N<<1];

int main(){
    n = read(), m = read();
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++) a[i][j] = read();
    }
    if(n == 1){
        int fab = 0; 
        for(int i = 1; i <= m; ++i) fab += a[1][i];
        printf("%d\n", fab);
        return 0;
    }
    if(m == 1){
        int fab = 0;
        for(int i = 1; i <= n; i++) fab += a[i][1];
        printf("%d\n", fab);
        return 0;
    }
    f[2][1][1] = a[1][1]; 
    for(int i = 3; i <= n + m; i++){
        for(int j = 1; j <= n; j++){
            for(int k = 1; k <= n; k++){
                if(j == k) continue;
                int h = i - j, l = i - k;
                if(h > m || l > m) continue;
                if(j>1 && k>1) f[i][j][k] = max(f[i][j][k], f[i-1][j-1][k-1]);
                if(j>1 && l>1 && j-1!=k) f[i][j][k] = max(f[i][j][k], f[i-1][j-1][k]);
                if(k>1 && h>1 && k-1!=j) f[i][j][k] = max(f[i][j][k], f[i-1][j][k-1]);
                if(l>1 && h>1) f[i][j][k] = max(f[i][j][k], f[i-1][j][k]);
                f[i][j][k] += a[j][h] + a[k][l];
            }
        }
    }
    printf("%d\n", max(f[n+m-1][n][n-1], f[n+m-1][n-1][n]) + a[n][m]);
    return 0;
}

