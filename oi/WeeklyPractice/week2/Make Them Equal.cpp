#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

const int Maxn = 1e4 + 5;

int t, n;
int a[Maxn];
int op[Maxn * 3][5];

int main(){
	scanf("%d", &t);
	for(int ii = 1; ii <= t; ii++){
//		memset(op, 0, sizeof(op));
		scanf("%d", &n);
		int tot = 0;
		int ans = 0;
		for(int i = 1; i <= n; i++){
			scanf("%d", &a[i]);
			tot += a[i];
		} 
		if(tot % n != 0){
			printf("-1\n");
			continue;
		}
		int avg = tot / n;
		for(int i = 2; i <= n; i++){
			if(a[i] % i != 0){
				int add = (a[i] / i + 1) * i - a[i];
				a[i] += add;
				a[1] -= add;
				op[++ans][1] = 1;
				op[ans][2] = i;
				op[ans][3] = add;
			}			
//			for(int j = 1; j <= n; j++){
//				printf("%d ", a[j]);
//			}
//			printf("\n");
			int minus = a[i];
			int cnt = a[i] / i;
			if(minus > 0){
				a[i] -= minus;
				a[1] += minus;
//				if(a[i] >= i) a[i] -= i, a[1] += i, minus += i, cnt++;
				op[++ans][1] = i;
				op[ans][2] = 1;
				op[ans][3] = cnt;
//				for(int j = 1; j <= n; j++){
//					printf("%d ", a[j]);
//				}
//				printf("\n");
			}			
		}		
		for(int i = 2; i <= n; i++){
			int add = avg - a[i];
			a[1] -= add;
			a[i] += add;
			op[++ans][1] = 1;
			op[ans][2] = i;
			op[ans][3] = add;
//			for(int j = 1; j <= n; j++){
//				printf("%d ", a[j]);
//			}
//			printf("\n");
		}
		printf("%d\n", ans);
		for(int i = 1; i <= ans; i++) printf("%d %d %d\n", op[i][1], op[i][2], op[i][3]);
	}
	return 0;
	
}
