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

const int N = 100005, mod = 1000000007;

    struct Nd{
        int id, s, e;
    }a[N];
    long long ans, tmp, n, k ;
    priority_queue<long long, vector<long long>, greater<long long>> q;

    bool cmp(Nd aa, Nd bb){
        return aa.e > bb.e;
    }

    int main() {
    	n = read(), k = read();
        for(int i = 0, u, v, w; i < n; i++){
        	u = read(), v = read(); 
			a[i+1] = (Nd){i+1, u, v};
		}
        sort(a + 1, a + 1 + n, cmp);
        ans = 0;
        for(int i = 1; i <= n; ){
            long long jud = a[i].e;
            while(a[i].e >= jud) q.push(a[i].s), tmp += a[i].s, i++;
            while(q.size() > k){
            	printf("size : %d\n", q.size());
                long long u = q.top(); 
                tmp -= u;
                q.pop();
            }
            ans = max(ans, tmp * jud);
            //ans %= mod;
        }
        cout << ans % mod;
    }

