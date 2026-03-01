#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define int long long
#define re register
using namespace std;
const int MAXN=2e5+5;
int m,a[MAXN<<1],tot=0,cnt;
struct node{
    int l,r,opt;
}ch[MAXN];
struct TREE{
    int l,r,sum,laz,flag;
}tr[MAXN<<2];
void build(int k,int l,int r){
    tr[k].l=l,tr[k].r=r,tr[k].laz=-1,tr[k].sum=0;
    if(l==r) return ;
    int mid=(l+r)>>1;
    build(k<<1,l,mid),build(k<<1|1,mid+1,r);
}
void pushup(int k){
    tr[k].sum=tr[k<<1].sum+tr[k<<1|1].sum;
}
void down(int k){
    int l=tr[k].l,r=tr[k].r,mid=(l+r)>>1;
    if(tr[k].laz!=-1){
        tr[k<<1].laz=tr[k<<1|1].laz=tr[k].laz;
        tr[k<<1].sum=tr[k].laz*(mid-l+1),tr[k<<1|1].sum=tr[k].laz*(r-mid);
        tr[k<<1].flag=tr[k<<1|1].flag=0;
        tr[k].laz=-1;
    }
    if(tr[k].flag){
        tr[k<<1].flag^=1;
        tr[k<<1|1].flag^=1;
        tr[k].flag=0;
        tr[k<<1].sum=(mid-l+1)-tr[k<<1].sum;
        tr[k<<1|1].sum=(r-mid)-tr[k<<1|1].sum;
    }
}
void change(int k,int opl,int opr,int val){
    int l=tr[k].l,r=tr[k].r;
    if(opl<=l&&r<=opr){
        tr[k].sum=val*(r-l+1);
        tr[k].laz=val;
        tr[k].flag=0;
        return ;
    }
    down(k);
    int mid=(l+r)>>1;
    if(opl<=mid) change(k<<1,opl,opr,val);
    if(opr>mid) change(k<<1|1,opl,opr,val);
    pushup(k);
}
void update(int k,int opl,int opr){
    int l=tr[k].l,r=tr[k].r;
    if(opl<=l&&r<=opr){
        tr[k].flag^=1;
        tr[k].sum=(r-l+1)-tr[k].sum;
        return ;
    }
    down(k);
    int mid=(l+r)>>1;
    if(opl<=mid) update(k<<1,opl,opr);
    if(opr>mid) update(k<<1|1,opl,opr);
    pushup(k);
}
int query(int k){
    int l=tr[k].l,r=tr[k].r;
    if(l==r) return l;
    down(k);
    int mid=(l+r)>>1;
    if(tr[k<<1].sum<(mid-l+1)) return query(k<<1);
    else return query(k<<1|1);
}
signed main(){
//	freopen("sample.in", "r", stdin);
//	freopen("answer.out", "w", stdout);
    scanf("%lld",&m);
    a[++tot]=1;
    for(re int i=1;i<=m;++i){
        scanf("%lld%lld%lld",&ch[i].opt,&ch[i].l,&ch[i].r);
        a[++tot]=ch[i].l,a[++tot]=ch[i].r+1;
    }
    sort(a+1,a+tot+1);
    cnt=unique(a+1,a+tot+1)-a-1;
    build(1,1,cnt);
    for(int i=1;i<=m;++i){
        ch[i].l=lower_bound(a+1,a+cnt+1,ch[i].l)-a;
        ch[i].r=lower_bound(a+1,a+cnt+1,ch[i].r+1)-a-1;
        if(ch[i].opt==1) change(1,ch[i].l,ch[i].r,1);
        else if(ch[i].opt==2) change(1,ch[i].l,ch[i].r,0);
        else update(1,ch[i].l,ch[i].r);
        printf("%lld\n",a[query(1)]);
    }
    return 0;
}
