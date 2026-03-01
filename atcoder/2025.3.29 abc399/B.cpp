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

int n, a[N], cnt, rk[N], r;
bool b[N];
vector<int> vec;

int main(){
    n = read();
    r = 1;
    for(int i = 1; i <= n; i++) a[i] = read();
    while(r <= n){
        int mx = 0;
        vec.clear();
        for(int i = 1; i <= n; i++){
            if(b[i]) continue;
            if(a[i] > mx){
                vec.clear();
                mx = a[i];
                vec.push_back(i);
            }
            else if(a[i] == mx) vec.push_back(i);
        }
        for(auto p : vec){
            rk[p] = r;
            b[p] = true;
        }
        r += vec.size();
    }
    for(int i = 1; i <= n; i++) printf("%d\n", rk[i]);
    return 0;
}