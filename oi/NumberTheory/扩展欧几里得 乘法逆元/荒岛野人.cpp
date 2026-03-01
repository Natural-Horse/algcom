#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

const int Maxn = 1e3;

int n;
int st[Maxn+5], v[Maxn+5], l[Maxn+5];
int maxn;

int exgcd(int a, int b, int &x, int &y){
	if(b == 0){
		x = 1, y = 0;
		return a;
	}
	int d = exgcd(b, a%b, x, y);
	int jud = x;
	x = y, y = jud - y * (a/b);
	return d;
}

bool check(int x){
	for(int i = 1; i < n; i++){
		for(int j = i + 1; j <= n; j++){
			int va = v[i], vb = v[j];
			int ansa = 0, ansb = 0;
			int s = 0, d = 0;
			if(va > vb){
				s = st[j] - st[i];
				d = exgcd(va-vb, x, ansa, ansb);
			}
			else{
				s = st[i] - st[j];
				d = exgcd(vb-va, x, ansa, ansb);
			}
			if(s % d != 0) continue;
			ansa *= (s/d);
			if(ansa < 0){
				ansa = -ansa;
				ansa = (x/d) - (ansa % (x/d));
			}
			else ansa %= (x/d);
			if(ansa <= l[i] && ansa <= l[j]) return false;
		}
	}
	return true;
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d %d %d", &st[i], &v[i], &l[i]);
		maxn = max(st[i], maxn);
	}
	if(n == 1){
		printf("1");
		return 0;
	}
	for(int i = maxn; i <= 1e6; i++){
		if(check(i)){
			printf("%d", i);
			return 0;
		}
	}
} 
