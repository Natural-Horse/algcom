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

const int N = 1e4 + 5;
char a[N], s[5005][5005];
int len, cnt, l, ans;
bool b[N];

int main(){
	scanf("%s", a + 1);
	l = read();
	len = strlen(a + 1);
	for(int i = len + 1; i <= len * 2; i++) a[i] = a[i-len];
	for(int i = 1; i <= (len<<1)-l+1 && i <= len; i++){
		cnt++;
		for(int j = 1; j <= l; j++){
			s[cnt][j] = a[i-1+j];
		}
	}
	for(int i = 1; i <= cnt; i++){
		for(int j = i+1; j <= cnt; j++){
			bool check = false;
			for(int k = 0; k <= l-1; k++){
				bool jud = true;
				for(int w = 1+k; w <= l+k; w++){
					int pta = w-k, ptb = w;
					if(ptb > l) ptb %= l;
					if(s[i][pta] != s[j][ptb]){jud = false;break;} 
				}
				if(jud == true){check = true;break;}
			}
			if(check == true){
				if(!b[j]){b[j]=true;ans++;}
			} 
		}
	}
	printf("%d", cnt - ans);
	return 0;
}

