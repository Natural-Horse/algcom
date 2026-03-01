// clang-format off
#include <bits/stdc++.h>
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

int n, cnt;
string s, t;

int main(){
    n = read();
    cin >> s >> t;
    for(int i = 0; i < n; i++){
        if(s[i] != t[i]) cnt++;
    }
    cout << cnt << endl;
    return 0;
}