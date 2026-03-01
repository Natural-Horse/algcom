#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

int read(){
	int x = 0,f = 1;char ch = getchar();
	while (ch < '0' || ch > '9'){if (ch == '-') f = -1; ch = getchar();}
	while (ch >= '0' && ch <= '9'){x = x*10 + ch - 48; ch = getchar();}
	return x * f;
}

const int N = 3e5 + 5;
int n, p;
int a[N], f[N][35], lg[N], plc[N][35]; 
vector<int> fir[N], las[N];
ll x[N*30], ans[N*30], pre[N], num, b[1000005];
ll fnans;

void init(){
	for(int i = 1; i <= n; i++) lg[i] = lg[i-1] + (1<<(lg[i-1]+1)==i);
	for(int i = 1; i <= lg[n]; i++){
		for(int j = 1; j <= n-(1<<i)+1; j++){		 
			if(f[j][i-1] > f[j+(1<<(i-1))][i-1]) 
				f[j][i] = f[j][i-1],plc[j][i] = plc[j][i-1];
			else 
				f[j][i] = f[j+(1<<(i-1))][i-1], plc[j][i] = plc[j+(1<<(i-1))][i-1];	
		} 
	}
}
int query_maxn(int st, int re){
	int len = lg[re-st+1];
	return f[st][len] > f[re-(1<<len)+1][len]? plc[st][len]: plc[re-(1<<len)+1][len];
}
void get_query(int st, int re){
	if(st >= re) return;
	int k = query_maxn(st, re);
	if(k - st > re - k){
		for(int i = k+1; i <= re; i++){
			x[++num] = (pre[i] - a[k] % p) % p;
//			if(i != k && x[num]==0) fnans++;
			fir[st-1].push_back(num), las[k].push_back(num);		
		}
		x[++num] = 0;
		fir[st-1].push_back(num), las[k-1].push_back(num);
	}
		
	else{
		for(int i = st; i < k; i++){
			x[++num] = (pre[i] + a[k] % p) % p;
//			if(i != k && x[num]==0) fnans++;
			fir[k-1].push_back(num), las[re].push_back(num);
		}
		x[++num] = 0;
		fir[k].push_back(num), las[re].push_back(num);
	}
		
	get_query(st, k-1), get_query(k+1, re);
}

int main(){
	n = read(), p = read();
	for(int i = 1; i <= n; i++){
		a[i] = read();
		pre[i] = (pre[i-1]+a[i]) % p;
		f[i][0] = a[i], plc[i][0] = i;
	} 
	init();
	get_query(1, n);
	for(int i = 0; i <= n; i++){
		if(i != 0) b[pre[i]]++;
		for(int j = 0; j < fir[i+1].size(); j++) ans[fir[i+1][j]] -= b[x[fir[i+1][j]]];
		for(int j = 0; j < las[i].size(); j++) ans[las[i][j]] += b[x[las[i][j]]];
	}
	for(int i = 1; i <= num; i++) fnans += ans[i];
	printf("%lld", fnans);
}
