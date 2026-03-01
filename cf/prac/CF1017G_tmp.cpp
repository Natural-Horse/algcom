// clang-format off
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f3f3f3f3f
#define ll long long
using namespace std;

inline ll read(){
    ll x = 0, f = 1; char ch = getchar();
    while(!isdigit(ch)){if(ch == '-') f = -1; ch = getchar();}
    while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - 48; ch = getchar();}
    return x * f;
}

const int N = 2e5 + 5;

int n, T, dir, q;    //dir为正向，dir^1为逆向, nd[dir^1]为起点，nd[dir]为终点
ll sum[2], tot, nsum;
deque<ll> dq[2];

void clear(){
    sum[1] = sum[2] = nsum = 0;
    tot = 0;
    dir = 1;      //dir==1从左向右，dir==0从右向左
    dq[1].clear(), dq[0].clear();
}

void solve(){
    for(int i = 1, op; i <= q; i++){
        op = read();
        if(op == 1){
            ll tmp = dq[dir].back();
            dq[dir].pop_back(), dq[dir].push_front(tmp);
            sum[dir] += nsum - dq[dir].size() * tmp;

            tmp = dq[dir^1].front();
            dq[dir^1].pop_front(), dq[dir^1].push_back(tmp);
            sum[dir^1] += dq[dir^1].size() * tmp - nsum;

            printf("%lld\n", sum[dir]);
        }
        else if(op == 2){
            dir ^= 1;
            printf("%lld\n", sum[dir]);
        }
        else if(op == 3){
            ll val = read();
            dq[dir].push_back(val);
            sum[dir] += dq[dir].size() * val;
            nsum += val;

            dq[dir^1].push_front(val);
            sum[dir^1] += nsum;

            printf("%lld\n", sum[dir]);
        }
    }
}

int main(){
    T = read();
    while(T--){
        clear();
        q = read();
        solve();
    }
    return 0;
}