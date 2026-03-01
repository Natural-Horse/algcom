#include<bits/stdc++.h>
#define maxn 200005
using namespace std;
const int inf = 2e9+1;
int n,p[maxn],c[maxn],mx[maxn<<2],val[maxn<<2],vl[maxn<<2];
int calc(int i,int l,int r,int d){
    if(l==r) return mx[i]>d?val[i]:inf;
    int mid=(l+r)>>1;
    if(mx[i<<1|1]<=d) return calc(i<<1,l,mid,d);
    else return min(vl[i],calc(i<<1|1,mid+1,r,d));
}
void insert(int i,int l,int r,int p,int id,int v){
    if(l==r) {mx[i]=id,val[i]=v;return;}
    int mid=(l+r)>>1;
    if(p<=mid) insert(i<<1,l,mid,p,id,v);
    else insert(i<<1|1,mid+1,r,p,id,v);
    mx[i]=max(mx[i<<1],mx[i<<1|1]),vl[i]=calc(i<<1,l,mid,mx[i<<1|1]);
}
int id,v;
void query(int i,int l,int r,int p){
    if(r<=p) {v=min(v,calc(i,l,r,id)),id=max(id,mx[i]);return;}
    int mid=(l+r)>>1;
    if(mid<p) query(i<<1|1,mid+1,r,p);
    query(i<<1,l,mid,p);
}
int main()
{	
	freopen("sample.in", "r", stdin);
	freopen("answer.out", "w", stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&p[i]);
    for(int i=1;i<=n;i++) scanf("%d",&c[i]);
    for(int i=1;i<=n*4;i++) vl[i]=inf;
    for(int i=1;i<=n;i++){
        id=0,v=inf,query(1,1,n,p[i]);
        insert(1,1,n,p[i],i,(v<inf?v:0)+c[i]);
    }
    id=0,v=inf,query(1,1,n,n);
    printf("%d\n",v);
}

