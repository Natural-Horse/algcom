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

const int N = 15;

ll n, a[N][N], f[N][N][N][N], ans;

int main(){
    n = read();
    int x = read(), y = read(), val = read();
    while(x && y && val){a[x][y] = val; x = read(), y = read(), val = read();}
//    for(int i = 1; i <= n; i++){
//        for(int j = 1; j <= n; j++) printf("%d ", a[i][j]);
//        printf("\n");
//    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            for(int k = 1; k <= n; k++){
                for(int l = 1; l <= n; l++){
                    f[i][j][k][l] = max(f[i][j][k][l], f[i-1][j][k-1][l] + a[i][j] + a[k][l]);
                    f[i][j][k][l] = max(f[i][j][k][l], f[i-1][j][k][l-1] + a[i][j] + a[k][l]);
                    f[i][j][k][l] = max(f[i][j][k][l], f[i][j-1][k-1][l] + a[i][j] + a[k][l]);
                    f[i][j][k][l] = max(f[i][j][k][l], f[i][j-1][k][l-1] + a[i][j] + a[k][l]);
//                    if(f[i][j][k][l] > 67) printf("%d %d %d %d val:%lld\n", i, j, k, l, f[i][j][k][l]);
//                    if(i == 6 && j == 3 && k == 6 && l == 4){
//                        printf("%lld %lld %lld %lld\n", f[i-1][j][k-1][l], f[i-1][j][k][l-1], f[i][j-1][k-1][l], f[i][j-1][k][l-1]);
//                    }
                    if(i == k && j == l) f[i][j][k][l] -= a[i][j];
                }
            }
        }
    }
    printf("%lld\n", f[n][n][n][n]);
    return 0;
}

