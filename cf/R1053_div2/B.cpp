#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
#define pii pair<int, int>
#define mkp make_pair
using namespace std;

inline int read(){
    int x = 0, f = 1; char ch = getchar();
    while(!isdigit(ch)){if(ch == '-') f = -1; ch = getchar();}
    while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - 48; ch = getchar();}
    return x * f;
}

const int N = 3e5 + 5;

int n, m, T, a[N], b[N], cnt, ans[N];
int tot;
string s;
pii seg[N];

bool cmp(pii &aa, pii &bb){
    return (aa.first == bb.first) ? aa.first < bb.first : aa.second < bb.second;
}

void reset(){
    tot = cnt = 0;
}

void solve(){
    int lasplc = 0, pt = 1, plc = 1;
    tot = m;
    for(int i = 0; i < n; i++){
        if(i == 0){
            if(s[i] == 'B'){
                plc++;
                if(a[pt] < plc && pt < m) pt++;
                while(a[pt] == plc){
                    if(pt < m) pt++;
                    plc++;
                }
                lasplc = plc;
                a[++tot] = plc;
            }
            else{
                plc++;
                if(a[pt] < plc && pt < m) pt++;
                lasplc = plc;
                if(a[pt] > plc || (pt == m && a[pt] < plc)) a[++tot] = plc;
            }
        }
        else{
            if(s[i] == 'B'){
                if(s[i-1] == 'A'){
                    plc++;
                    if(a[pt] < plc && pt < m) pt++;
                    while(a[pt] == plc){
                        if(pt < m) pt++;
                        plc++;
                    }
                    lasplc = plc, a[++tot] = plc;
                }
                else{
                    plc++;
                    while(a[pt] == plc){
                        if(pt < m) pt++;
                        plc++;
                    }
                    plc++;
                    while(a[pt] == plc){
                        if(pt < m) pt++;
                        plc++;
                    }
                    lasplc = plc, a[++tot] = plc;
                }
            }
            else{
                if(s[i-1] == 'A'){
                    plc++;
                    if(a[pt] < plc && pt < m) pt++;
                    lasplc = plc;
                    if(a[pt] > plc || (pt == m && a[pt] < plc)) a[++tot] = plc;
                }
                else{
                    plc++;
                    while(a[pt] == plc){
                        if(pt < m) pt++;
                        plc++;
                    }
                    plc++;
                    if(a[pt] < plc && pt < m) pt++;
                    lasplc = plc;
                    if(a[pt] > plc || (pt == m && a[pt] < plc)) a[++tot] = plc;
                }
            }
        }
    }
    sort(a + 1, a + 1 + tot);
    tot = unique(a + 1, a + 1 + tot) - a - 1;
}


int main(){
    T = read();
    int count = T;
    while(T--){
        n = read(), m = read();
        cin >> s;
        for(int i = 1; i <= m; i++){
            a[i] = read();
            seg[i] = mkp(a[i], a[i]);
        }
        reset();
        solve();
        // printf("ans%d : \n", count - T);
        printf("%d\n", tot);
        for(int i = 1; i <= tot; i++) printf("%d ", a[i]);
        printf("\n");
    }
    return 0;
}