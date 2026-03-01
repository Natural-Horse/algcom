// clang-format off
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

inline int read(){
    int x = 0, f = 1; char ch = getchar();
    while (!isdigit(ch)){if(ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch)){x = (x << 3) + (x << 1) + ch - 48; ch = getchar();}
    return x * f;
}

const int N = 105;

char s[N];
int n, ans;

int main(){
   scanf("%s", s + 1);
   cout << s[2] << s[3] << s[1] << ' ' << s[3] << s[1] << s[2] << endl;
   return 0;
}