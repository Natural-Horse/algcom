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

const int N = 2e5 + 5;

int n, m, p;

int main(){
    n = read(), m = read(), p = read();
    int cnt = 0;
    while(m <= n){
        cnt++;
        m += p;
        // printf("m : %d\n", m);
    }
    printf("%d\n", cnt);
    return 0;
}