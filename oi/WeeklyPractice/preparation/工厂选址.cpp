#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

const int Maxn = 5e4 + 5;

struct Node{
	int num, d;
}inc[Maxn];

int m, b, H, n;
int a[Maxn];
int h[55], c[Maxn][55];
int ans = inf, plc; 

bool cmp(Node a, Node b){
	return a.d < b.d;
}

int main(){
	scanf("%d %d %d %d", &m, &b, &H, &n);
	for(int i = 1; i <= m; i++) scanf("%d", &a[i]);
	for(int i = 1; i <= n; i++) scanf("%d", &h[i]);
	for(int i = 0; i <= n; i++){
		for(int j = 1; j <= m; j++) scanf("%d", &c[j][i]);
	}
	for(int i = 1; i <= n; i++){
		memset(inc, 0, sizeof(inc));
		for(int j = 1; j <= m; j++){
			inc[j].d = c[j][0] - c[j][i];
			inc[j].num = j;
		}
		sort(inc + 1, inc + 1 + m, cmp);
		int str = 0, val = 0, pt = 0, res = 0;;
		for(int j = 1; j <= m; j++){
			int num = inc[j].num;
			if(str + a[num] <= b){
				val += c[num][0] * a[num];
				str = str + a[num];
				if(str == b){
					pt = j + 1;
					break;
				}
			}
			else{
				res = a[num] - (b - str);
				val += c[num][0] * (b-str);			
				pt = j + 1;
				break;
			}
		}
		if(res != 0){
			int num = inc[pt-1].num;
			val += c[num][i] * res;
		}
		for(int j = pt; j <= m; j++){
			int num = inc[j].num;
			val += c[num][i] * a[num];				
		}
		if(val + H + h[i] < ans){
			ans = val + H + h[i];
			plc = i;
		}
	}
	printf("%d\n%d", plc, ans);
	return 0;
}
