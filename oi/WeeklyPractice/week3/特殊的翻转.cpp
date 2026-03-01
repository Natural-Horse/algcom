#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

const int Maxn = 4e6 + 5;

char in[1000005];
int n;
int a[Maxn], b[Maxn], cnt;
int ansa, ansb;
int rp;

void prework(char c){
	int x = c, jud = (1 << 3);
	if(c >= '0' && c <= '9') x -= '0';
	else x = x - 64 + 9;
	while(jud){
		if(x & jud){
			a[++cnt] = 1;
			b[cnt] = 1;
		}
		else{
			a[++cnt] = 0;
			b[cnt] = 0;
		} 
		jud >>= 1;
	}
}

int main(){
	scanf("%s", in + 1);
	n = strlen(in + 1);
	for(int i = 1; i <= n; i++){
		prework(in[i]);
	}
	int plc = 1;
	while(!a[plc]) plc++;
	a[plc] ^= 1, a[plc+1] ^= 1, ansa = 1;
	b[plc] ^= 1, b[plc+1] ^= 1, b[plc+2] ^= 1, ansb = 1;
	for(int i = plc+1; i <= cnt-2; ++i){
		if(a[i]){
			a[i] ^= 1, a[i+1] ^= 1, a[i+2] ^= 1;
			ansa++;
		}
	}
	if(a[cnt] != a[cnt-1]) ansa = -1;
	else if(a[cnt]) ansa++;
	for(int i = plc+1; i <= cnt-2; ++i){
		if(b[i]){
			b[i] ^= 1, b[i+1] ^= 1, b[i+2] ^= 1;
			ansb++;
		}
	}
	if(b[cnt] != b[cnt-1]) ansb = -1;
	else if(b[cnt]) ansb++;
	if(ansa == -1 && ansb == -1) printf("No");
	else if(ansa == -1) printf("%d", ansb);
	else if(ansb == -1) printf("%d", ansa);
	else printf("%d", min(ansa, ansb));
	return 0;
}
