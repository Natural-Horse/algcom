#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
#define db double
#define pii pair<int, int>
#define mkp make_pair()
using namespace std;

inline int read(){
    int x = 0, f = 1; char ch = getchar();
    while(!isdigit(ch)){if(ch == '-') f = -1; ch = getchar();}
    while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - 48; ch = getchar();}
    return x * f;
}

const int N = 1e5 + 5;

int n, T;
int winner, loser, n_round;

void reset(){
    winner = loser = n_round = 0;
}

void solve(){
    winner = n;
    while(winner > 1 || loser > 1){
        int winner_nxt = winner / 2 + (winner & 1);
        int loser_nxt = loser / 2 + winner / 2 + (loser & 1);
        n_round += winner / 2 + loser / 2;
        winner = winner_nxt, loser = loser_nxt;
    }
    n_round += 1;
}

int main(){
    T = read();
    int count = T;
    while(T--){
        n = read();
        reset();
        solve();
        // printf("Test %d : ", count - T);
        printf("%d\n", n_round);
    }
    return 0;
}