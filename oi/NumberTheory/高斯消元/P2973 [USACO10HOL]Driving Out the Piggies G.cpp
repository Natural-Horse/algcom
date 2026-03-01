#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
#define db double
using namespace std;

inline db read(){
    db x = 0, f = 1; char ch = getchar();
    while(!isdigit(ch)){if(ch == '-') f = -1; ch = getchar();}
    while(isdigit(ch)){x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int N = 3e2 + 5, M = 5e4 + 5;

struct Edge{
    int nxt, to;
}ed[M << 1];
int n, m, head[N], tot, plc[N];
db p, q, a[N][N], d[N], ans[N];

void add_edge(int u, int v){
    ed[++tot].nxt = head[u]; ed[tot].to = v; head[u] = tot;
}

void Gauss(){
    for(int i = 1; i <= n; i++){
        int jud = 0; db fab = 0;
        for(int j = 1; j <= n; j++) if(fabs(a[i][j]) > fabs(fab)) fab = a[i][j], jud = j;
        for(int j = 1; j <= n+1; j++) if(j != jud) a[i][j] /= a[i][jud];
        a[i][jud] = 1;
        for(int j = 1; j <= n; j++){
            if(j == i) continue;
            for(int k = 1; k <= n+1; k++) if(k != jud) a[j][k] -= a[i][k] * a[j][jud];
            a[j][jud] = 0;
        } 
        plc[i] = jud;
    }
}

int main(){
    n = read(), m = read(), p = read(), q = read();
    for(int i = 1, u, v; i <= m; i++){
        u = read(), v = read();
        add_edge(u, v), add_edge(v, u);
        d[u] += 1, d[v] += 1;
    }
    for(int i = 1; i <= n; i++){
        a[i][i] = 1;
        if(i == 1) a[i][n+1] = p / q;
        for(int j = head[i]; j; j = ed[j].nxt){
            int v = ed[j].to;
            a[i][v] = (p / q - 1) * (1 / d[v]);
        }
    }
    Gauss();
    for(int i = 1; i <= n; i++) ans[plc[i]] = a[i][n+1];
    for(int i = 1; i <= n; i++) printf("%lf\n", ans[i]);
    return 0;
}
