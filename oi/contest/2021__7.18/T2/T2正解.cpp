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

const int N = 31;
int n, m;
char s[N];

struct hash_map{
    int head[40000000], tot;
    struct node{
        int nxt, to, w;
        double v;
    }ed[6000000];
    double &operator[](int sta){
        int key = 1LL * sta % 30000019;
        for(int i = head[key]; i; i = ed[i].nxt)
            if(ed[i].to == sta) return ed[i].v;
        ed[++tot].nxt = head[key]; ed[tot].to = sta; ed[tot].v = -1.0;
        head[key] = tot;
        return ed[tot].v;
    }
}mp;

db dfs(int now, int num){
	if(n - num >= m) return 0;
	if(mp[now] != -1) return mp[now];
	double res = 0;
	for(int i = 1; i <= num >> 1; i++){
		int st1 = now&((1<<i)-1),las1 = now-st1,fir1 = now&((1<<(i-1))-1);
		int tran1 = (las1 >> 1) | fir1;
		int st2 = now&((1<<(num-i+1))-1), las2 = now-st2, fir2 = now&((1<<(num-i))-1);
		int tran2 = (las2 >> 1) | fir2;
		int c1 = (now >> (i-1)) & 1, c2 = (now >> (num-i)) & 1;
		res += 2 * max(dfs(tran1, num-1) + c1, dfs(tran2, num-1) + c2);
	}
	if(num & 1){
		int i = num >> 1;
		int c = (now >> i) & 1, st = now&((1<<(i+1))-1);
		int fir = now&((1<<i)-1), las = now - st;
		int tran = fir | (las >> 1);
		res += dfs(tran, num-1) + c;
	}
	res = res / num;
	return mp[now] = res;
}

int main(){
	n = read(), m = read();
	scanf("%s", s + 1);
	int sta = 1;
	for(int i = 1; i <= n; i++){
		sta <<= 1;
		if(s[i] == 'W') sta |= 1;
	}
	db res = dfs(sta, n);
	printf("%lf", res);
	return 0;
}

