#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

inline int read(){
	int x = 0, f = 1; char ch = getchar();
	while(!isdigit(ch)){if(ch == '-') f = -1; ch = getchar();}
	while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - 48; ch = getchar();}
	return x * f;
}

const int N = 105, M = 25;

    int f[N][N][M], ans, n, m, cost[N][M], target, houses[N];

    int main(){
    	m = read(), n = read(), target = read();
    	for(int i = 1; i <= m; i++) houses[i] = read();
    	for(int i = 1; i <= m; i++)
    		for(int j = 1; j <= n; j++) cost[i][j] = read();
        memset(f, inf, sizeof f);
        if(houses[1] == 0){
            for(int j = 1; j <= n; j++) f[1][1][j] = cost[1][j];
		}
		else f[1][1][houses[1]] = 0;
        
        for(int i = 2; i <= m; i++){
            for(int j = 1; j <= i; j++){
                if(houses[i] == 0){
                    for(int k = 1; k <= n; k++){
                        int jud = inf;
                        for(int p = 1; p <= n; p++)
                            if(p != k) jud = min(jud, f[i-1][j-1][p] + cost[i][k]);
                        f[i][j][k] = min(f[i-1][j][k] + cost[i][k], jud);
                    }
                }
                else{
                    int jud = inf;
                    for(int p = 1; p <= n; p++)
                        if(p != houses[i]) jud = min(jud, f[i-1][j-1][p]);
                    f[i][j][houses[i]] = min(f[i-1][j][houses[i]], jud);
                }
            }
        }
        ans = inf;
        for(int i = 1; i <= n; i++){
			ans = min(ans, f[m][target][i]);
//			printf("i : %d; f : %d\n", i, f[m][target][i]);
		}
        ans = (ans == inf? -1 : ans);
        cout << ans;
    }
