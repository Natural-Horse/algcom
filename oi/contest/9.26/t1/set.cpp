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

const int N = 1e6 + 5;

struct Nd{
	int id, val;
}nd[N];
struct Edge{
	int to, w;
}ed[N << 1];
int n;
bool b[N];
vector<int> vec;

void add_edge(int u, int v, int w){
	ed[u].to = v, ed[u].w = w;
}

bool cmp(Nd aa, Nd bb){
	return aa.val < bb.val;
}

int main(){
	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);
	n = read();
	for(int i = 1; i <= n; i++){
		nd[i].id = i, nd[i].val = read() % n;
		if(nd[i].val == 0){
			printf("%d\n%d\n", 1, i);
			return 0;
		}
	}
	sort(nd + 1, nd + 1 + n, cmp);
	int jud = 0;
	for(int i = 1; i <= n; i++){
		if(nd[i].val == nd[i-1].val){
			int fab = (jud + nd[i].val) % n;
			vec.push_back(i);
			if(fab == 0){
				int sz = vec.size();
				printf("%d\n", sz);
				for(int j = 0; j < sz; j++) printf("%d ", nd[vec[j]].id);
				printf("\n");
				return 0;
			} 
			else if(b[n-fab]){
				int u = n-fab;
				while(u){
					vec.push_back(ed[u].w);
					u = ed[u].to;
				}
				int sz = vec.size();
				printf("%d\n", sz);
				for(int j = 0; j < sz; j++) printf("%d ", nd[vec[j]].id);
				printf("\n");
				return 0;
			}
			jud = fab;
		}
		else{
			int sz = vec.size();
			int fab = 0;
			for(int j = 0; j < sz; j++){
				int u = (fab+nd[vec[j]].val) % n;
				if(!b[u]) add_edge(u, fab, nd[vec[j]].id);
				fab = u;
				b[fab] = true;
			}
			vec.clear();
			vec.push_back(i);
			jud = nd[i].val;
		}
	}
	return 0;
}
