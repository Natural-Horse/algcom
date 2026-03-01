#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

const int Maxn = 7e4 + 5;

int n;
int a[Maxn], xors[Maxn];
vector<int> v[Maxn];
bool check, b[Maxn];
int x, y;
int jud;

int main(){
	scanf("%d", &n);
	for(int i = 2; i <= n; i++){
		printf("XOR 1 %d\n", i);
		fflush(stdout);
		scanf("%d", &xors[i]);
		if(b[xors[i]]) check = true;
		v[xors[i]].push_back(i);
		b[xors[i]] = true;
		if(!check){
			if(xors[i] == 1) x = i;
			if(xors[i] == n - 2) y = i;
		}
		else{
			if(v[xors[i]].size() > 1) jud = xors[i];
		}
	}
	if(!check && !b[0]){
		int xx = 0, yy = 0;
		printf("AND 1 %d\n", x);
		fflush(stdout);
		scanf("%d", &xx);
		int xxx = ((xx >> 1) << 1);
		printf("AND 1 %d\n", y);
		fflush(stdout);
		scanf("%d", &yy);
		int yyy = (yy & 1);
		a[1] = xxx + yyy;
	}
	else{
		if(jud == 0){
			int xx = v[0][0];
			int xxx = 0;
			printf("AND 1 %d\n", xx);
			fflush(stdout);
			scanf("%d", &xxx);
			a[1] = xxx;
		}
		else{
			int xx = v[jud][0], yy = v[jud][1];
			int xxx = 0;
			printf("AND %d %d\n", xx, yy);
			fflush(stdout);
			scanf("%d", &xxx);
			a[xx] = xxx;
			a[1] = a[xx] ^ xors[xx];
		}
	}
	printf("! %d ", a[1]);
	fflush(stdout);
	for(int i = 2; i <= n; i++){
		a[i] = a[1] ^ xors[i];
		printf("%d ", a[i]);
		fflush(stdout);
	}
	printf("\n");
	return 0;
}
