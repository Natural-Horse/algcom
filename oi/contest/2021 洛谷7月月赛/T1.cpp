#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

int read(){
	int x = 0,f = 1;char ch = getchar();
	while (ch < '0' || ch > '9'){if (ch == '-') f = -1; ch = getchar();}
	while (ch >= '0' && ch <= '9'){x = x*10 + ch - 48; ch = getchar();}
	return x * f;
}

const int N = 10;

int a[N][N], b[N][N]; 
int ba[N], bb[N], cnta, cntb, lesa, lesb;

int main(){
	a[1][1] = read(), a[1][2] = read(), a[2][1] = read(), a[2][2] = read();
	b[1][1] = read(), b[1][2] = read(), b[2][1] = read(), b[2][2] = read();
	ba[++ba[0]] = a[1][1]; if(a[1][1]!=0) cnta++;
	ba[++ba[0]] = a[1][2]; if(a[1][2]!=0) cnta++;
	ba[++ba[0]] = a[2][2]; if(a[2][2]!=0) cnta++;
	ba[++ba[0]] = a[2][1]; if(a[2][1]!=0) cnta++;
	bb[++bb[0]] = b[1][1]; if(b[1][1]!=0) cntb++; 
	bb[++bb[0]] = b[1][2]; if(b[1][2]!=0) cntb++; 
	bb[++bb[0]] = b[2][2]; if(b[2][2]!=0) cntb++;  
	bb[++bb[0]] = b[2][1]; if(b[2][1]!=0) cntb++; 
	lesa = 4 - cnta, lesb = 4 - cntb;
	if(cnta != cntb){
		printf("No");
		return 0;
	}
	else if(cnta == 4 && cntb == 4){
		for(int i = 1; i <= 4; i++){
			if(ba[i] != bb[i]){
				printf("No");
				return 0;
			}
		}
		printf("Yes");
		return 0;
	}
	else if(cnta == 0 && cntb == 0){
		printf("Yes");
		return 0;
	}
	else{
		for(int i = 1; i <= 4; i++){
			if(ba[i] != 0){
				int j = i-1;
				while(ba[j] == 0) j--;
				if(j+1 != i) ba[j+1] = ba[i], ba[i] = 0;
			}
			if(bb[i] != 0){
				int j = i-1;
				while(bb[j] == 0) j--;
				if(j+1 != i) bb[j+1] = bb[i], bb[i] = 0;
			}			
		}
		bool jud = true;
		for(int i = 0; i < cnta; i++){
			jud = true;
			for(int j = 1; j <= cnta; j++){
				int pta = j, ptb = i+j;
				if(ptb > cnta) ptb %= cnta;
				if(ba[pta] != bb[ptb]){
					jud = false;
					break;
				}
			}
			if(jud == true){
				printf("Yes");
				return 0;
			} 
		}
		printf("No");
	}
	return 0;
}

