// clang-format off
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define pii pair<long long, long long>
#define mkp make_pair
#define ll long long
#define int long long
using namespace std;

inline int read(){
    int x = 0, f = 1; char ch = getchar();
    while (!isdigit(ch)){if(ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch)){x = (x << 3) + (x << 1) + ch - 48; ch = getchar();}
    return x * f;
}

const int N = 2e9 + 5;

char s[N];
int n, m, las, ans;
vector<pii> vec;

signed main(){
    n = read(), m = read();
    for(int i = 1; i <= m; i++) vec.push_back(mkp(read(), 0));
    for(int i = 1; i <= m; i++) vec[i-1].second = read();
    sort(vec.begin(), vec.end(), [](pii &aa, pii &bb){return aa.first < bb.first;});
    las = n + 1;
    for(int i = vec.size() - 1; i >= 0; --i){
        int jud = las - vec[i].first;
        if(jud >= vec[i].second){
            ans += (las - vec[i].second - vec[i].first + las - 1 - vec[i].first) * vec[i].second / 2;
            las = las - vec[i].second;
        }
        else{
            printf("-1\n");
            return 0;
            ans += (las - vec[i].first) * (las - 1 - vec[i].first) / 2;
            las = vec[i].first;
        }
        // ans += min(, 
        //     (las - vec[i].second - vec[i].first + las - 1 - vec[i].first) * vec[i].second / 2);
        // las = max(vec[i].first,  las - vec[i].second);
        
    }
    if(las != 1) printf("-1\n");
    else printf("%lld\n", ans);
    return 0;
}