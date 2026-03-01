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

const int N = 1e5 + 5; 

int n, a[N], tmp[N];

void merge_sort(int l, int r){
	if(l == r) return;
	int mid = (l + r) >> 1;
	merge_sort(l, mid), merge_sort(mid+1, r);
	for(int i = l, j = mid+1, cnt = l-1; i <= mid || j <= r;){
		if(i <= mid && j <= r){
			if(a[i] > a[j]) tmp[++cnt] = a[j], j++;
			else tmp[++cnt] = a[i], i++;
		}
		else if(i > mid && j <= r) tmp[++cnt] = a[j++];
		else if(j > r && i <= mid) tmp[++cnt] = a[i++];
		else break;
	}
	for(int i = l; i <= r; i++) a[i] = tmp[i];
	return;
}

int main(){
	n = read();
	for(int i = 1; i <= n; i++) a[i] = read();
	merge_sort(1, n);
	for(int i = 1; i <= n; i++) printf("%d ", a[i]);
	return 0;
}

