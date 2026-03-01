#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

const int Maxn = 1e5 + 5;

struct Num{
	int d, val;
}num[Maxn];

int n;
int a[Maxn];
int nxt[Maxn], p[Maxn];
int b = inf, w = inf;
int headb, headw;
int ans;

bool cmp(Num aa, Num bb){
	return aa.val < bb.val;
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		num[i].d = i, num[i].val = a[i];
		nxt[i] = inf;
	} 
	sort(num + 1, num + 1 + n, cmp);
	for(int i = 1; i <= n; i++){
		int cnt = 0;
		memset(p, 0, sizeof(p));
		p[++cnt] = num[i].d;
		i++;
		while(num[i].val == num[i-1].val){
			p[++cnt] = num[i].d;
			i++;
		}
		sort(p + 1, p + 1 + cnt);
		for(int j = 1; j <= cnt; j++) nxt[p[j]] = p[j+1];
		nxt[p[cnt]] = inf;
		i--;
	}
	for(int i = 1; i <= n; i++){
		if(a[i] == headw) w = nxt[i];
		else if(a[i] == headb) b = nxt[i];
		else{
			if(w <= b) headb = a[i], b = nxt[i];
			else headw = a[i], w = nxt[i];  
			ans++;
		}
	}
	printf("%d", ans);
	return 0;
} 
