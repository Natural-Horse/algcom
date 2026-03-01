#include <bits/stdc++.h>
using namespace std;
#define For(i,x,y,...) for(int i=x,##__VA_ARGS__;i<=int(y);++i)
#define pb emplace_back
typedef unsigned long long ULL; typedef vector<int> VI;
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
	else{static int s[41];int l=0;if(x<0)putchar('-'),x=-x;
		for(;x;x/=10)s[l++]=x%10;while(l)putchar(s[--l]|48);}
	putchar(y);
}

const int N = 1e6+5;
int n,m,q,k;
ULL w[N];
VI l[N];

int B,deg[N];
ULL lstans,ans[N];
VI r[N];

signed main() {
	read(n,m,q,k);
	For(i,1,n) read(w[i]);
	For(i,1,m) { int x,y; read(x,y); l[x].pb(y), l[y].pb(x); }
	For(u,1,n) {
		sort(l[u].begin(),l[u].end());
		l[u].erase(unique(l[u].begin(),l[u].end()),l[u].end());
		deg[u] = l[u].size();
	} B = sqrt(*max_element(deg+1,deg+n+1));
	For(u,1,n) {
		for(int v : l[u]) {
			ans[u] += w[v];
			if( deg[v] > B ) r[u].pb(u);
		}
	}
	while( q-- ) {
		int op,u; ULL x; read(op,u,x); (x+=k*lstans)%=ULL(1e13);
		if( op == 1 ) {
			w[u] += x;
			for(int v : r[u]) ans[v] += x;
		} else {
			if( deg[u] <= B ) {
				lstans = 0;
				for(int v : l[u]) (lstans += w[v]) %=x;
			} else lstans = ans[u];
			write(lstans);
		}
	}
	return iocl();
}
