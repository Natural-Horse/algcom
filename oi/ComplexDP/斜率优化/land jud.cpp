#include <cstdio>
#include <algorithm>

const int N=5e4+5;
int n,q[N];
long long f[N];
struct Land {
	int x,y;
	bool operator < (const Land &b) const {
		return x==b.x?y>b.y:x>b.x;
	}
} a[N];

void init() {
	std::sort(a+1,a+n+1);
	int m=0;
	for(int i=1;i<=n;++i) if(a[i].y>a[m].y) a[++m]=a[i];
	n=m;
}
double slope(int i,int j) {
	return 1.0*(f[i]-f[j])/(a[j+1].x-a[i+1].x);
}
int main() {
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d%d",&a[i].x,&a[i].y);
	init();
	int l=1,r=0;
	q[++r]=0;
	for(int i=1;i<=n;++i) {
		while(l<r&&slope(q[l],q[l+1])<=a[i].y) ++l;
		f[i]=f[q[l]]+1LL*a[q[l]+1].x*a[i].y;
		while(l<r&&slope(q[r-1],q[r])>=slope(q[r],i)) --r;
		q[++r]=i;
	}
	printf("%lld\n",f[n]);
	return 0;
}
