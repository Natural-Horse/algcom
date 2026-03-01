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

const int N = 31;

    int n, m, b[10], f[N][10], ans, jud;
    vector<vector<int>> v[N];
    vector<int> fab, groups;
    map<vector<int>, int> mp;

    int main(){
        n = read();
        m = read();
        for(int i = 0; i < n; i++) {
			groups[i] = read(); 
			groups[i] %= m, b[groups[i]]++;
		}
        mp[fab] = b[0];
        ans = max(ans, b[0]);
        for(int i = 1; i <= n-b[0]; i++){
            if(i == 1){
                vector<int> vec(10);
                for(int j = 1; j <= m-1; j++){
                   // if(b[j] == 0) continue;
                    vec[j]++;
                    v[1].push_back(vec);
                    mp[vec] = b[0] + 1;
                    vec[j]--;
                }
                continue;
            }
            for(auto vec : v[i-1]){
                int jud = 0;
                vector<int> V = vec;
                for(int j = 1; j <= m-1; j++) jud += vec[j] * j;
                for(int j = 1; j <= m-1; j++){
                    if(vec[j] < b[j]){
                        vec[j]++; 
                        if(jud % m == 0) mp[vec] = max(mp[vec], mp[V] + 1);
                        else mp[vec] = max(mp[vec], mp[V]);
                        ans = max(ans, mp[vec]);
                        v[i].push_back(vec);
                        vec[j]--;
                    }
                }
            }
        }
        cout << ans;
    }

