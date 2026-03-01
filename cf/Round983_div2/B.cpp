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

const int N = 2e5 + 5; 
int T, n, a[N], k;

int main(){
    T = read();
    while(T--){
        n = read(), k = read();
        int l = k - 1, r = n - k;
        if(n != 1){
            if(l == 0 || r == 0){
                printf("-1\n");
                continue;
            }
            if((l + r) & 1){
                printf("-1");
                continue;
            }
            else{
                if(l & 1){
                    printf("3\n");
                    printf("%d %d %d\n", 1, k, k + 1);
                }            
                else{
                    printf("3\n");
                    printf("%d %d %d\n", 1, k - 1, k + 2);
                }
            }   
        }
        else{
            printf("1\n1\n");
            continue;
        }
        
    }
    return 0;
}