#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
#define db double
using namespace std;

inline int read(){
	int x = 0, f = 1; char ch = getchar();
	while(!isdigit(ch)){if(ch == '-') f = -1; ch = getchar();}
	while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - 48; ch = getchar();}
	return x * f;
}

const int N = 4e6 + 500, M = 5e2 + 5;

ll n, m, ans = inf;
ll f[N], t[M], s[N], c[N]; 
ll q[N], head, tail;

db slope(int u, int v){
    return (db)(f[v]+s[v]-f[u]-s[u]) / (db)(c[v]==c[u]?1e-9:c[v]-c[u]);
}

int main(){
    n = read(), m = read();
    for(int i = 1; i <= n; i++) t[i] = read() + 1;
    sort(t + 1, t + 1 + n);
    int lim = t[n] + m;
    int cnt = 1;
    head = tail = 1;
    for(int i = 0; i < lim; i++){
        s[i] = s[i-1], c[i] = c[i-1];
        while(i == t[cnt]) s[i] += t[cnt++], c[i]++;
        if(i - m > 0){
            while(head < tail && slope(q[tail-1],q[tail]) >= slope(q[tail],i-m)) tail--;
            q[++tail] = i-m;
        }
        int p = i * c[i] - s[i];
        while(head < tail && slope(q[head],q[head+1]) <= i) head++;
        int j = q[head];
        f[i] = p;
        if(head <= tail){
            f[i] = min(f[i], f[j] + p + s[j] - i*c[j]);
        }
    }
    for(int i = t[n]; i < lim; i++) ans = min(ans, f[i]);
    printf("%d\n", ans);
    return 0;
}

