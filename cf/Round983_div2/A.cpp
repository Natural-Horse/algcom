// clang-format off
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

inline int read(){
    int x = 0, f = 1; char ch = getchar();
    while(!isdigit(ch)){if(f == '-') f = -1; ch = getchar();}
    while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - 48; ch = getchar();}
    return x * f;
}

const int N =55; 
int T, n, a[N * 2], cnt, maxans, minans;

int main(){
    T = read();
    while(T--){
        n = read();
        cnt = 0;
        for(int i = 1; i <= n * 2; i++){
            a[i] = read();
            cnt += (a[i] == 1);
        }
        minans = cnt & 1;
        if(cnt <= n) maxans = cnt;
        else maxans = n - (cnt - n);
        printf("%d %d\n", minans, maxans);
    }
    return 0;
}