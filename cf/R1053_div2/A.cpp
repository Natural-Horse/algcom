#include <bits/stdc++.h>
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

int n, m, T, a[N], ans;


int main(){
    T = read();
    while(T--){
        n = read(), m = read();
        bool flag = false;
        for(int i = 1; i <= m; i++){
            a[i] = read();
            if(a[i] <= a[i-1]) flag = true;
        }
        if(!flag){
            ans = n - a[m] + 1;
        }
        else ans = 1;
        printf("%d\n", ans);
    }
    return 0;
}