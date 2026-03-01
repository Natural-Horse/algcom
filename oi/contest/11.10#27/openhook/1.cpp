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

const int N = 1e6 + 5;

int n, a[N], b[N], ls[N], tot, num, p[N], len[N]; 
ull ans;
vector<int> vec[N];
queue<int> q;

bool cmp(int aa, int bb){
    return aa > bb;
}

int main(){
    freopen("sample_openhook4.in", "r", stdin);
//    freopen("1.out", "w", stdout);
    n = read();
    for(int i = 1; i <= n; i++){
        a[i] = read();
        ls[++tot] = a[i];
    }
    sort(ls + 1, ls + 1 + n);
    num = unique(ls + 1, ls + 1 + n) - ls - 1;
    for(int i = 1; i < num; i++) p[i] = ls[i+1] - ls[i];
    p[num] = inf;
    for(int i = 1; i <= n; i++){
        a[i] = lower_bound(ls + 1, ls + 1 + num, a[i]) - ls;
        vec[a[i]].push_back(i);
    }
    for(int i = 1; i <= n; i++) b[i] = read();
    int x = 1, y = 1;
    for(int i = 1; i <= num; i++){
        int sz = vec[i].size();
        if(sz == 1) continue;
        if(i > x) x = i, y = 1;
        while(p[x] == 1) x++;
        y = 1;
        for(int j = 0; j < sz-1; j++){
            len[vec[i][j]] = ls[x] + y - ls[i];
            if(y < p[x]) y++;
            else x++, y = 1;
        }
    }
    sort(len + 1, len + 1 + n);
    sort(b + 1, b + 1 + n, cmp);
    for(int i = 1; i <= n; i++){
        ans += (ull)b[i] * (ull)len[i];
    }
    printf("%llu\n", ans);
    return 0;
}

