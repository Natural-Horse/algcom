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

int n, a[10], ans;

    int main() {
    	n = read();
        for(int i = 1; i <= n; i++){
            int jud = i * i;
            int p = 0; bool check = false;
            while(jud) a[++p] = jud % 10, jud /=10;
            for(int j = 0; j < (1<<(p-1)); j++){
                int tmp = j, tot = 0, plc = p, num = a[p];
                for(int w = p-1; w; tmp >>= 1, w--){
                	int k = tmp & 1;
                    if(k == 0) num = num * 10 + a[--plc];
                    else tot += num, num = a[--plc];
                }
                tot += num;
                if(tot == i){check = true; break;}
            }
            if(check) ans += i * i;
        }
        cout << ans;
    	return 0;
	}

