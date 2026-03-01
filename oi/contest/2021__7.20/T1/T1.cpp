#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
#define db double
using namespace std;

int read(){
	int x = 0,f = 1;char ch = getchar();
	while (ch < '0' || ch > '9'){if (ch == '-') f = -1; ch = getchar();}
	while (ch >= '0' && ch <= '9'){x = x*10 + ch - 48; ch = getchar();}
	return x * f;
}

const int N = 1e7 + 5;

int n, k, w;
ll p[N], cnt;
int s1[N], s2[N];
db ans;
bool b[N];
int tmp[N];

void Prime(){
	for(int i = 2; i <= N; i++){
		if(!b[i]){
			p[++cnt] = i;
			s1[cnt] = (ll)i * cnt % w;
			s2[cnt] = s1[cnt]+s1[cnt/10+1];
		} 		
		if(cnt >= n) break;
		for(int j = 1; j <= cnt && p[j]*i <= N; j++){
			b[i*p[j]] = true;
			if(i % p[j] == 0) break;
		}
	}
}

int main(){
	n = read(), k = read(), w = read();
	Prime();
	for(int i = 1; i <= n-k+1; i++){
		for(int j = i; j <= i + k - 1; j++) tmp[j-i+1] = s2[j];
		sort(tmp + 1, tmp + 1 + k);
		int numa = tmp[k/2+1], numb = tmp[k/2];
		if(k % 2 == 1){
			ans += (db)numa;
		}
		else ans += ((db)numa + (db)numb) / 2;
	}
	printf("%.1lf", ans);
	return 0;
}
