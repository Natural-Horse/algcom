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

const int N = 105;

string s[N];
int n, ans;

int main(){
    n = read();
    for(int i = 1; i <= n; i++){
        cin >> s[i];
        if(s[i] == "Takahashi") ans++;
    }
    printf("%d\n", ans);
    return 0;
}