#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

inline int read(){
	int x = 0, f = 1; char ch = getchar();
	while(!isdigit(ch)){if(ch == '-') f = -1; ch = getchar();}
	while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - 48; ch = getchar();}
	return x * f;
}

const int N = 1e5 + 5, M = 3e6 + 5;

struct Trie{
	int nxt[M][70], tot, cnt[M];
	
	void insert(char* s, int len){
		int plc = 0;
		for(int i = 1; i <= len; i++){
			int c;
			if(s[i] >= '0' && s[i] <= '9') c = s[i] - '0';
			else if(s[i] >= 'a' && s[i] <= 'z') c = s[i] - 'a' + 1 + 9;
			else if(s[i] >= 'A' && s[i] <= 'Z') c = s[i] - 'A' + 1 + 9 + 26;
			if(!nxt[plc][c]) nxt[plc][c] = ++tot;
			plc = nxt[plc][c];
			cnt[plc]++;
		}
	}
	int qr_cnt(char* s, int len){
		int plc = 0;
		for(int i = 1; i <= len; i++){
			int c;
			if(s[i] >= '0' && s[i] <= '9') c = s[i] - '0';
			else if(s[i] >= 'a' && s[i] <= 'z') c = s[i] - 'a' + 1 + 9;
			else if(s[i] >= 'A' && s[i] <= 'Z') c = s[i] - 'A' + 1 + 9 + 26;
			
			if(!nxt[plc][c]) return 0;
			plc = nxt[plc][c];
		}
		return cnt[plc];
	}
	void erase(){
		for(int i = 0; i <= tot; i++){
			cnt[i] = 0;
			for(int j = 0; j <= 61; j++) nxt[i][j] = 0;
		}
		tot = 0;
	}
}tr;

int t, n, q;
char a[M];

int main(){
	t = read();
	while(t--){
		tr.erase();
		n = read(), q = read();
		for(int i = 1; i <= n; i++){
			scanf("%s", a + 1);
			tr.insert(a, strlen(a + 1));
		}
		for(int i = 1; i <= q; i++){
			scanf("%s", a + 1);
			int ans = tr.qr_cnt(a, strlen(a + 1));
			printf("%d\n", ans);
		}
	}
	return 0;
}

