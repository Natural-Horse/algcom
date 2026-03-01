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

const int N = 15;

string a, b, c;
int n, m, T;

int main(){
    T = read();
    while(T--){
        n = read();
        cin >> a;
        m = read();
        cin >> b;
        cin >> c;
        int pt = 0;
        for(auto ch : b){
            if(c[pt] == 'D') a = a + ch;
            else if(c[pt] == 'V') a = ch + a;
            pt++;
        }
        cout << a << endl;
    }
    return 0;
}