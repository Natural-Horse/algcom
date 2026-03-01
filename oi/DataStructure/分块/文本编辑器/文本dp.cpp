
#include<bits/stdc++.h>
using namespace std;

const int N = 2e3 + 10, M = 2e3 + 10;

struct node {
	char s[N + 1];
	int c, l, r;
}p[M];
int id[N], idx;//可分配的编号池
char str[2000010];
int n, x, y;
void move(int k)//移动到第k个字符后面
{
	x = p[0].r;
	while (k > p[x].c) k -= p[x].c, x = p[x].r;
	y = k - 1;
}
void add(int x, int u) //将节点u插到节点x的右边
{
	p[u].r = p[x].r; p[p[u].r].l = u;
	p[x].r = u; p[u].l = x;
}
void del(int u) //删除节点u
{
	p[p[u].l].r = p[u].r;
	p[p[u].r].l = p[u].l;
	p[u].l = p[u].r = p[u].c = 0;
	id[++idx] = u;
}
void insert(int k) //在光标后面插入k个字符
{
	if (y + 1 != p[x].c) //分裂
	{
		int u = id[idx--];
		for (int i = y + 1; i < p[x].c; i++) p[u].s[p[u].c++] = p[x].s[i];
		p[x].c = y + 1;
		add(x, u);
	}
	int cur = x, i = 0;
	while (i < k) {
		int u = id[idx--];
		for (; i < k and p[u].c < N; i++) {
			p[u].s[p[u].c++] = str[i];
		}
		add(cur, u);
		cur = u;
	}
}
void remove(int k) //删除光标后的k个字符
{
	if (y + 1 + k <= p[x].c) {
		for (int i = y + 1, j = y + 1 + k; j < p[x].c; j++,i++) {
			p[x].s[i] = p[x].s[j];
		}
		p[x].c -= k;
	}
	else {
		k -= (p[x].c - y - 1);
		p[x].c = y + 1;
		while (p[x].r and k >= p[p[x].r].c) {
			k -= p[p[x].r].c;
			del(p[x].r);
		}
		int u = p[x].r;
		for (int i = 0, j = k; j < p[u].c; j++, i++)p[u].s[i] = p[u].s[j];
		p[u].c -= k;
	}
}

void get(int k) //获取光标后k个字母
{
	if (y + 1 + k <= p[x].c) {
		for (int i = y + 1; i <= y + k; i++)putchar(p[x].s[i]);
	}
	else {
		k -= (p[x].c - y - 1);
		for (int i = y + 1; i < p[x].c; i++)putchar(p[x].s[i]);
		int cur = x;
		while (p[cur].r and k >= p[p[cur].r].c) {
			k -= p[p[cur].r].c;
			for (int i = 0; i < p[p[cur].r].c; i++)putchar(p[p[cur].r].s[i]);
			cur = p[cur].r;
		}
		int u = p[cur].r;
		for (int i = 0; i < k; i++)putchar(p[u].s[i]);
	}
	puts("");
}
void prev() //光标前移
{
	if (y) y--;
	else {
		x = p[x].l;
		y = p[x].c - 1;
	}
}
void next() //光标后移
{
	if (y != p[x].c - 1) {
		y++;
	}
	else {
		x = p[x].r;
		y = 0;
	}
}

void merge() //关键操作,将长度较短的合并，保持正确的复杂度
{
	for (int i = p[0].r; i; i = p[i].r) {
		while (p[i].r and p[i].c + p[p[i].r].c < N) {
			int r = p[i].r;	
			for (int ii = p[i].c, j = 0; j < p[r].c; ii++, j++) {
				p[i].s[ii] = p[r].s[j];
			}
			if (x == r) x = i, y += p[i].c;
			p[i].c += p[r].c;
			del(r);
		}
	}
}
int main() {
    //freopen("P4008_1.in", "r", stdin);
    //freopen("ans.out", "w", stdout);
	for (int i = 1; i < M; i++) id[++idx] = i;
	scanf("%d", &n);
	char op[10];

	str[0] = '>';
	insert(1);  // 插入哨兵
	move(1);  // 将光标移动到哨兵后面

	while (n--)
	{
		int a;
		scanf("%s", op);
		if (!strcmp(op, "Move"))
		{
			scanf("%d", &a);
			move(a + 1);
		}
		else if (!strcmp(op, "Insert"))
		{
			scanf("%d", &a);
			int i = 0, k = a;
			while (a)
			{
				str[i] = getchar();
				if (str[i] >= 32 && str[i] <= 126) i++, a--;
			}
			insert(k);
			merge();
		}
		else if (!strcmp(op, "Delete"))
		{
			scanf("%d", &a);
			remove(a);
			merge();
		}
		else if (!strcmp(op, "Get"))
		{
			scanf("%d", &a);
			get(a);
		}
		else if (!strcmp(op, "Prev")) prev();
		else next();
	}
}

