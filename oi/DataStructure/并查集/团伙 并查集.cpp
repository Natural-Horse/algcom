#include<bits/stdc++.h> 
using namespace std;

int n,m;
int fa[2005];
int ans;

int find(int x){
	if(fa[x]==x) return x;
	else return fa[x]=find(fa[x]);
}

void merge(int x,int y){
	fa[find(x)]=find(y);
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=2*n;i++){
		fa[i]=i;
	}
	ans=n;
	for(int i=1;i<=m;i++){
		char opt;
		int x,y;
		scanf("\n%c %d %d",&opt,&x,&y);
		if(y>x) swap(x,y);
		if(opt=='E'){
			if(find(x)!=find(y+n)){
				merge(x,y+n);
//				ans--;
			}
			if(find(y)!=find(x+n)){
				merge(y,x+n);
//				ans--;
			}
		}
		else{
			if(find(x)!=find(y)){
				merge(x,y);
				ans--;
			}
		}
	}
	printf("%d",ans);
	return 0;
}
