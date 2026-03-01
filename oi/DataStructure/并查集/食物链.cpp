#include<bits/stdc++.h>
using namespace std;

int n,k;
int fa[150005];
int cnt;

int find(int x){
	if(fa[x]==x) return x;
	else return fa[x]=find(fa[x]);
}

void merge(int x,int y){
	fa[find(x)]=find(y);
}

int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=3*n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=k;i++){
		int opt,x,y;
		scanf("%d %d %d",&opt,&x,&y);
		if(opt==2&&x==y){
			cnt++;
			continue;
		}
		if(x>n||y>n){
			cnt++;
			continue;
		}
		if(opt==1){
			if(find(x)!=find(y)){
				cnt++;
				continue;
			}
			else merge(x,y);
		} 
		else{
			if(find(x+2*n)==find(y)||find(x)==find(y)){
				cnt++;
				continue;
			}
			else{
				merge(x+n,y);
			merge(y+2*n,x);
			}
			
		}
	}
	printf("%d",cnt);
	return 0;
} 
