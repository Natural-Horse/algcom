#include<bits/stdc++.h>
using namespace std;
#define re register int
const int N=1e7+5;
int n,k,w;
int prime[N],cnt;
bitset<N*18> vis;
int s1[N],s2[N];
double ans;
int now[N],sum[N*2];
signed main(){
	scanf("%d%d%d",&n,&k,&w);
	for(re i=2;cnt<=n;i++){
		if(!vis[i])prime[++cnt]=i;
		for(re j=1;j<=cnt&&prime[j]*i<=n*18;j++){
			vis[prime[j]*i]=1;
			if(i%prime[j]==0)break;
		}
	}
	for(re i=1;i<=n;i++)s1[i]=1ll*i*prime[i]%w;
	for(re i=1;i<=n;i++)s2[i]=s1[i]+s1[i/10+1];
	for(int i = 1; i <= n; i++) printf("%d ", s1[i]);
	printf("\n");
	for(int i = 1; i <= n; i++) printf("%d ", s2[i]);
	printf("\n");
	if(k&1){
		for(re i=1;i<=k;i++)sum[s2[i]]++,now[i]=s2[i];
		sort(now+1,now+k+1);
		int mid=now[k+1>>1],rak=0;
		for(re i=1;i<=k;i++)
			if(now[i]<=mid)rak++;
		ans+=mid;
		for(re i=2;i<=n-k+1;i++){
			if(s2[i-1]<=mid)rak--;
			if(s2[i+k-1]<=mid)rak++;
			sum[s2[i-1]]--;
			sum[s2[i+k-1]]++;
			while(rak-sum[mid]>=(k+1>>1))rak-=sum[mid],mid--;
			while(rak+sum[mid+1]<(k+1>>1))rak+=sum[mid+1],mid++;
			if(rak<(k+1>>1))mid++,rak+=sum[mid];
			ans+=mid;
		}
	}
	else{
		for(re i=1;i<=k;i++)now[i]=s2[i],sum[s2[i]]++;
		sort(now+1,now+k+1);
		int m1,r1=0,m2,r2=0;
		m1=now[k>>1];m2=now[k+2>>1];
		for(re i=1;i<=k;i++){
			if(now[i]<=m1)r1++;
			if(now[i]<=m2)r2++;
		}
		//cout<<r2<<endl;
		ans+=(m1+m2)*1.0/2.0;
		for(re i=2;i<=n-k+1;i++){
			//cout<<i<<endl;
			sum[s2[i-1]]--;
			sum[s2[i+k-1]]++;
			if(s2[i-1]<=m1)r1--;
			if(s2[i-1]<=m2)r2--;
			if(s2[i+k-1]<=m1)r1++;
			if(s2[i+k-1]<=m2)r2++;
			while(r1-sum[m1]>=(k>>1))r1-=sum[m1],m1--;
			while(r1+sum[m1+1]<(k>>1))r1+=sum[m1+1],m1++;
			if(r1<(k>>1))m1++,r1+=sum[m1];
			while(r2-sum[m2]>=(k+2>>1))r2-=sum[m2],m2--;
			while(r2+sum[m2+1]<(k+2>>1))r2+=sum[m2+1],m2++;//cout<<r2<<endl;
			if(r2<(k+2>>1))m2++,r2+=sum[m2];
			ans+=(m1+m2)*1.0/2.0;
		}
	}
	printf("%.1lf",ans);
}
