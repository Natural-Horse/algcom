#include<bits/stdc++.h>
#define inf 0x3f3f3f
#define ll long long
using namespace std;

inline int read(){ 
    int x = 0, f = 1; char ch = getchar();
    while(!isdigit(ch)){if(ch == '-') f = -1; ch = getchar();}
    while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - 48; ch = getchar();}
    return x * f;
}

const int N = 1e5 + 5;

int n;
ll p[N], LCM;

ll getlcm(int l, int r){
    if(l == r) return p[l];
    int mid = (l + r) >> 1;
    ll la = getlcm(l, mid), lb = getlcm(mid+1, r);
    return la * lb / gcd(la, lb);
}

bool check(ll x){
    ll sq = sqrt(LCM * x * 2);
    if(sq * (sq + 1) == LCM * x * 2) return true;
    else return false;
}

ll find(ll l, ll r){
    ll mid = (l + r) >> 1;
    while(l < r){
        mid = (l + r) >> 1;
        if(!check(mid)) l = mid + 1;
        else r = mid;
    }
    return mid;
}

int main(){
    n = read();
    for(int i = 1; i <= n; i++) p[i] = read();
    LCM = getlcm(1, n);
    printf("LCM:%lld\n", LCM);
    ll ans = find(1, 1e18+1);
    printf("%lld\n", ans);
    return 0;
}