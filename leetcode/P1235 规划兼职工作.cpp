#include<bits/stdc++.h>
#define inf 2147483647
#define ll long long
#define db double
#define R register
using namespace std;

inline int read(){
	int x = 0, f = 1; char ch = getchar();
	while(!isdigit(ch)){if(ch == '-') f = -1; ch = getchar();}
	while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - 48; ch = getchar();}
	return x * f;
}

const int N = 5e4 + 5, B = 305;
int n, ls[N<<2], tot, f[N<<2], startTime[N], endTime[N], profit[N];
vector<pair<int,int>> vec[N<<2];
int main() {
    n = read();
    for(int i = 0; i < n; i++) startTime[i] = read();
    for(int i = 0; i < n; i++) endTime[i] = read();
    for(int i = 0; i < n; i++) profit[i] = read();
    for(int i = 0; i < n; i++){
        // startTime[i] = read(), endTime[i] = read(), profit[i] = read();
        ls[++tot] = startTime[i], ls[++tot] = endTime[i];
        // ls[++tot] = startTime[i] - 1, ls[++tot] = endTime[i] - 1;
    }
    sort(ls + 1, ls + 1 + tot);
    tot = unique(ls + 1, ls + 1 + tot) - ls - 1;
    int mx = 0;
    for(int i = 0; i < n; i++){
        int l = lower_bound(ls + 1, ls + 1 + tot, startTime[i]) - ls;
        int r = lower_bound(ls + 1, ls + 1 + tot, endTime[i]) - ls;
        vec[r].push_back({l, profit[i]});
    }
    f[0] = 0;
    for(int i = 1; i <= tot; i++){
        f[i] = max(f[i], mx);
        for(auto u : vec[i]){
            int v = u.first, w = u.second;
            f[i] = max(f[i], f[v] + w);
        }
        mx = max(mx, f[i]);
    }
    // return f[tot];
    printf("%d\n", mx);
    return 0;
}