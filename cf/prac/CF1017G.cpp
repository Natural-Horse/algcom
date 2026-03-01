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

struct Nd{
    int adj[2];
    ll val;
}nd[N];

int n, T, dir, q;    //dir为正向，dir^1为逆向, nd[dir^1]为起点，nd[dir]为终点
ll sum[2], tot, nsum;

void init(){
    nd[0].adj[1] = 1;
    nd[1].adj[0] = 0;
    sum[0] = sum[1] = nsum = 0;
    tot = 1;
    dir = 1;      //dir==1从左向右，dir==0从右向左
}

void add(int val){
    nd[++tot].val = val;
    nd[tot].adj[dir] = dir;
    nd[tot].adj[dir^1] = nd[dir].adj[dir^1];
    nd[nd[dir].adj[dir^1]].adj[dir] = tot;
    nd[dir].adj[dir^1] = tot;

    sum[dir] += (tot - 1) * val;
    sum[dir^1] += val + nsum;
    

    nsum += val;

    // sum[dir^1] = tot * nsum - sum[dir];
}

void ror(){
    int u = nd[dir].adj[dir^1];
    nd[dir].adj[dir^1] = nd[u].adj[dir^1];
    nd[nd[u].adj[dir^1]].adj[dir] = dir;

    int v = nd[dir^1].adj[dir];
    nd[dir^1].adj[dir] = u;
    nd[v].adj[dir^1] = u;
    nd[u].adj[dir] = v, nd[u].adj[dir^1] = dir^1;
    
    sum[dir] += nsum - (tot - 1) * nd[u].val;
    sum[dir^1] += (tot - 1) * nd[u].val - nsum;
    // sum[dir^1] = tot * nsum - sum[dir];
}

int main(){
    T = read();
    while(T--){
        init();
        q = read();
        for(int i = 1, op; i <= q; i++){
            op = read();
            if(op == 1){
                if(tot > 2) ror();
                printf("%lld\n", sum[dir]);
            }
            else if(op == 2) dir ^= 1, printf("%lld\n", sum[dir]);
            else if(op == 3){
                ll val = read();
                add(val);
                // printf("step[%d] : %lld, dir : %d\n", i, sum[dir], dir);
                printf("%lld\n", sum[dir]);
            }
        }
    }
    return 0;
}