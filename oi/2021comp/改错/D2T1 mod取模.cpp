#include<bits/stdc++.h>
#define inf 0x3f3f3f3f3f3f3f3f
#define ll long long
using namespace std;

const int Maxn = 2e5;

int n;
int a[Maxn];
int ans;
int op[Maxn], cnt;

bool cmp1(int x, int y){
	return x > y;
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}
	sort(a + 1, a + 1 + n, cmp1);
	for(int i = 1; i <= n; i++){
		if(a[i] <= ans) break;
		cnt = 0;
		for(int j = 1; j <= n; j++){
			if(i != j) op[++cnt] = a[j] % a[i];
		}
		sort(op + 1, op + 1 + cnt);
		int jud = op[cnt] + op[cnt - 1] - a[i];
		int l = 1, r = cnt, sum = 0;
		while(l <= r){
			sum = op[l] + op[r];
			if(sum >= a[i]){
				r--;
			}
			if(sum < a[i]){
				l++;
				jud = max(jud, sum);
			}
		}
		ans = max(ans, jud);
	}
	printf("%d", ans);
	return 0;
}
