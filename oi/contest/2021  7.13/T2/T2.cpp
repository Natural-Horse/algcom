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

const int N = 1e6 + 5;
struct Node{
	int num, val;
	bool operator < (const Node &x) const{
		return val < x.val;
	}
};
int n, a, b;
int link[N][2];
int siz[N];
ll val[N];
double v[N];
bool check[N];
ll ans;

int main(){
	n = read(), a = read(), b = read();
	for(int i = 1; i <= n; i++){
		link[i][0] = read(), link[i][1] = read();
		siz[link[i][0]]++, siz[link[i][1]]++;
		val[link[i][0]] += a, val[link[i][1]] += b;
	}  
	for(int i = 1; i <= n; i++){
		v[i] = (double)val[i] / siz[i];
	}
	for(int i = 1; i <= n; i++){
		if(!check[link[i][0]] && !check[link[i][1]])
			if(v[link[i][0]] > v[link[i][1]]){
				check[link[i][1]] ^= 1,ans+=val[link[i][1]];
			}
			else{
				check[link[i][0]] ^= 1, ans+=val[link[i][0]];
			} 
	}
	printf("%lld", ans);
	return 0;
}

