#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;

int n,m;
char a[55][55];
vector<int> sf,hr,bl;

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%s",a[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]=='*'){
				bl.push_back((i-1)*m+j);
			}
			if(a[i][j]=='#'){
				hr.push_back((i-1)*m+j);
			}
			if(a[i][j]=='x'){
				sf.push_back((i-1)*m+j);
			}
		}
	}
	for(int i=0;i<bl.size();i++){
		
	}
}
