#include<cstdio>
#include<string>
#include<cmath>
using namespace std;
const int maxn=100005;
int n,ans,a[maxn],f[maxn];
void doit(int x){
	int sq=sqrt(x),sum=0,y=x;
	for (int i=2;i<=sq;i++)
	if (x%i==0){
		sum=max(max(sum,f[i]),f[x/i]);
	}
	sum=max(sum,f[x]);
	x=y;
	for (int i=2;i<=sq;i++)
	if (x%i==0){
		f[i]=sum+1,f[x/i]=sum+1;
		while (x%i==0) x/=i;
	}
	f[x]=sum+1;
	ans=max(ans,sum+1);
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) doit(a[i]);
	printf("%d\n",ans);
	return 0;
}
