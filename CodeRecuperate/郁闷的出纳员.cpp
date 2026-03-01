#include<bits/stdc++.h>
#define inf 0x7fffffff
#define ll long long
using namespace std;

inline int read(){
	int x = 0, f = 1; char ch = getchar();
	while(!isdigit(ch)){if(ch == '-') f = -1; ch = getchar();}
	while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - 48; ch = getchar();}
	return x * f;
}

const int N = 3e5 + 5;

int n, minn, num, tot, dif, rt, m;
int ch[N][2], val[N], cnt[N], siz[N], dat[N]; 

int New(int v){
	val[++tot] = v, dat[tot] = rand();
	siz[tot] = cnt[tot] = 1;
	return tot;
}

void push_up(int u){
	siz[u] = siz[ch[u][1]] + siz[ch[u][0]] + cnt[u];
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

int qr_val(int u, int rk){
	if(!rk) return 0;
	if(cnt[u] + siz[ch[u][0]] >= rk && siz[ch[u][0]] < rk) return val[u];
	else if(cnt[u] + siz[ch[u][0]] < rk) return qr_val(ch[u][1], rk - (cnt[u] + siz[ch[u][0]]));
	else return qr_val(ch[u][0], rk);
}

int qr_pre(int v){
	int u = rt, pre = 1;
	while(u){
		if(val[u] == v){pre = u; break;}
		if(val[u] < v && val[u] > val[pre]) pre = u;
		if(val[u] < v) u = ch[u][1];
		else u = ch[u][0];
	}
	return val[pre];
}

int main(){
	freopen("P1486_2.in", "r", stdin);
	freopen("2.out", "w", stdout);
	n = read(), minn = read();
	insert(rt, -inf);
	insert(rt, inf);
	for(int i = 1, k; i <= n; i++){
		char op;
		cin >> op >> k;
		getchar();
		if(op == 'I'){
			if(k - dif < minn) continue;
			insert(rt, k - dif);
			num++, m++;
		}
		if(op == 'A') dif += k, minn -= k;
		if(op == 'S'){
			dif -= k, minn += k;
			int u = minn - 1, v;
			while(qr_pre(u) != -inf){
				v = u, u = qr_pre(u);
				remove(rt, qr_pre(v));
				num--;
			}
		}
		if(op == 'F'){
			if(num < k) printf("-1\n");
			else{
				int prt = qr_val(rt, num-k+2) + dif;
				printf("%d\n", prt);
			}
		}
	}
	printf("%d\n", m - num);
	return 0;
}

