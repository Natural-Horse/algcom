#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

const int MAXN = 1e6; 

struct Tree{
	int l, r, siz;
	int lsum1, insum1, rsum1;
	int lsum0, insum0, rsum0;
	int lz0, lz1, rev;
	int sum1;
}tree[4 * MAXN + 5];

int a[MAXN + 5];
int n, m;
int ans, anssum[5]; 

void build(int flag, int l, int r){
	if(l == r){
		tree[flag].l = l;
		tree[flag].r = r;
		tree[flag].siz = 1;
		return;
	}
	int mid = ((l + r) >> 1);
	int numa = (flag << 1), numb = (numa | 1);
	tree[numa].l = l, tree[numa].r = mid;
	tree[numb].l = mid + 1, tree[numb].r = r;
	build(numa, l, mid);
	build(numb, mid + 1, r);
	tree[flag].siz = tree[numa].siz + tree[numb].siz;
}

void dfs(int u){
	int l = tree[u].l, r = tree[u].r;
	if(l == r){
		tree[u].lsum1 = tree[u].insum1 = tree[u].rsum1 = tree[u].sum1 = a[l] & 1;
		tree[u].lsum0 = tree[u].insum0 = tree[u].rsum0 = a[l] ^ 1;
		return;
	}
	int numa = (u << 1), numb = ((u << 1) | 1);
	dfs(numa);
	dfs(numb);
	//longest 1
	tree[u].lsum1 = tree[numa].lsum1;
	if(tree[numa].lsum1 == tree[numa].siz) tree[u].lsum1 += tree[numb].lsum1;
	tree[u].rsum1 = tree[numb].rsum1;
	if(tree[numb].rsum1 == tree[numb].siz) tree[u].rsum1 += tree[numa].rsum1;
	tree[u].insum1 = max(tree[numa].rsum1 + tree[numb].lsum1,max(tree[numa].insum1, tree[numb].insum1));
	//longest 0
	tree[u].lsum0 = tree[numa].lsum0;
	if(tree[numa].lsum0 == tree[numa].siz) tree[u].lsum0 += tree[numb].lsum0;
	tree[u].rsum0 = tree[numb].rsum0;
	if(tree[numb].rsum0 == tree[numb].siz) tree[u].rsum0 += tree[numa].rsum0;
	tree[u].insum0 = max(tree[numa].rsum0 + tree[numb].lsum0,max(tree[numa].insum0, tree[numb].insum0));
	//sum1
	tree[u].sum1 = tree[numa].sum1 + tree[numb].sum1; 
}

void push_down(int u){
	int numa = (u << 1), numb = (numa | 1);
	if(tree[u].lz1){
		tree[numa].lz0 = 0;
		tree[numa].lz1 = 1;
		tree[numa].rev = 0;
		tree[numa].lsum1 = tree[numa].insum1 = tree[numa].rsum1 = tree[numa].sum1 = tree[numa].siz;
		tree[numa].lsum0 = tree[numa].insum0 = tree[numa].rsum0 = 0;
		tree[numb].lz0 = 0;
		tree[numb].lz1 = 1;
		tree[numb].rev = 0;
		tree[numb].lsum1 = tree[numb].insum1 = tree[numb].rsum1 = tree[numb].sum1 = tree[numb].siz;
		tree[numb].lsum0 = tree[numb].insum0 = tree[numb].rsum0 = 0;
		tree[u].lz1 = 0;
	}
	if(tree[u].lz0){
		tree[numa].lz0 = 1;
		tree[numa].lz1 = 0;
		tree[numa].rev = 0;
		tree[numa].lsum0 = tree[numa].insum0 = tree[numa].rsum0 = tree[numa].siz;
		tree[numa].lsum1 = tree[numa].insum1 = tree[numa].rsum1 = tree[numa].sum1 = 0;
		tree[numb].lz0 = 1;
		tree[numb].lz1 = 0;
		tree[numb].rev = 0;
		tree[numb].lsum0 = tree[numb].insum0 = tree[numb].rsum0 = tree[numb].siz;
		tree[numb].lsum1 = tree[numb].insum1 = tree[numb].rsum1 = tree[numb].sum1 = 0;
		tree[u].lz0 = 0;
	}
	if(tree[u].rev){
		if(tree[numa].lz0){
			tree[numa].lz0 = 0;
			tree[numa].lz1 = 1;
		}
		else if(tree[numa].lz1){
			tree[numa].lz0 = 1;
			tree[numa].lz1 = 0;
		}
		else if(tree[numa].rev){
			tree[numa].rev = 0;
		}
		else tree[numa].rev = 1;
		swap(tree[numa].lsum1, tree[numa].lsum0);
		swap(tree[numa].insum1, tree[numa].insum0);
		swap(tree[numa].rsum1, tree[numa].rsum0);
		tree[numa].sum1 = tree[numa].siz - tree[numa].sum1;
		if(tree[numb].lz0){
			tree[numb].lz0 = 0;
			tree[numb].lz1 = 1;
		}
		else if(tree[numb].lz1){
			tree[numb].lz0 = 1;
			tree[numb].lz1 = 0;
		}
		else if(tree[numb].rev){
			tree[numb].rev = 0;
		}
		else tree[numb].rev = 1;
		swap(tree[numb].lsum1, tree[numb].lsum0);
		swap(tree[numb].insum1, tree[numb].insum0);
		swap(tree[numb].rsum1, tree[numb].rsum0);
		tree[numb].sum1 = tree[numb].siz - tree[numb].sum1;
		tree[u].rev = 0;
	}
}

void push_back(int u){
	int numa = (u << 1), numb = (numa | 1);
	//longest 1
	tree[u].lsum1 = tree[numa].lsum1;
	if(tree[numa].lsum1 == tree[numa].siz) tree[u].lsum1 += tree[numb].lsum1;
	tree[u].rsum1 = tree[numb].rsum1;
	if(tree[numb].rsum1 == tree[numb].siz) tree[u].rsum1 += tree[numa].rsum1;
	tree[u].insum1 = max(tree[numa].rsum1 + tree[numb].lsum1,max(tree[numa].insum1, tree[numb].insum1));
	//longest 0
	tree[u].lsum0 = tree[numa].lsum0;
	if(tree[numa].lsum0 == tree[numa].siz) tree[u].lsum0 += tree[numb].lsum0;
	tree[u].rsum0 = tree[numb].rsum0;
	if(tree[numb].rsum0 == tree[numb].siz) tree[u].rsum0 += tree[numa].rsum0;
	tree[u].insum0 = max(tree[numa].rsum0 + tree[numb].lsum0,max(tree[numa].insum0, tree[numb].insum0));
	//sum1
	tree[u].sum1 = tree[numa].sum1 + tree[numb].sum1;
}

void to1(int u, int st, int re){
	int l = tree[u].l, r = tree[u].r;
	if(l > re || r < st) return;
	if(l >= st && r <= re){
		tree[u].lz0 = 0;
		tree[u].lz1 = 1;
		tree[u].rev = 0;
		tree[u].lsum1 = tree[u].insum1 = tree[u].rsum1 = tree[u].sum1 = tree[u].siz;
		tree[u].lsum0 = tree[u].insum0 = tree[u].rsum0 = 0;
	}
	else{
		push_down(u);
		if(l <= re) to1((u << 1), st, re);
		if(r >= st) to1(((u << 1) | 1), st, re);
		push_back(u);
	}	
}

void to0(int u, int st, int re){
	int l = tree[u].l, r = tree[u].r;
	if(l > re || r < st) return;
	if(l >= st && r <= re){
		tree[u].lz0 = 1;
		tree[u].lz1 = 0;
		tree[u].rev = 0;
		tree[u].lsum0 = tree[u].insum0 = tree[u].rsum0 = tree[u].siz;
		tree[u].lsum1 = tree[u].insum1 = tree[u].rsum1 = tree[u].sum1 = 0;
	}
	else{
		push_down(u);
		if(l <= re) to0((u << 1), st, re);
		if(r >= st) to0(((u << 1) | 1), st, re);
		push_back(u);
	}	
}

void rev(int u, int st, int re){
	int l = tree[u].l, r = tree[u].r;
	if(l > re || r < st) return;
	if(l >= st && r <= re){
		if(tree[u].lz0){
			tree[u].lz0 = 0;
			tree[u].lz1 = 1;
		}
		else if(tree[u].lz1){
			tree[u].lz0 = 1;
			tree[u].lz1 = 0;
		}
		else if(tree[u].rev){
			tree[u].rev = 0;
		}
		else tree[u].rev = 1;
		swap(tree[u].lsum1, tree[u].lsum0);
		swap(tree[u].insum1, tree[u].insum0);
		swap(tree[u].rsum1, tree[u].rsum0);
		tree[u].sum1 = tree[u].siz - tree[u].sum1;
	}
	else{
		push_down(u);
		if(l <= re) rev((u << 1), st, re);
		if(r >= st) rev(((u << 1) | 1), st, re);
		push_back(u);
	}	
}

void ask1(int u, int st, int re){
	int l = tree[u].l, r = tree[u].r;
	if(l > re || r < st) return;
	push_down(u);
	if(l >= st && r <= re){
		ans += tree[u].sum1;
		return;
	}
	else{
		if(l <= re) ask1((u << 1), st, re);
		if(r >= st) ask1(((u << 1) | 1), st, re);
		push_back(u);
	}
}

void ask2(int u, int st, int re){
	int l = tree[u].l, r = tree[u].r;
	if(l > re || r < st) return;
	push_down(u);
	if(l >= st && r <= re){
		anssum[1] = max(anssum[1], anssum[2] + tree[u].lsum1);
		anssum[1] = max(anssum[1], tree[u].insum1);		
		if(tree[u].insum1 == tree[u].siz){
			anssum[2] += tree[u].siz; 
		}
		else anssum[2] = tree[u].rsum1;
	}
	else{
		if(l <= re) ask2((u << 1), st, re);
		if(r >= st) ask2(((u << 1) | 1), st, re);
		push_back(u);
	}
}

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	tree[1].l = 0;
	tree[1].r = n - 1;
	tree[1].siz = n;
	build(1, 0, n - 1);
	dfs(1);
	for(int i = 1, op, st, re; i <= m; i++){
		scanf("%d %d %d", &op, &st, &re);
		if(op == 0){
			to0(1, st, re);
		}
		if(op == 1){
			to1(1, st, re);
		}
		if(op == 2){
			rev(1, st, re);
		}
		if(op == 3){
			ans = 0;
			ask1(1, st, re);
			printf("%d\n", ans);
		}
		if(op == 4){
			anssum[1] = anssum[2] = 0;
			ask2(1, st, re);
			printf("%d\n",anssum[1]);
		}
	}
	return 0;
}
