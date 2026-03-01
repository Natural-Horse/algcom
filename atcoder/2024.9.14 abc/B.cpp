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
int n, m;
int a[N];
char s[N];
bool b[N];

int main(){
    n = read(), m = read();
    for(int i = 1; i <= m; i++){
        a[i] = read();
        // getchar();
        s[i] = getchar(); 
        if(!b[a[i]] && s[i] == 'M') printf("Yes\n"), b[a[i]] = true;
        else printf("No\n");
    }
    return 0;
}