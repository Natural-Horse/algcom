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

const int N = 15;
int n, m1, m2, w[N][N], a[N][N], b[N][N], ans;

int main(){
    n = read(), m1 = read();
    ans = inf;
    for(int i = 1, u, v; i <= m1; i++){
        u = read(), v = read();
        a[u][v] = a[v][u] = 1;
    }
    m2 = read();
    for(int i = 1, u, v; i <= m2; i++){
        u = read(), v = read();
        b[u][v] = b[v][u] = 1;
    }
    for(int i = 1; i < n; i++){
        for(int j = i+1; j <= n; j++) w[i][j] = read(), w[j][i] = w[i][j];
    }
    vector<int> vec(n);
    iota(vec.begin(), vec.end(), 1);
    do{
        int res = 0;
        // for(auto p : vec) printf("%d ", p);
        // printf("\n");
        for(int i = 1; i < n; i++){
            for(int j = i+1; j <= n; j++){
                if(b[i][j] != a[vec[i-1]][vec[j-1]]) res += w[i][j];
            }
        }
        ans = min(ans, res);
    }while(next_permutation(vec.begin(), vec.end()));
    printf("%d\n", ans);
    return 0;
}