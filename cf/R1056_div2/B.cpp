#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
#define db double
#define pii pair<int, int>
#define mkp make_pair()
using namespace std;

inline int read(){
    int x = 0, f = 1; char ch = getchar();
    while(!isdigit(ch)){if(ch == '-') f = -1; ch = getchar();}
    while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - 48; ch = getchar();}
    return x * f;
}

const int N = 1e3 + 5;

int n, T, k;
bool ans;
char a[N][N];

void reset(){
    ans = true;
}

void solve(){
    if(k == n * n - 1){
        ans = false;
        return;
    }
    int rem = k % n, div = k / n;
    for(int i = 1; i <= n; i++){
        for(int j = n - div + 1; j <= n; j++) a[i][j] = 'R';
    }
    for(int i = 1; i <= rem; i++) a[i][n - div] = 'R';
    if(n - div > 1){
        for(int i = rem + 1; i <= n; i++) a[i][n - div] = 'L';
        for(int i = 1; i <= n; i++){
            for(int j = 1; j < n - div; j++){
                if(i == 1) a[i][j] = 'D';
                else if(i == n) a[i][j] = 'U';
                else a[i][j] = 'U';
            }
        }
    }
    else{
        for(int i = rem + 1; i <= n; i++){
            if(i == rem + 1) a[i][n - div] = 'D';
            else if(i == n) a[i][n - div] = 'U';
            else a[i][n - div] = 'U';
        }
    }
    
}

int main(){
    T = read();
    int count = T;
    while(T--){
        n = read(), k = read();
        reset();
        solve();
        // printf("Test %d : ", count - T);
        if(ans){
            printf("YES\n");
            for(int i = 1; i <= n; i++){
                for(int j = 1; j <= n; j++)
                    printf("%c", a[i][j]);
                printf("\n");
            }
        }
        else printf("NO\n");
    }
    return 0;
}