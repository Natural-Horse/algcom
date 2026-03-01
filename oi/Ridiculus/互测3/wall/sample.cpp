#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
#define db double
using namespace std;

inline int read(){
	int x = 0, f = 1; char ch = getchar();
	while(!isdigit(ch)){if(ch == '-') f = -1; ch = getchar();}
	while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - 48; ch = getchar();}
	return x * f;
}

const int N = 1e6 + 5, M = 1e2;

int n, m, q, k;

int main(){
    freopen("data.in", "w", stdout);
    n = 10;
    m = 10, q = 5, k = 0;
    printf("%d %d %d %d\n", n, m, q, k);
    for(int i = 1; i <= n; i++){
        ll w = rand() % M + 1;
        printf("%lld ", w);
    }
    printf("\n");
    for(int i = 1; i <= m; i++){
        int u = rand() % n + 1;
        int v = rand() % n + 1;
        printf("%d %d\n", u, v);
    }
    for(int i = 1; i <= q; i++){
        int op, u; ll x;
        op = rand() % 2 + 1;
        u = rand() % 10 + 1, x = rand() % M + 1;
        printf("%d %d %lld\n", op, u, x);
    }
    return 0;
}

