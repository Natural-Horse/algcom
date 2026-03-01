#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

const int Maxn = 105;

char s[Maxn];
int f[Maxn][Maxn];
string a[Maxn][Maxn];
int n;

int get_len(int x){
	int ans = 0;
	while(x){
		ans++;
		x /= 10;
	}
	return ans;
}

int main(){
	scanf("%s", s + 1);
	n = strlen(s + 1);
	memset(f, 0x3f, sizeof(f));
	for(int i = 0; i <= n; i++) f[i][i] = 1;
	for(int k = 2; k <= n; k++){
		for(int l = 1; l <= n - k + 1; l++){
			int r = l + k - 1;
			for(int mid = l; mid < r; mid++){
				f[l][r] = min(f[l][r], f[l][mid] + f[mid+1][r]);
			}
			for(int i = 1; i <= sqrt(k); i++){
				if(k % i != 0) continue;
				int check = true;
				int cnt = l;
				for(int j = l + i; j <= r; j++){
					if(s[j] != s[cnt]){
						check = false;
						break;
					}
					cnt++;
					if(cnt == l + i) cnt = l;
				}
				if(check) f[l][r] = min(f[l][r], get_len(k/i) + f[l][l+i-1] + 2);
				else{
					check = true;
					i = k / i;
					cnt = l;
					for(int j = l + i; j <= r; j++){
						if(s[j] != s[cnt]){
							check = false;
							break;
						}
						cnt++;
						if(cnt == l + i) cnt = l;
					}
					if(check) f[l][r] = min(f[l][r], get_len(k/i) + f[l][l+i-1] + 2);
					i = k / i;
				}
			}
		}
	}
	printf("%d", f[1][n]);
	return 0;
}
