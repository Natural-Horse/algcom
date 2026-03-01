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
int la, lb, nxt[Maxn], lst[Maxn]; 
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
	nxt[0] = inf;
	for(int i = 1; i <= n; i++) lst[a[i]] = inf;
	for(int i = n; i >= 1; i--){
		nxt[i] = lst[a[i]];
		lst[a[i]] = i;
	}
	for(int i = 1; i <= n; i++){
		if(a[i] != a[la] && a[i] != a[lb]){
			ans++;
			if(nxt[la] >= nxt[lb]) lb = i;
			else la = i;
		}
		else if(a[i] != a[la]) ans++, la = i;
		else if(a[i] != a[lb]) ans++, lb = i;
		else la = lb = i;
	}
	printf("%d", ans);
	return 0;
} 
