#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
#define db double
#define R register
using namespace std;

inline int read(){
	int x = 0, f = 1; char ch = getchar();
	while(!isdigit(ch)){if(ch == '-') f = -1; ch = getchar();}
	while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - 48; ch = getchar();}
	return x * f;
}

const int N = 2e3 + 5, M = 2e6 + 10;

struct Part{
    int l, r, c;
    char s[N << 1];
}p[(N << 1) + 10];
int n, x, y, nd[N << 1], tot, S;
char a[M]; 

inline void move(int k){                // 把光标移到k后 
    x = p[0].r;
    while(k > p[x].c) k -= p[x].c, x = p[x].r;
    y = k;
}
inline void add(int k, int u){         // 在k后面加上u 
    p[u].r = p[k].r, p[p[u].r].l = u;
    p[k].r = u, p[u].l = k;
}
inline void del(int u){                //把u删了, 顺便把左右接上 
    p[p[u].l].r = p[u].r, p[p[u].r].l = p[u].l;
    p[u].l = p[u].r = p[u].c = 0;
    nd[++tot] = u;
}
void insert(int k){             //在光标后面插入k个字符
    if(y != p[x].c){
        int u = nd[tot--];
        for(R int i = y+1; i <= p[x].c; i++) p[u].s[++p[u].c] = p[x].s[i];
        p[x].c = y;
        add(x, u);
    }
    int tmp = x, i = 0;
    while(i < k){
        int u = nd[tot--];
        for(; i < k && p[u].c <= N; i++) p[u].s[++p[u].c] = a[i];
        add(tmp, u);
        tmp = u;
    }
}
void remove(int k){            // 在删掉光标后面的k个字符 
    if(y + k <= p[x].c){
        for(R int i = y + 1, j = y+k+1; j <= p[x].c; i++, j++) p[x].s[i] = p[x].s[j];
        p[x].c -= k;
    }
    else{
        k -= (p[x].c - y); p[x].c = y;
        while(p[x].r && k >= p[p[x].r].c){
            k -= p[p[x].r].c;
            del(p[x].r);
        }
        int u = p[x].r;
        for(R int i = 1, j = k+1; j <= p[u].c; i++, j++) p[u].s[i] = p[u].s[j];
        p[u].c -= k;
    }
}
void get(int k){                //输出光标后k个字符 
    if(y + k <= p[x].c)
        for(int i = y+1; i <= y+k; i++) putchar(p[x].s[i]);
    else{
        k -= (p[x].c - y);
        for(R int i = y+1; i <= p[x].c; i++) putchar(p[x].s[i]);
        int tmp = x;
        while(p[tmp].r && k >= p[p[tmp].r].c){
            k -= p[p[tmp].r].c; tmp = p[tmp].r;
            for(int i = 1; i <= p[tmp].c; i++) putchar(p[tmp].s[i]); 
        }
        tmp = p[tmp].r;
        for(R int i = 1; i <= k; i++) putchar(p[tmp].s[i]);
    }
    puts("");
}
inline void prev(){                   //光标左移 
    if(y == 1) x = p[x].l, y = p[x].c;
    else y--;
}
inline void next(){                   //光标右移 
    if(y == p[x].c) x = p[x].r, y = 1;
    else y++;
}
inline void merge(){
    for(R int i = p[0].r; i; i = p[i].r){
        while(p[i].r && p[i].c + p[p[i].r].c < N){
            int r = p[i].r;
            for(R int j = p[i].c+1, k = 1; k <= p[r].c; j++, k++) p[i].s[j] = p[r].s[k];
            if(x == r) x = i, y += p[i].c;
            p[i].c += p[r].c;
            del(r);
        }
    }
}

int main(){
//    freopen("P4008_1.in", "r", stdin);
//    freopen("out.out", "w", stdout);
    n = read();
    for(int i = 1; i <= N; i++) nd[++tot] = i;
    a[0] = '>';
    insert(1);
    move(1);
    char op[15];
    for(R int i = 1; i <= n; i++){
         int k = 0;
        scanf("%s", op);
        if(!strcmp(op, "Move")){
            k = read();
            move(k + 1);
        }
        else if(!strcmp(op, "Insert")){
            k = read();
            int i = 0, fab = k; 
            while(fab){
                a[i] = getchar();
                if(a[i] >= 32 && a[i] <= 126) i++, fab--;
            }
            insert(k);
            merge();
        }
        else if(!strcmp(op, "Delete")){
            k = read();
            remove(k);
            merge();
        }
        else if(!strcmp(op, "Get")){
            k = read();
            get(k);
        }
        else if(!strcmp(op, "Prev")) prev();
        else next();
    }
    return 0;
}
