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

const int N = 1e5 + 5;

int n, p[N], cnt;
bool b[N];

int main(){
    n = read();
    memset(b, true, sizeof b);
    for(int i = 2; i <= n; i++){
        if(b[i]) p[++cnt] = i;
        for(int j = 1; j <= cnt && i*p[j] <= n; j++){
            b[i*p[j]] = false;
            if(i % p[j] == 0) break;
        }
    }
    printf("\n");
    for(int i = 1; i <= cnt; i++) printf("%d ", p[i]);
    return 0;
}