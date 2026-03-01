#include<bits/stdc++.h>
#define inf 2e9
#define ll long long
using namespace std;

ll n;
ll ansm = inf, anscnt;
int s1, s2, s3, s4, s5, s6, s7, s8, s9, s10;

inline void dfs(int a, int all, int sum, int c1, int c2, int c3, int c4, int c5, int c6, int c7, int c8, int c9, int c10){
	
	if(a*2 > n){
		if((a <= ansm && all >= anscnt) || all > anscnt){
			ansm = a, anscnt = all;
			s1 = c1, s2 = c2, s3 = c3, s4 = c4, s5 = c5, s6 = c6, s7 = c7, s8 = c8, s9 = c9, s10 = c10;
			return;
		}
	}
	else{
		for(int i = 1; i <= 10; i++){
			if(i == 1 && a*2 <= n && c1 <= 30){
				dfs(a*2, all/(c1+1)*(c1+2), sum+1, c1+1, c2, c3, c4, c5, c6, c7, c8, c9, c10);
			}
			if(i == 2 && a*3 <= n && c2+1 <= c1){
				dfs(a*3, all/(c2+1)*(c2+2), sum+1, c1, c2+1, c3, c4, c5, c6, c7, c8, c9, c10);
			}
			if(i == 3 && a*5 <= n && c3+1 <= c2){
				dfs(a*5, all/(c3+1)*(c3+2), sum+1, c1, c2, c3+1, c4, c5, c6, c7, c8, c9, c10);
			}
			if(i == 4 && a*7 <= n && c4+1 <= c3){
				dfs(a*7, all/(c4+1)*(c4+2), sum+1, c1, c2, c3, c4+1, c5, c6, c7, c8, c9, c10);
			}
			if(i == 5 && a*11 <= n && c5+1 <= c4){
				dfs(a*11, all/(c5+1)*(c5+2), sum+1, c1, c2, c3, c4, c5+1, c6, c7, c8, c9, c10);
			}
			if(i == 6 && a*13 <= n && c6+1 <= c5){
				dfs(a*13, all/(c6+1)*(c6+2), sum+1, c1, c2, c3, c4, c5, c6+1, c7, c8, c9, c10);
			}
			if(i == 7 && a*17 <= n && c7+1 <= c6){
				dfs(a*17, all/(c7+1)*(c7+2), sum+1, c1, c2, c3, c4, c5, c6, c7+1, c8, c9, c10);
			}
			if(i == 8 && a*19 <= n && c8+1 <= c7){
				dfs(a*19, all/(c8+1)*(c8+2), sum+1, c1, c2, c3, c4, c5, c6, c7, c8+1, c9, c10);
			}
			if(i == 9 && a*23 <= n && c9+1 <= c8){
				dfs(a*23, all/(c9+1)*(c9+2), sum+1, c1, c2, c3, c4, c5, c6, c7, c8, c9+1, c10);
			}
			if(i == 10 && a*29 <= n && c10+1 <= c9){
				dfs(a*29, all/(c10+1)*(c10+2), sum+1, c1, c2, c3, c4, c5, c6, c7, c8, c9, c10+1);
			}
		}
	}
}

int main(){
	scanf("%lld", &n);
	dfs(1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	printf("%d %d %d %d %d %d %d %d %d %d", s1, s2, s3, s4, s5, s6, s7, s8, s9, s10);
	printf("%lld", ansm);
}
