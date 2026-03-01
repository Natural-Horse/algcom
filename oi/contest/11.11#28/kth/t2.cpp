#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
#define db double
#define int long long
using namespace std;

inline int read(){
	int x = 0, f = 1; char ch = getchar();
	while(!isdigit(ch)){if(ch == '-') f = -1; ch = getchar();}
	while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - 48; ch = getchar();}
	return x * f;
}
 
const int N = 2e5 + 5;

ll n, k, a[N], ans;
int nxt[N], las[N], stk[N], top;
bool b[N];

signed main(){
    freopen("kth2.in", "r", stdin);
//    freopen("1.out", "w", stdout);
    n = read(), k = read();
    for(int i = 1; i <= n; i++) a[i] = read();
    for(int i = 1; i <= n; i++){
        if(!top){stk[++top] = i; continue;} 
        while(a[i] > a[stk[top]] && top) nxt[stk[top]] = i, top--;
        stk[++top] = i;
    }
    top = 0;
    for(int i = n; i; --i){
        if(!top){stk[++top] = i; continue;}
        while(a[i] > a[stk[top]] && top) las[stk[top]] = i, top--;
        stk[++top] = i;
    }
//    for(int i = 1; i <= n; i++) printf("%d %d\n", nxt[i], las[i]);
    for(int i = 1; i <= n; i++){
        int l = i, r = i, len = 1;
        while(len <= k && l){
            int fab = l;
            l = las[l];
            if(l) len++;
            else nxt[l] = fab;
        }
        while(len <= k && nxt[r]){
            r = nxt[r];
            if(r) len++;
        }
        while(nxt[l] && r){
            if(!nxt[r]) ans += (min(nxt[l], i) - l) * (n + 1 - r) * a[i];
            else ans += (min(nxt[l], i) - l) * (nxt[r] - r) * a[i];
            l = nxt[l], r = nxt[r];
            if(l > i) break;
        }
    }
    printf("%lld\n", ans);
    return 0;
}

