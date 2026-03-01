#include<bits/stdc++.h>
using namespace std;
#define Ri register
template<typename T>inline T read(Ri T&t)
{Ri T f=1;Ri char ch=getchar();t=0;
while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
while(ch>='0'&&ch<='9')t=t*10+ch-'0',ch=getchar();t*=f;return t;}
template<typename T,typename...Args>
inline void read(T&t,Args&...args)
{read(t);read(args...);}
const long long p=998244353,G=3,Gi=332748118;
inline long long power(long long x,long long k=p-2)
{
	long long re=1;
	for(;k;k>>=1,x=(x*x)%p)if(k&1)re=(re*x)%p;
	return re;
}
int rev[1600005];
void NTT(long long *f,int lim,int flag)
{
	for(int i=0;i<lim;i++)if(i<rev[i])swap(f[i],f[rev[i]]);
	long long wn,buf,tp;
	for(int len=1;len<lim;len<<=1)
	{
		wn=power(flag==1?G:Gi,(p-1)/(len<<1));
		for(int l=0;l<lim;l+=len<<1)
			for(int i=l,buf=1;i<l+len;i++,buf=(buf*wn)%p)
			{
				tp=(f[i+len]*buf)%p;
				f[i+len]=(f[i]-tp+p)%p;
				f[i]=(f[i]+tp)%p;
			}
	}
	if(flag==1)return;
	long long Inv=power(lim,p-2);
	for(int i=0;i<lim;i++)f[i]=f[i]*Inv%p;
}
void MUL(long long *A,long long *B,long long *g,int n,int m)
{
	static long long A_[1600005],B_[1600005];
	static int n_,m_;n_=n;m_=m;
	m=n+m;n=1;
	while(n<m)n<<=1; 
	for(int i=0;i<n_;i++)A_[i]=A[i];
	for(int i=0;i<m_;i++)B_[i]=B[i];
	for(int i=n_;i<n;i++)A_[i]=0;
	for(int i=m_;i<n;i++)B_[i]=0;
	for(int i=0;i<n;i++)rev[i]=(rev[i>>1]>>1)|((i&1)?n>>1:0);
	NTT(A_,n,1);NTT(B_,n,1);
	for(int i=0;i<n;i++)g[i]=A_[i]*B_[i]%p;
	NTT(g,n,0);
	for(int i=m;i<n;i++)g[i]=0;
}
void INV(long long *f,long long *g,int m)
{
	if(m==1)return g[0]=power(f[0],p-2),void();
	INV(f,g,(m+1)>>1);
	static long long f_[1600005];
	int n=1;while(n<(m<<1))n<<=1;
	for(int i=0;i<n;i++)rev[i]=(rev[i>>1]>>1)|((i&1)?n>>1:0),f_[i]=f[i];
	for(int i=m;i<n;i++)f_[i]=0;
	NTT(f_,n,1);NTT(g,n,1);
	for(int i=0;i<n;i++)g[i]=((2-g[i]*f_[i]%p+p)*g[i])%p;
	NTT(g,n,0);
	for(int i=m;i<n;i++)g[i]=0;
}
void Newton(long long * F,int n)
{
	if(n==1)return F[0]=1,void();
	static long long f[1600005];
	Newton(f,(n+1)>>1);
	static long long f_2_x[1600005],f_3_x[1600005];
	static long long f_x_2[1600005],f_x_3[1600005];
	MUL(f,f,f_2_x,n,n);
	MUL(f,f_2_x,f_3_x,n,n);
	memset(f_x_2,0,sizeof(f_x_2));
	memset(f_x_3,0,sizeof(f_x_3));
	for(int i=0;i*2<n;i++)f_x_2[i*2]=f[i];
	for(int i=0;i*3<n;i++)f_x_3[i*3]=f[i];
	static long long GF[1600005],G_F[1600005];
	static long long _3_f_x_2[1600005];
	for(int i=0;i<n;i++)
		_3_f_x_2[i]=f_x_2[i]*3%p;
	static long long f_3_f_x_2[1600005];
	MUL(_3_f_x_2,f,f_3_f_x_2,n,n);
	for(int i=1;i<n;i++)
		GF[i]=(f_3_x[i-1]+f_3_f_x_2[i-1]+f_x_3[i-1]*2)%p;
	GF[0]=6;
	for(int i=0;i<n;i++)
		GF[i]=(GF[i]-f[i]*6%p+p)%p;
	for(int i=1;i<n;i++)
		G_F[i]=(f_2_x[i-1]*3+f_x_2[i-1]*3)%p;
	G_F[0]=p-6;
	static long long Inv_G_F[1600005];
	memset(Inv_G_F,0,sizeof(Inv_G_F));
	INV(G_F,Inv_G_F,n);
	static long long Mul[1600005];
	MUL(GF,Inv_G_F,Mul,n,n);
//	printf("%lld\n",Mul[0]);
	for(int i=0;i<n;i++)
		F[i]=(f[i]-Mul[i]+p)%p;
}
void solve(long long * f,int n)
{
	static long long A[1600005];
	Newton(A,n);
	static long long A_x_2[1600005],A_x_3[1600005],A_x_4[1600005];
	for(int i=0;i*2<n;i++)
		A_x_2[i*2]=A[i];
	for(int i=0;i*3<n;i++)
		A_x_3[i*3]=A[i];
	for(int i=0;i*4<n;i++)
		A_x_4[i*4]=A[i];
	static long long A_x_2_A_2[1600005],A_x_2_2[1600005],A_4_x[1600005],A_x_3_A[1600005];
	MUL(A,A,A_4_x,n,n);
	MUL(A_4_x,A,A_4_x,n,n);
	MUL(A_4_x,A,A_4_x,n,n);
	MUL(A_x_2,A,A_x_2_A_2,n,n);
	MUL(A_x_2_A_2,A,A_x_2_A_2,n,n);
	MUL(A_x_2,A_x_2,A_x_2_2,n,n);
	MUL(A_x_3,A,A_x_3_A,n,n);
	for(int i=0;i<n;i++)
		f[i]=(A_4_x[i]+
			A_x_2_A_2[i]*6+
			A_x_2_2[i]*3+
			A_x_3_A[i]*8+
			A_x_4[i]*6)%p;
	long long Inv=power(24);
	for(int i=n-1;i>=1;i--)
		f[i]=f[i-1]*Inv%p;
	f[0]=1;
	static long long A_sub1[1600005],A_x_2_sub1[1600005],A_sub1_2[1600005];
	for(int i=0;i<n;i++)A_sub1[i]=A[i];
	A_sub1[0]=0;
	for(int i=0;i<n;i++)A_x_2_sub1[i]=A_x_2[i];
	A_x_2_sub1[0]=0;
	MUL(A_sub1,A_sub1,A_sub1_2,n,n);
	static long long Q[1600005];
	Inv=power(2);
	for(int i=0;i<n;i++)
		Q[i]=(A_sub1_2[i]+A_x_2_sub1[i])%p*Inv%p;
	for(int i=0;i<n;i++)
		f[i]=(f[i]-Q[i]+A_x_2[i]+p)%p; 
}
int main()
{
	int n;read(n);
	static long long f[1600005];
	solve(f,n+1);
	printf("%lld\n",f[n]);
	return 0;
}
