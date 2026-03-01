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

int n, a[N], tmp[N];
int tot, siz[N], sum[N][2], ch[N][2], d[N], sep[N];
ll ans;

void insert(){
    int u = 0; 
    for(int i = 30; i; --i){
        if(!ch[u][tmp[i]]) ch[u][tmp[i]] = ++tot;
        int fa = u; 
        u = ch[u][tmp[i]], d[u] = d[fa] + 1;
        ans += (siz[ch[fa][tmp[i]^1]]-1) * siz[ch[fa][tmp[i]^1]] / 2;
        ans += siz[ch[fa][tmp[i]^1]] * (sum[d[u]][tmp[i]^1] - siz[ch[fa][tmp[i]^1]]) - sep[ch[fa][tmp[i]^1]];
        sep[u] += sum[d[u]][tmp[i]] - siz[u];
        siz[u]++, sum[d[u]][tmp[i]]++;
    }
}

int main(){
    freopen("xor2.in", "r", stdin);
    n = read();
    for(int i = 1; i <= n; i++){
        a[i] = read();
        for(int j = 1; j <= 30; ++j) tmp[j] = (a[i] & (1 << (j-1))) >> (j-1);
        insert();
    }
    printf("%d\n", ans);
    return 0;
}

