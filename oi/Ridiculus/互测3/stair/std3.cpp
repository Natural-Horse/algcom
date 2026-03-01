#include <bits/stdc++.h>
using namespace std;
#define For(i,x,y,...) for(int i=x,##__VA_ARGS__;i<=int(y);++i)
#define rFor(i,x,y,...) for(int i=x,##__VA_ARGS__;i>=int(y);--i)
#define mem(a,x,n) memset(a,x,sizeof(a[0])*(n+1))
#define pb emplace_back
#define MP make_pair
#define fi first
#define se second
typedef long long LL; typedef unsigned long long ULL; typedef long double LD;
typedef pair<int,int> PII; typedef vector<int> VI;
char buf[1<<20],*p1=buf,*p2=buf,pbuf[1<<20],*pp=pbuf;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin),p1==p2)?EOF:*p1++)
#define iocl() fwrite(pbuf,1,pp-pbuf,stdout),pp=pbuf,0
#define putchar(x) pp-pbuf==1<<20&&(iocl()),*pp++=x
template<typename T>void read(T &x){
	x=0;bool f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=0;
	if(f)for(;isdigit(c);c=getchar())x=x*10+c-48;
	else for(;isdigit(c);c=getchar())x=x*10-c+48;
}
template<typename T,typename ...Args>void read(T &x, Args &...args)
	{ read(x),read(args...); }
template<typename T>void write(T x,char y=10) {
	if(!x)putchar(48);
	else{static int s[21];int l=0;if(x<0)putchar('-'),x=-x;
		for(;x;x/=10)s[l++]=x%10;while(l)putchar(s[--l]|48);}
	putchar(y);
}
template<typename T>void ckmax(T &x,T y) { if( y > x ) x = y; }
template<typename T>void ckmin(T &x,T y) { if( y < x ) x = y; }

const int N = 2e5+5;
int n,q,k,a[N];

int mx,lsh[N],rt[N];
LL ans;

#define ls(u) t[u].ls
#define rs(u) t[u].rs
#define mid ((l+r)>>1)
#define lson ls(u),l,mid
#define rson rs(u),mid+1,r
namespace hjt {
int ind;
struct Node { int ls,rs,siz; } t[N<<7];
void insert(int p,int x,int &u,int l=1,int r=mx) {
	if( !u ) u = ++ind;
	t[u].siz += x;
	if( l == r ) return;
	p <= mid ? insert(p,x,lson) : insert(p,x,rson);
}
int query(int ql,int qr,int u,int l=1,int r=mx) {
	if( !u || qr < l || r < ql ) return 0;
	if( ql <= l && r <= qr ) return t[u].siz;
	return query(ql,qr,lson) + query(ql,qr,rson);
}
}
#undef ls
#undef rs
#undef mid
#undef lson
#undef rson

void add(int i,int p,int x) { for(; i <= n; i += i&-i) hjt::insert(p,x,rt[i]); }
int query(int l,int r,int ql,int qr) {
	if( l > r || ql > qr ) return 0;
	int res = 0;
	for(--l; r > l; r -= r&-r) res += hjt::query(ql,qr,rt[r]);
	for(; l > r; l -= l&-l) res -= hjt::query(ql,qr,rt[l]);
	return res;
}

signed main() {
	//freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	read(n,q,k);
	For(i,1,n) read(a[i]), lsh[i] = a[i];
	sort(lsh+1,lsh+n+1), mx = unique(lsh+1,lsh+n+1)-lsh-1;
	For(i,1,n) {
		a[i] = lower_bound(lsh+1,lsh+mx+1,a[i])-lsh;
		ans += query(1,i-1,a[i]+1,mx);
		add(i,a[i],1);
	}
	write(ans);
	while( q-- ) {
		int l0,r0,l,r; read(l0,r0); l = ((l0^(ans*k))+r0*k-1)%n+1, r = ((r0^(ans*k))+l0*k-1)%n+1;
		if( l > r ) swap(l,r);
		if( l == r ) { write(ans); continue; }
		ans -= query(l+1,r-1,a[r]+1,mx) + query(l+1,r-1,1,a[l]-1);
		add(l,a[l],-1), add(r,a[r],-1);
		if(a[l] < a[r]) ans++;
		else if(a[l] > a[r]) ans--;
        swap(a[l],a[r]);
		add(l,a[l],1), add(r,a[r],1);
		ans += query(l+1,r-1,1,a[l]-1) + query(l+1,r-1,a[r]+1,mx);
		write(ans);
	}
	return iocl();
}
