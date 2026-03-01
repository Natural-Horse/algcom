#include<bits/stdc++.h>
#define inf 2e14
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
ll a[N], s[N], mx;
priority_queue<ll> q;

int main(){
    n = read();
    // mx = -inf;
    for(int i = 1; i <= n; i++){
        a[i] = read(), s[i] = a[i] + s[i-1];
    }
    int pt = 1;
    while(s[pt] == 0 && pt <= n) pt++;
    if(s[pt] < 0 || s[n] < 0){
        printf("-1\n");
        return 0;
    }
    ll res = 0, t = 0;
    for(int i = 1; i <= n; i++){ 
        int j = i;
        ll fab = 0;
        while(s[j] < 0) fab += s[j], j++;
        if(j == i){
            q.push(s[i]); 
            res += s[i], t++;
        }
        else{
            ll jud = q.top();
            if(res + fab >= 0) res += fab;
            else{
                ll k = (-res - fab) / jud + ((-res - fab) % jud != 0);
                t += k, res = res + fab + k * jud;
            }
            t += j - i;
            i = j - 1;
        }
    }
    printf("%lld\n", t);
    return 0;
}