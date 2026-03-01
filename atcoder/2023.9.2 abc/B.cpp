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

const int N = 205;

int n, s[N][N], ans;

int main(){
    n = read();
    for(int i = 1, a, b, c, d; i <= n; i++){
        a = read(), b = read(), c = read(), d = read();
        for(int j = a+1; j <= b; j++)
            for(int k = c+1; k <= d; k++)
                if(!s[j][k]) s[j][k] = 1;
    }
    for(int i = 1; i <= 200; i++)
        for(int j = 1; j <= 200; j++) 
            if(s[i][j]) ans++;
    printf("%d\n", ans);
    return 0;
}