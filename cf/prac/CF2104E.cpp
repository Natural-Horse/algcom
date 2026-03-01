// clang-format off
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

inline int read(){
    int x = 0, f = 1; char ch = getcahr();
    while(!isdigit(ch)){if(ch == '-') f = -1; ch = getchar();}
    while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - 48; ch = getchar();}
    return x * f;
}

const int N = 1e6 + 5;

struct Tr{
    int plc[30][2];
    int l, r, siz;
}tr[N << 4];

int n, k, q;
string s, t;

void build(int u, int l, int r){
    tr[u].l = l, tr[u].r = r, tr[u].siz = r - l + 1;
    for(int i = 1; i <= k; i++) tr[u].plc[i][0] = inf, tr[u].plc[i][1] = -1;
    if(l == r){
        tr[u].plc[s[l - 1] - 'a' + 1][0] = tr[u].plc[s[l - 1] - 'a' + 1][1] = l;
        return;
    }
    int na = u << 1, nb = na | 1;
    int mid = (l + r) >> 1;
    build(na, l, mid);
    build(nb, mid + 1, r);
    for(int i = 1; i <= k; i++){
        tr[u].plc[i][0] = min(tr[u].plc[i][0], min(tr[na].plc[i][0], tr[nb].plc[i][0]));
        tr[u].plc[i][1] = max(tr[u].plc[i][1], max(tr[na].plc[i][1], tr[nb].plc[i][1]));
    }
}

int plc_min = inf, plc_max = -1;
void qr_plc_min(int u, int st, int re, int ch){
    int l = tr[u].l, r = tr[u].r;
    if(l > re || r < st) return;
    if(l >= st && r <= re){
        plc_min = min(plc_min, tr[u].plc[ch][0]);
        return;
    }
    qr_plc_min(u << 1, st, re, ch);
    qr_plc_min(u << 1 | 1, st, re, ch);
}

void qr_plc_max(int u, int st, int re, int ch){
    int l = tr[u].l, r = tr[u].r;
    if(l > re || r < st) return;
    if(l >= st && r <= re){
        plc_max = max(plc_min, tr[u].plc[ch][1]);
        return;
    }
    qr_plc_max(u << 1, st, re, ch);
    qr_plc_max(u << 1 | 1, st, re, ch);
}

int main(){
    n = read(), k = read();
    cin >> s;
    q = read();
    while(q--){
        cin >> t;
        int plc_tmp = 1;
        int ans = 0;
        for(int i = 0; i < t.size(); i++){
            qr_plc_min(1, plc_tmp, n, t[i]-'a'+1);
            plc_tmp = plc_min + 1;
            if(plc_tmp > n) break;
            plc_min = inf;
        }
        for(; plc_tmp <= n; ans++){
            
        }
    }
    
}