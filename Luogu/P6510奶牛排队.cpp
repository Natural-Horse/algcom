// clang-format off
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
#define pll pair<ll, ll>
using namespace std;

inline ll read(){
    ll x = 0, f = 1;
    char ch = getchar();
    while (!isdigit(ch)){
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (isdigit(ch)){
        x = (x << 3) + (x << 1) + ch - 48;
        ch = getchar();
    }
    return x * f;
}

const int N = 1e5 + 5;

struct Stack{
    ll h, id;
}st[N];
ll n, a[N], top, ans, r[N];

pll solve(int st, int re){
    if(st > re) return make_pair(0, 0);
    if(st == re) return make_pair(a[st], st);
    int jud = a[st], plc = st;
    for(int i = st; i <= re; i++){
        pll res = solve(i + 1, r[i]);
        if(!plc) jud = res.first, plc = res.second;
        else if(res.first > jud) jud = res.first, plc = res.second;
        ans = max(ans, res.second - i + 1);
        i = r[i];
    }
    // if(!plc) jud = a[st], plc = st;
    // else if(a[st] > jud) jud = a[st], plc = st;
    return make_pair(jud, plc);
}

int main(){
    int n = read();
    for (int i = 1; i <= n; i++){
        a[i] = read();
        while (top && a[i] <= st[top].h){
            r[st[top].id] = i - 1;
            top--;
        }
        st[++top] = {a[i], i};
    }
    while(top){
        r[st[top].id] = n;
        top--;
    }
    for(int i = 1; i <= n; i++){
        pll res = solve(i + 1, r[i]);
        if(res.second > i) ans = max(ans, res.second - i + 1);
        i = r[i];
    }
    printf("%lld\n", ans);
    return 0;
}