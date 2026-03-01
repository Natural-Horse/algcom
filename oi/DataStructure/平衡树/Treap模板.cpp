#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

const int Maxn = 2e6 + 5;

int read(){
	int x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >='0' && ch <= '9') { x = x * 10 + ch - 48; ch = getchar();}
	return x * f;
}

int n, m, las, ans, x_;
int ch[Maxn][2];
int val[Maxn], dat[Maxn], siz[Maxn], cnt[Maxn];
int root, tot;

int New(int v){
	val[++tot] = v;
	dat[tot] = rand();
	siz[tot] = 1, cnt[tot] = 1;
	return tot;
}
void push_up(int u){
	siz[u] = siz[ch[u][0]] + siz[ch[u][1]] + cnt[u];
}
void rotate(int &u, int d){
	int tmp = ch[u][d^1];
	ch[u][d^1] = ch[tmp][d];
	ch[tmp][d] = u;
	u = tmp;
	push_up(ch[u][d]), push_up(u);
}
void insert(int &u, int v){
	if(!u){
		u = New(v);
		return;
	}
	if(v == val[u]) cnt[u]++;
	else{
		int d = v < val[u]? 0: 1;
		insert(ch[u][d], v);
		if(dat[u] < dat[ch[u][d]]) rotate(u, d ^ 1);
	}
	push_up(u);
}
void remove(int &u, int v){
	if(!u) return;
	if(v == val[u]){
		if(cnt[u] > 1){
			cnt[u]--;
			push_up(u);			
			return;
		}
		if(ch[u][0] || ch[u][1]){
			if(!ch[u][1] || dat[ch[u][0]] > dat[ch[u][1]]){
				rotate(u, 1), remove(ch[u][1], v);
			}
			else rotate(u, 0), remove(ch[u][0], v);
			push_up(u);
		}
		else u = 0;
		return;
	}
	v < val[u]? remove(ch[u][0], v): remove(ch[u][1], v);
	push_up(u);
}
int query_rank(int u, int v){
	if(!u) return 1;
	if(v == val[u]) return siz[ch[u][0]] + 1;
	else if(v < val[u]) return query_rank(ch[u][0], v);
	else return siz[ch[u][0]] + cnt[u] + query_rank(ch[u][1], v);
}
int query_val(int u, int rk){
	if(!u) return inf;
	if(rk <= siz[ch[u][0]]) return query_val(ch[u][0], rk);
	else if(rk <= siz[ch[u][0]] + cnt[u]) return val[u];
	else return query_val(ch[u][1], rk - siz[ch[u][0]] - cnt[u]);
}
int query_pre(int v){
	int u = root, pre = 0;
	while(u){
		if(val[u] < v) pre = val[u], u = ch[u][1];
		else u = ch[u][0];
	}
	return pre;
}

int query_nxt(int v){
	int u = root, nxt = 0;
	while(u){
		if(val[u] > v) nxt = val[u], u = ch[u][0];
		else u = ch[u][1];
	}
	return nxt;
}
int main(){
	n = read(), m = read();
	for(int i = 1; i <= n; i++){
		int jud = read();
		insert(root, jud);
	}
	for(int i = 1; i <= m; i++){
		int op = read(), v = read();
		if(op == 1) insert(root, x_^v);
		if(op == 2) remove(root, x_^v);
		if(op == 3) x_ = query_rank(root, x_^v), ans ^= x_;
		if(op == 4) x_ = query_val(root, x_^v), ans ^= x_;
		if(op == 5) x_ = query_pre(x_^v), ans ^= x_;
		if(op == 6) x_ = query_nxt(x_^v), ans ^= x_;	
	}
	printf("%d", ans);
	return 0;
}
