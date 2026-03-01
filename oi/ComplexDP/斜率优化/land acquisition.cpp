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

const int N = 5e4 + 5;

struct Nd{
    int w, l;
}a[N], b[N];
int n, cnt, q[N], head, tail;
ll f[N];

bool cmp(Nd aa, Nd bb){
    return aa.w == bb.w? aa.l > bb.l : aa.w > bb.w;
}
db slope(int u, int v){
    return (db)(f[u] - f[v]) / (db)(b[v+1].w - b[u+1].w);
}

int main(){
    n = read();
    for(int i = 1; i <= n; i++) a[i].w = read(), a[i].l = read();
    sort(a + 1, a + 1 + n, cmp);
    int jud = 0;
    for(int i = 1; i <= n; i++)
        if(a[i].l > jud) b[++cnt] = a[i], jud = a[i].l;
    head = tail = 1;
    for(int i = 1; i <= cnt; i++){
        while(head < tail && slope(q[head], q[head+1]) <= b[i].l) head++;
        int j = q[head];
//        printf("%d\n", j);
        f[i] = f[j] + (ll)b[j+1].w * (ll)b[i].l;
        while(head < tail && slope(q[tail-1], q[tail]) >= slope(q[tail], i)) tail--;
        q[++tail] = i;
    }
    printf("%lld\n", f[cnt]);
    return 0;
}

