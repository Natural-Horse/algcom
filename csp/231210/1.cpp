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

const int N = 2e5 + 5, M = 12;

int n, m, a[N][M];

int main(){
    n = read(), m = read();
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) a[i][j] = read();
        int cnt = 0;
    for(int i = 1; i <= n; i++){
        bool check = true;
        for(int j = 1; j <= n; j++){
            if(i == j) continue;
            check = true;            
            for(int k = 1; k <= m; k++){
                if(a[i][k] >= a[j][k]){check = false; break;}
            }
            if(check){printf("%d\n", j); break;}
        }
        if(!check) printf("0\n");
    }
    // printf("%d\n", cnt);
    return 0;
}