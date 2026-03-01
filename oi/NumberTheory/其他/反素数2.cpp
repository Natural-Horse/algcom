#include<bits/stdc++.h>
#define inf 2e9
#define ll long long
using namespace std;

ll n;
ll ansm = inf, anscnt;
ll state[15] = {0, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 2};

inline void dfs(ll a, ll all, ll now, ll pre){
	if(a*2 >= n || now > 10){
		if((a <= ansm && all >= anscnt) || all > anscnt){
			ansm = a, anscnt = all; 			
		}
		return;
	}
	for(register int i = 1; i <= pre; i++){
		a *= state[now];
		if(a > n){
			a /= state[now];
			break;
		}
		all *= (i+1);
		all /= i;
		if(a <= n){
			dfs(a, all, now+1, i);
		}
	}	
}

int main(){
	scanf("%lld", &n);
	dfs(1, 1, 1, 31);
	printf("%lld", ansm);
}
