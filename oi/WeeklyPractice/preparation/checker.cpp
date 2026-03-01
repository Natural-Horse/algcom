
#include <bits/stdc++.h>
#define int long long
#define Get getchar()
inline void read (int &x){
	char c=Get; int w=1; x=0;
	while (!isdigit(c)) {if (c=='-') w=-1; c=Get;}
	while (isdigit(c)) {x=(x*10)+(c^48),c=Get;};
	x*=w;
}
using namespace std;
typedef long long ll;
int n,m,k,x,y,tot=0;
int a[100001],b[100001];
int q[200001][2];
//q[x][0]表示第x个1在此序列中的位置，q[x][1]表示第x个1在原序列中的下标
int f[201][100001];
int Q[100001];
int dp[10000001];
signed main(){
	read(n); read(m); read(k);
	for (int i=1;i<=m;++i) read(x),a[x]=1;
	for (int i=1;i<=k;++i) read(b[i]);
	for (int i=0;i<=n;++i) a[i]^=a[i+1]; //差分序列
	for (int i=0;i<=n;++i) if (a[i]) q[tot][0]=tot,q[tot][1]=i,tot++; //将所有1的位置保存在q数组中
	
   //---------------------SPFA & START-----------------------
	
	for (int i=0;i<tot;++i){ 
	    //这里的spfa每次转移时的权值为1，所以不需要记录该点是否已在队列内 
		for (int j=0;j<=n;++j) f[q[i][0]][j]=0x7FFFFFFF;
		f[q[i][0]][q[i][1]]=0;
		int l=1,r=1;
		Q[1]=q[i][1];
		while (l<=r) {
			int x=Q[l];
			for (int j=1;j<=k;++j) {
				if (x-b[j]>=0&&f[q[i][0]][x]+1<f[q[i][0]][x-b[j]]) {
					f[q[i][0]][x-b[j]]=f[q[i][0]][x]+1;
					r++; Q[r]=x-b[j];
				}
				if (x+b[j]<=n&&f[q[i][0]][x]+1<f[q[i][0]][x+b[j]]) {
					f[q[i][0]][x+b[j]]=f[q[i][0]][x]+1;
					r++; Q[r]=x+b[j];
				}
			}
			l++;
		}
	}
	
	//---------------------SPFA & END-----------------------
    
	memset(dp,127,sizeof(dp));
	dp[0]=0;
	int Mx=(1ll<<tot)-1;
	for (int i=0;i<=Mx;++i) {
		x=0; 
		while ((i>>x)&1ll) x++;
		for (y=x+1;y<tot;++y) if (!((i>>y)&1ll))  
			dp[i|(1ll<<x)|(1ll<<y)]=min(dp[i|(1ll<<x)|(1ll<<y)],dp[i]+f[x][q[y][1]]);
	}
	
	printf("%lld\n",dp[Mx]>1e9?-1:dp[Mx]); //-1千万不要忘辣！ 
}
