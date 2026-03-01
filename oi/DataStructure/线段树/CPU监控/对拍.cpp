#include<cstdio>
#include<algorithm>
using namespace std;
#define lc k<<1
#define rc k<<1|1
#define ls lc,l,mid
#define rs rc,mid+1,r
const int MAXN=1e5+5,INF=0x7fffffff;
int n,m;
int a[MAXN];
int mx[MAXN<<2],mxh[MAXN<<2];
int tagp[MAXN<<2],tagc[MAXN<<2];	//常规tag
int htagp[MAXN<<2],htagc[MAXN<<2];
inline void pushup(int k){
	mx[k]=max(mx[lc],mx[rc]);
	mxh[k]=max(mxh[lc],mxh[rc]);
}
void Build(int k,int l,int r){
	tagc[k]=INF;	//赋值标记为INF表示没有赋值操作
    htagc[k]=-INF;	//防止一直是负数
	if(l==r){
		mx[k]=mxh[k]=a[l];
		return ;
	}
	int mid=l+r>>1;
	Build(ls);
	Build(rs);
	pushup(k);
	return ;
}
inline void chg(int k,int v,int hv){
	mx[k]=v;
	mxh[k]=max(mxh[k],hv);
	tagc[k]=v;
	htagc[k]=max(htagc[k],hv);
}
inline void add(int k,int v,int hv){
	if(tagc[k]!=INF) return chg(k,tagc[k]+v,tagc[k]+hv);	//转区间赋值操作
	htagp[k]=max(htagp[k],hv+tagp[k]);
	tagp[k]+=v;
	mx[k]+=v;
	mxh[k]=max(mxh[k],mx[k]-tagp[k]+htagp[k]);
}
inline void pushdwn(int k){
	add(lc,tagp[k],htagp[k]);
	add(rc,tagp[k],htagp[k]);
	tagp[k]=htagp[k]=0;
	if(tagc[k]!=INF){	//如果有赋值标记
		chg(lc,tagc[k],htagc[k]);
		chg(rc,tagc[k],htagc[k]);
		tagc[k]=INF;
	}
}
int qx,qy,qv;
int Query(int k,int l,int r){
	if(qx<=l&&r<=qy) return mx[k];
	pushdwn(k);
	int mid=l+r>>1;
	int res=-INF;
	if(qx<=mid) res=max(res,Query(ls));
	if(mid<qy) res=max(res,Query(rs));
	return res;
}
int Queryh(int k,int l,int r){
	if(qx<=l&&r<=qy) return mxh[k];
	pushdwn(k);
	int mid=l+r>>1;
	int res=-INF;
	if(qx<=mid) res=max(res,Queryh(ls));
	if(mid<qy) res=max(res,Queryh(rs));
	return res;
}
void Modifyp(int k,int l,int r){  //plus
	if(qx<=l&&r<=qy) return add(k,qv,max(qv,0));
	pushdwn(k);
	int mid=l+r>>1;
	if(qx<=mid) Modifyp(ls);
	if(mid<qy) Modifyp(rs);
	pushup(k);
	return ;
}
void Modifyc(int k,int l,int r){  // change
	if(qx<=l&&r<=qy) return chg(k,qv,qv);
	pushdwn(k);
	int mid=l+r>>1;
	if(qx<=mid) Modifyc(ls);
	if(mid<qy) Modifyc(rs);
	pushup(k);
	return ;
}
int main(){
//	freopen("sample.in", "r", stdin);
//	freopen("ans.out", "w", stdout);
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
		scanf("%d",a+i);
	Build(1,1,n);
	scanf("%d",&m);
	while(m--){
		char opt[2];
		scanf("%s%d%d",opt,&qx,&qy);
		if(opt[0]=='Q') printf("%d\n",Query(1,1,n));
		else if(opt[0]=='A') printf("%d\n",Queryh(1,1,n));
		else{
			scanf("%d",&qv);
			if(opt[0]=='P') Modifyp(1,1,n);
			else Modifyc(1,1,n);
		}
	}
	return 0;
}
