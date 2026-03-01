// clang-format off
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
#define pii pair<int, int>
using namespace std;

inline int read(){
    int x = 0, f = 1; char ch = getchar();
    while (!isdigit(ch)){if (f == '-') f = -1; ch = getchar();}
    while (isdigit(ch)){x = (x << 3) + (x << 1) + ch - 48; ch = getchar();}
    return x * f;
}

const int N = 2e5 + 5;

int T, n, q, cnt, tmp[N];
string s;

int main(){
    // freopen("C.out", "w", stdout);
    T = read();
    while (T--){
        cnt = 0;
        cin >> s;
        n = s.length();
        for(int i = 0; i < n-3; i++){
            int check = 1;
            if(s[i] != '1' || s[i+1] != '1' || s[i+2] != '0' || s[i+3] != '0') check = 0;
            cnt += check;
            tmp[i] = check;
        }
        q = read();
        for(int i = 1, plc, val; i <= q; i++){
            plc = read() - 1, val = read();
            int check = 1;
            s[plc] = val + '0';
            for(int j = plc - 3; j <= plc && j + 3 < n; j++){
                if(s[j] != '1' || s[j+1] != '1' || s[j+2] != '0' || s[j+3] != '0'){
                    if(tmp[j] == 1) cnt--, tmp[j] = 0;
                }
                else if(tmp[j] == 0) cnt++, tmp[j] = 1;
            }
            if(cnt > 0) printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}