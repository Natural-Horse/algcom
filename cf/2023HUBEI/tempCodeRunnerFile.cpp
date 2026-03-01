#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

inline int read(){
    int x = 0, f = 1; char ch = getchar();
    while(!isdigit(ch)){if(ch == '-') f = -1; ch = getchar();}
    while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - 48; ch = getchar();}
    return x * f;
}

const int N = 2e6 + 5;

struct Tr{
    int l, r;
    int lmax, rmax;
    int mmax, dev;
}tr[2][N<<2];
int T, a[N], n;
bool b[N];
bool ans;

void build(int u, int l, int r){
    if(l == r){
        int jud = 0;
        if(l > 1 && a[l-1] != a[l]) jud++;
        if(l < n && a[l+1] != a[l]) jud++;
        tr[a[l]][u].lmax = tr[a[l]][u].rmax = tr[a[l]][u].mmax = jud - 1;
        tr[a[l]^1][u].lmax = tr[a[l]^1][u].rmax = tr[a[l]^1][u].mmax = tr[a[l]^1][u].dev = tr[a[l]][u].dev = -inf;
        return;
    }
    tr[0][u].lmax = tr[0][u].rmax = tr[0][u].mmax = tr[0][u].dev = -inf;
    tr[1][u].lmax = tr[1][u].rmax = tr[1][u].mmax = tr[1][u].dev = -inf;
    int mid = (l + r) >> 1, na = u << 1, nb = na | 1;
    build(na, l, mid), build(nb, mid+1, r);
    
}

int main(){
    T = read();
    while(T--){
        n = 0;
        char ch = getchar();
        while(isdigit(ch)){
            a[++n] = ch - '0';
            b[n] = true;
            ch = getchar();
        }
        
        
    }
    return 0;
}