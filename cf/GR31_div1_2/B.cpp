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

const int N = 1e3 + 5;

int T, n;
string a[N], s;

void reset(){
    s.clear();
}

void solve(){
    for(int p = 1; p <= n; p++){
        string new_s = a[p];
        string str_a = new_s + s, str_b = s + new_s;
        if(s.empty()){
            s = new_s;
        }
        else{
            if(str_a < str_b){
                s = str_a;
            }
            else s = str_b;
        }
    }
}

int main(){
    T = read();
    while(T--){
        n = read();
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        reset();
        solve();
        // printf("ans : ");
        cout << s << endl;
    }
    return 0;
}