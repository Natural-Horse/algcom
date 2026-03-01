#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
#define db double
#define ull unsigned long long
using namespace std;

inline int read(){
	int x = 0, f = 1; char ch = getchar();
	while(!isdigit(ch)){if(ch == '-') f = -1; ch = getchar();}
	while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - 48; ch = getchar();}
	return x * f;
}

const ll N = 1e6 + 5;

int n, a[N], b[N], cnt[N], mn = inf, mx;
ull ans;
vector<int> vec[N];
queue<int> q;

bool cmp(ull aa, ull bb){
    return aa > bb;
}

int main(){
    freopen("sample_openhook4.in", "r", stdin);
//    freopen("1", "w", stdout);
    n = read();
    for(int i = 1; i <= n; i++){
        a[i] = read();
        vec[a[i]].push_back(i);
        mx = max(mx, a[i]), mn = min(mn, a[i]);
    } 
    for(int i = 1; i <= n; i++) b[i] = read();
    int pt = mn, val = mn;
    for(pt = mn; pt <= mx; pt++){
        if(vec[pt].size() > 1) break; 
    }
    
    q.push(pt);
    if(pt == mx && vec[mx].size() <= 1){
        printf("0\n");
        return 0;
    }
    for(val = mn; ; val++){
        if(!vec[val].size()) break;
    }
//    printf("%d %d\n", mx, mn);
    while(!q.empty()){
        int u = q.front(); q.pop();
        int sz = vec[u].size();
        for(int i = 0; i < sz-1; i++){
            cnt[vec[u][i]] = val - u;
            val++;
            while(vec[val].size()) val++;
        }
        int v = u + 1;
        if(v > mx) break;
        for(v = u + 1; v <= mx; v++){
            if(vec[v].size() > 1) break;
        }
        q.push(v);
    }
    sort(cnt + 1, cnt + 1 + n, cmp);
    sort(b + 1, b + 1 + n);
    for(int i = 1; i <= n; i++){
        ans += (ull)cnt[i] * (ull)b[i];
    }
    printf("%llu\n", ans);
    return 0;
}

