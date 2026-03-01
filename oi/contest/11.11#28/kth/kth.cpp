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

const int N = 5e5 + 5;

ll n, k, a[N], ans;
priority_queue<int, vector<int>, greater<int> > q;

int main(){
    freopen("kth.in", "r", stdin);
    freopen("kth.out", "w", stdout);
    n = read(), k = read();
    for(int i = 1; i <= n; i++) a[i] = read();
    for(int i = k; i <= n; i++){
        while(!q.empty()) q.pop();
        for(int j = i; j >= i-k+1; --j) q.push(a[j]);
        ans += q.top();
        for(int j = i-k; j; --j){
            int u = q.top();
            if(a[j] > u){q.pop(); q.push(a[j]);}
            ans += q.top();
        }
    }
    printf("%lld\n", ans);
    return 0;
}

