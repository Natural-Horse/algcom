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

const int N = 4e4 + 5; 
int T, n, a[N], k, l, r, tmp, cnt, res, lasl, lasr;

int main(){
    T = read();
    while(T--){
        n = read();
        l = tmp = r = cnt = res = 0;
        for(int i = 2; i <= n; i++){
            printf("? 1 %d", i);
            cnt++;
            res = 0;
            scanf("%d", &res);
            if(res == 0){
                l = 1, r = i - 1, tmp = i - 1;
                break;
            }
            fflush(stdout);
        }
        while(tmp < n){
            if(cnt >= n * 2 - 6){

            }
            int mid = (l + r) >> 1;
            printf("? %d %d", tmp - (r - l + 1) + 1, tmp + mid - l + 1);
            scanf("%d", &res);
            if(res == )
        }
    }
    return 0;
}