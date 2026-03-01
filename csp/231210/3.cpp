#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

inline int read(){
    int x = 0, f = 1; char ch = getchar();
    while(!isdigit(ch)){if(ch == '-') f = -1; ch = getchar();}
    while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - 48; ch = getchar();}
    return x * f;
}

const int N = 2e3 + 5, M = 105;

struct Edge{
    int u, v, nxt;
}ed[N];
int n, m, x, hd[N], tot;
bool son[N];
ll w[N];

void add_edge(int u, int v){
    ed[++tot].nxt = hd[u];
    ed[tot].u = u, ed[tot].v = v;
}

int get_son(int u){
    int res = 0;
    for(int i = hd[u]; i; i = ed[i].nxt){
        int v = ed[i].v; 
        res += get_son(v);
    }
    return res;
}

int main(){
    n = read(), m = read();
    for(int i = 1; i <= n; i++) w[i] = read();
    for(int i = 2, p; i <= n; i++){
        p = read();
        add_edge(p, i), son[p] = true;
    }
    while(m--){
        x = read();
        while(son[x]){
            
        }
    }
}