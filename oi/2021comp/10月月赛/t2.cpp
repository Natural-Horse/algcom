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

const int N = 1e6 + 5;

int n, m, k, T;
int a[N];

int main(){
    T = read();
    while(T--){
        n = read(), m = read(), k = read();
        if((n*m) % k){printf("NO\n"); continue;}
        printf("YES\n");
        int les = k, cnt = 1;
        for(int i = 1; i <= n*m; i++){
            a[i] = cnt, les--;
            if(!les) cnt++, les = k;
        }
        for(int i = 1; i <= n; i++){
            if(i & 1) for(int j = (i-1)*m+1; j <= i*m; j++) printf("%d ", a[j]);
            else for(int j = i*m; j > (i-1)*m; --j) printf("%d ", a[j]);
            printf("\n");
        }
    }
    return 0;
}

