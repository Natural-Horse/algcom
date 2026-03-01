#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e6+10,MAXM=2e5+10,p=4324321;
int k[MAXM],t[MAXN];
string s;
int qpow(int x,int y){
    int res=1;
    while(y){
        if(y&1)res=1ll*res*x%p;
        x=1ll*x*x%p;
        y>>=1;
    }
    return res;
}
int main(){
    int n,m;
    scanf("%d",&m);
    for(int i=0;i<m;i++)scanf("%d",k+i);
    scanf("\n");
    getline(cin,s);
    n=s.size();
    for(int i=0;i<n;i++)
        t[i]=qpow(k[i%m],s[i]);
    for(int i=0;i<n;i++)
        printf("%d ",t[i]);
}
