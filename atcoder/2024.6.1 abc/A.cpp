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

int n, l, r;

int main(){
    n = read(), l = read(), r = read();
    for(int i = 1; i < l; i++) printf("%d ", i);
    for(int i = r; i >= l; --i) printf("%d ", i);
    for(int i = r+1; i <= n; i++) printf("%d ", i);
    return 0;
}