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

int a[N<<1], n, ans, pre[N];

int main(){
    n = read();
    for(int i = 1; i <= (n<<1); i++){
        a[i] = read();
        if(!pre[a[i]]) pre[a[i]] = i;
        else if(i - pre[a[i]] == 2) ans++;
    }
    printf("%d\n", ans);
    return 0;
}