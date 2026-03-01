#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
#define db double
using namespace std;

char ch;

int read(){
	int x = 0,f = 1;ch = getchar();
	while (ch < '0' || ch > '9'){if (ch == '-') f = -1; ch = getchar();}
	while (ch >= '0' && ch <= '9'){x = x*10 + ch - 48; ch = getchar();}
	return x * f;
}

const int N = 2e3 + 5;

struct Edge{
	int nxt, to;
	db w;
}ed[N << 2];

int n;
char a[10][10];
vector<int> l, r;
int tot, pta, ptb, cnta, cntb;
db e, ans, na, nb, fa, fb, jud;

int main(){
	n = read();
	na = read();
	if(ch == '.'){
		jud = read();
		while(jud >= 1) jud /= 10;
		na += jud;
		jud = 0;
	} 
	ch = getchar();
	while(ch != ' '){
		a[1][++pta] = ch;
		ch = getchar();
	}
	ch = getchar(), ch = getchar();
	nb = read();
	if(ch == '.'){
		jud = read();
		while(jud >= 1) jud /= 10;
		nb += jud;
		jud = 0;
	} 
	ch = getchar();
	while(ch != ' '){
		a[2][++ptb] = ch;
		ch = getchar();
	}
	ch = getchar(), ch = getchar(), ch = getchar();
	scanf("%lf\n", &e);
	fa = read();
	if(ch == '.'){
		jud = read();
		while(jud >= 1) jud /= 10;
		fa += jud;
		jud = 0;
	} 
	ch = getchar();
	while(ch != ' '){
		a[3][++cnta] = ch;
		ch = getchar();
	}
	ch = getchar(), ch = getchar();
	fb = read();
	if(ch == '.'){
		jud = read();
		while(jud >= 1) jud /= 10;
		fb += jud;
		jud = 0;
	} 
	ch = getchar();
	while(ch != ' '){
		a[4][++cntb] = ch;
		ch = getchar();
	}
	for(int i = 1; i <= 4; i++) ch = getchar();
	for(int i = 1; i <= cnta; i++){
		for(int j = 1; j <= pta; j++){
			if(a[3][i] != a[1][j]){
				ans = -e * (fb/na);
				printf("%.1lf", ans);
				return 0;
			}
		}
	}
	ans = e * (fa / na);
	printf("%.1lf", ans);
	return 0;	
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
//	for(int i = 1; i <= n; i++){
//		c = false, eq = false;
//		num = 0, f = 1, x = 0, ap = 0;
//		l.clear(), r.clear();
//		memset(pt, 0, sizeof(pt));
//		while(1){
//			char ch = getchar();
//			while(ch == '-') f = -1, ch = getchar();
//			while(ch >= '0' && ch <= '9') x = x*10 + ch - 48, ch = getchar();
//			if(x){
//				ch = getchar();
//				if(ch == ' ') num = x * f, x = 0, f = 1;
//				else if(ch == '\n'){
//					for(int j = 0; j < l.size(); j++){
//						for(int k = 0; k < r.size(); k++){
//							db w = (db)(pt[l[j]]*num)/(db)pt[r[k]];
//							add_edge(l[j], r[k], w), add_edge(r[k], l[j], -w);
//						}
//					}
//					
//					break;
//				}
//			}
//			if(ch == '='){
//				ch = getchar();
//				if(ch == '=') eq = true;
//			}
//			if(ch >= 'A' && ch <= 'Z'){
//				a[++ap] = ch;
//				ch = getchar();
//				while(ch != ' ') a[++ap] = ch, ch = getchar();
//				bool exi = false;
//				for(int j = 1; j <= tot; j++){
//					for(int k = 1; k <= ap; k++){
//						if(sub[i][k] != a[k]) break;
//						if(k == ap){
//							if(!eq) l.push_back(j);
//							else r.push_back(j);
//							exi = true;
//							pt[j] = num;
//						}
//					}
//					if(exi) break;
//				}
//				if(!exi){
//					tot++;
//					for(int j = 1; j <= ap; j++) sub[tot][j] = a[j];
//					if(!eq) l.push_back(j);
//					else r.push_back(j);
//					pt[tot] = num;
//				}
//			}
//		}
//	}
//}

