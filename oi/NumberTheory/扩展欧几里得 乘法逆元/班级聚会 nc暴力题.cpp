#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long 
using namespace std;

inline int read(){
	int x = 0, f = 1; char ch = getchar();
	while(!isdigit(ch)){if(ch == '-') f = -1;ch = getchar();}
	while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - 48; ch = getchar();}
	return x * f;
}

const int N = 205;

struct Nd{
	int dis, cnt;
	string s;
}a[N];
int tot, sum[N], cnt[N], val, jud;
string ans;
//map<string, int> dis;

bool cmp(Nd A, Nd B){
	return A.dis < B.dis;
}

int main(){
	cin >> a[++tot].cnt >> a[tot].dis;
	cin >> a[tot].s;
//	cout << "fabs:" << a[tot].s;
	while(1){
		if(a[tot].s == "Moscow") break;
		cin >> a[++tot].cnt >> a[tot].dis;
		cin >> a[tot].s;
//		dis[a[tot].s] = a[tot].dis;
	} 
//	sort(a + 1, a + 1 + tot, cmp);
//	for(int i = 1; i <= tot; i++) sum[i] = sum[i-1] + a[i].dis;
	val = inf;
	printf("tot : %d\n", tot);
	for(int i = 1; i <= tot; i++){
		jud = 0;
		for(int j = 1; j <= tot; j++){
			jud += (abs(a[i].dis - a[j].dis) * a[j].cnt);
		}
//		printf("1 : %d ", jud);
//		for(int j = i+1; j <= tot; j++){
//			jud += abs(dis[a[j].s] - dis[a[i].s]) * a[j].cnt;
//		}
		cout << a[i].s << jud << endl;
		if(jud < val){
			val = jud;
			ans = a[i].s;
		}
	}
	cout << ans << " " << val;
	return 0;
} 
