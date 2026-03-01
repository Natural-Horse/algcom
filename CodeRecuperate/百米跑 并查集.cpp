#include<bits/stdc++.h>
#include<map>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

inline int read(){
	int x = 0, f = 1; char ch = getchar();
	while(!isdigit(ch)){if(ch == '-') f = -1; ch = getchar();}
	while(isdigit(ch)){x = (x << 1) + (x << 3) + ch - 48; ch = getchar();}
	return x * f;
}

const int N = 2e4 + 5;

map<string, string> anc;
int n, m, k; 

string find(string u){
	if(anc[u] == u) return u;
	else return anc[u] = find(anc[u]);
}

void merge(string u, string v){
	string x = find(u), y = find(v);
	if(x != y) anc[x] = y;
}

int main(){
	string s1, s2;
	n = read(), m = read();
//	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> s1;
		anc[s1] = s1;
//		printf("%s\n", anc[s1]);
	}
	for(int i = 1; i <= m; i++){
//		printf("123123123123\n");
		cin >> s1 >> s2;
		merge(s1, s2);
	}
	k = read();
	for(int i = 1; i <= k; i++){
		cin >> s1 >> s2;
		if(find(s1) == find(s2)) printf("Yes.\n");
		else printf("No.\n");
	}
	return 0;
}

