#include <bits/stdc++.h>
#define inf 0x3f3f3f3f3f
#define ll long long
using namespace std;

inline int read(){
    int x = 0, f = 1; char ch = getchar();
    while(!isdigit(ch)){if(f == '-') f = -1; ch = getchar();}
    while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - 48; ch = getchar();}
    return x * f;
}

const int N = 2e5 + 5;

int n, T;
string s, ans;
vector<int> l, r;
int p[N];

void reset(){
    ans = "NO\n";
    l.clear(), r.clear();
}

void extract(){
    int len = s.length();
    for(int i = 0; i < len; i++){
        if(s[i] == '1'){
            if(l.size() > r.size()){
                r.push_back(i);
            }
        }
        else{
            if(l.size() == r.size()){
                l.push_back(i+1);
            }
        }
    }
    if(s[len-1] == '0') r.push_back(len); 
}

void solve(){
    extract();
    int len = s.length();
    for(int i = 0; i < len; i++)
        if(s[i] == '1') p[i+1] = i + 1;
    for(int i = 0; i < l.size(); i++){
        if(l[i] - r[i] + 1 == 1){
            ans = "NO\n";
            return;
        }
        else{
            p[l[i]] = r[i];
            for(int j = l[i] + 1; j <= r[i]; j++)
                p[j] = j - 1;
        }
    }
    ans = "YES\n";
}


int main(){
    T = read();
    int count = T;
    while(T--){
        n = read();
        cin >> s;
        reset();
        solve();
        cout << ans;
        if(ans == "YES\n"){
            for(int i = 1; i <= n; i++) printf("%d ", p[i]);
            printf("\n");
        }
    }
    return 0;
}