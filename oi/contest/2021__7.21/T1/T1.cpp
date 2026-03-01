#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;
//É¾ÁËfreopen£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡ 
int read(){
	int x = 0,f = 1;char ch = getchar();
	while (ch < '0' || ch > '9'){if (ch == '-') f = -1; ch = getchar();}
	while (ch >= '0' && ch <= '9'){x = x*10 + ch - 48; ch = getchar();}
	return x * f;
}
const int N = 1e5 + 5;

struct Rec{
	ll a, b, id;
}r[N];

struct Node{
	ll aa;
	bool operator < (const Node &x) const{
		return aa > x.aa;
	}
};

int n, m, T;
priority_queue<Node> q;
ll ans;

bool cmp(Rec aa, Rec bb){
	return aa.a < bb.a;
}
             //É¾ÁËfreopen£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡ 
int main(){  //É¾ÁËfreopen£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡ 
//	freopen("d2.in", "r", stdin);
//	freopen("1", "w", stdout);
	T = read();
	for(int ii = 1; ii <= T; ii++){
		ans = 0;
		n = read(), m = read();
		for(int i = 1, a, b; i <= n; i++){
			a = read(), b = read();
			r[i] = ((Rec){a, b, i});
		}
		sort(r + 1, r + 1 + n, cmp);
		while(!q.empty()) q.pop();
		for(int i = m + 1; i <= n; i++){
			q.push((Node){r[i].b});
		}
		for(int i = m; i >= 0; --i){
			Node bb = q.top();q.pop();
			ll x = bb.aa;
			ans = max(ans, r[i+1].a * x);
			if(i) q.push((Node){r[i].b});
		}
		printf("%lld\n", ans);
	}
	return 0;
}
