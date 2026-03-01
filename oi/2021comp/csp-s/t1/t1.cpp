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

int n, m, k, f[N], g[N], mxb, mxa, wa[N], wb[N], cnta, cntb, ans;
set<int> sa, sb;
map<int,int> mpa, mpb;

int main(){
//    freopen("airport2.in", "r", stdin);
//    freopen("1.out", "w", stdout);
    n = read(), m = read(), k = read();
    for(int i = 1, l, r; i <= m; i++){
        l = read(), r = read();
        sa.insert(l);
        mpa[l] = r, mxa = max(mxa, l);
    }
    for(int i = 1, l, r; i <= k; i++){
        l = read(), r = read();
        sb.insert(l);
        mpb[l] = r, mxb = max(mxb, l);
    }
    while(!sa.empty()){
        int plc = mpa[*sa.begin()];
        sa.erase(sa.begin()); 
        wa[++cnta] = 1;
        while(!sa.empty() && plc <= *sa.rbegin()){
            int jud = *sa.lower_bound(plc);
            sa.erase(jud); 
            wa[cnta]++, plc = mpa[jud];
        }
    }
    while(!sb.empty()){
        int plc = mpb[*sb.begin()];
        sb.erase(sb.begin()); 
        wb[++cntb] = 1;
        while(!sb.empty() && plc <= *sb.rbegin()){
            int jud = *sb.lower_bound(plc);
            sb.erase(jud); 
            wb[cntb]++, plc = mpb[jud];
        }
    }
    for(int i = 1; i <= cnta; i++) wa[i] = wa[i] + wa[i-1];
    for(int i = 1; i <= cntb; i++) wb[i] = wb[i] + wb[i-1];
    for(int i = 0; i <= min(n, cnta); i++){
        if(n-i >= cntb) ans = max(wa[i], wb[cntb]);
        else ans = max(ans, wa[i]+wb[n-i]);
    } 
    printf("%d\n", ans);
    return 0;
}
