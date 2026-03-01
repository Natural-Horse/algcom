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

int p[N], s1[N], s2[N], cnt, n, len, w; 
bool b[200000005];
int bc[20000005];
db ans;

void Prime(){
	for(int i = 2; i <= 200000000; i++){
		if(!b[i]){
			p[++cnt] = i;
			s1[cnt] = i * cnt % w;
			s2[cnt] = s1[cnt] + s1[cnt/10+1];
		}
		if(cnt >= n) return; 
		for(int j = 1; j <= cnt && p[j] * i <= N; j++){
			b[i*p[j]] = true;
			if(i % p[j] == 0) break;
		}
	}
}

int main(){
	n = read(), len = read(), w = read();
	Prime();
	for(int i = 1; i <= n; i++) printf("%d ", s1[i]);
	printf("\n");
	for(int i = 1; i <= n; i++) printf("%d ", s2[i]);
	printf("\n");
	for(int i = 1; i <= len; i++) bc[s2[i]]++;
	if(len % 2 == 1){
		int jud = (len+1) >> 1, pt = 0, rk = 0;
		while(rk < jud) rk += bc[++pt];
		for(int i = 1; i <= n-len+1; i++){
			ans += (db) pt;
			bc[s2[i]]--, bc[s2[i+len]]++;
			s2[i] > pt? rk++: rk--;
			s2[i+len] > pt? rk--: rk++;
			while(rk < jud) rk += bc[++pt];
			while(rk > jud) rk -= bc[--pt];
		}
	}
	if(len % 2 == 0){
		int juda = len >> 1, judb = juda+1, pta = 0, ptb = 0, rka = 0, rkb = 0;
		while(rka < juda) rka += bc[++pta];
		while(rkb < judb) rkb += bc[++ptb];
		for(int i = 1; i <= n-len+1; i++){
			ans += ((db)(pta + ptb)/2);
			bc[s2[i]]--, bc[s2[i+len]]++;
			s2[i] > pta? rka++: rka--;
			s2[i+len] > pta? rka--: rka++;
			s2[i] > ptb? rkb++: rkb--;
			s2[i+len] > ptb? rkb--: rkb++;
			while(rka < juda) rka += bc[++pta];
			while(rka > juda) rka -= bc[--pta];
			while(rkb > judb) rkb -= bc[--ptb];
			while(rkb < judb) rkb += bc[++ptb];
		}
	}
	printf("%.1lf", ans);
	return 0;
}

