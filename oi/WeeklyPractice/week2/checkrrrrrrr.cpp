#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

const int Maxn = 1e5 + 5;

struct NXT{
	int d, v;
}g[Maxn];

int n;
int a[Maxn];
int heada, headb;
int nxta, nxtb, nxt[Maxn]; 
int tmp[Maxn], pt;
int ans;

bool cmp(NXT aa, NXT bb){
	return aa.v < bb.v;
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		g[i] = (NXT){i, a[i]};
	}
	sort(g + 1, g + 1 + n, cmp);
	for(int i = 1; i <= n; i++){
		pt = 0;
		i++;
		while(g[i].v == g[i-1].v){
			tmp[++pt] = g[i].d;
			i++;
		}
		i--;
		for(int j = 1; j <= pt; j++) nxt[tmp[j]] = tmp[j+1];
		nxt[tmp[pt]] = inf;
	} 
	heada = a[1], nxta = nxt[1];
	ans++;
	for(int i = 2; i <= n; i++){
		if(heada == a[i]){
			if(headb == a[i]) nxtb = nxt[i];
			else{
				headb = a[i];
				nxtb = nxt[i];
				ans++;
			}
		}
		else if(headb == a[i]){
			heada = a[i];
			nxta = nxt[i];
			ans++;
		}
		else{
			ans++;
			if(nxt[i] > nxta){
				if(nxt[i] <= nxtb){
					heada = a[i];
					nxta = nxt[i];
				}
				else{
					if(heada <= headb){
						heada = a[i];
						nxta = nxt[i];
					}
					else{
						headb = a[i];
						nxtb = nxt[i];
					}
				}
			}
			else{
				if(nxt[i] >= nxtb){
					headb = a[i];
					nxtb = nxt[i];
				}
				else{
					heada = a[i];
					nxta = nxt[i];
				}
			}
		}
	}
	printf("%d", ans);
	return 0;
} 
