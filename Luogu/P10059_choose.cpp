// clang-format off
#include <bits/stdc++.h>
#define inf 2e9 + 5
#define long long
#define pii pair<int, int>
#define mkp make_pair
using namespace std;

inline int read(){
    int x = 0, f = 1; char ch = getchar();
    while(!isdigit(ch)){if(ch == '-') f = -1; ch = getchar();}
    while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - 48; ch = getchar();}
    return x * f;
}

const int N = 5e5 + 5;

struct Nd{
    int id, val;
}q1[N << 1], q2[N << 1];
int n, k, T;
int a[N], L, X;
int front1, back1, front2, back2;

bool check(int x, int l){
    int cnt = 0;
    front1 = front2 = 1;
    back1 = back2 = 0;
    for(int i = 1; i <= l; i++){
        while(front1 <= back1 && back1 >= 1 && q1[back1].val < a[i]) back1--;
        q1[++back1] = {i, a[i]};
        while(front2 <= back2 && back2 >= 1 && q2[back2].val > a[i]) back2--;
        q1[++back2] = {i, a[i]};
    }
    cnt += ((q1[front1].val - q2[front2].val) >= x);
    if(cnt >= k) return true;
    for(int i = l + 1; i <= n; i++){
        while(front1 <= back1 && back1 >= 1 && q1[back1].val < a[i]) back1--;
        q1[++back1] = {i, a[i]};
        while(front1 <= back1 && q1[front1].id < i - l + 1) front1++;
        while(front2 <= back2 && back2 >= 1 && q2[back2].val > a[i]) back2--;
        q2[++back2] = {i, a[i]};
        while(front2 <= back2 && q2[front2].id < i - l + 1) front2++;
        cnt += ((q1[front1].val - q2[front2].val) >= x);
        if(cnt >= k) return true;
    }
    return false;
}

void solveX(){
    front1 = front2 = 1;
    back1 = back2 = 0;
    X = inf;
    for(int i = 1; i <= L; i++){
        while(front1 <= back1 && back1 >= 1 && q1[back1].val < a[i]) back1--;
        q1[++back1] = {i, a[i]};
        while(front2 <= back2 && back2 >= 1 && q2[back2].val > a[i]) back2--;
        q2[++back2] = {i, a[i]};
    }
    X = min(X, q1[front1].val - q2[front2].val);
    for(int i = L + 1; i <= n; i++){
        while(front1 <= back1 && back1 >= 1 && q1[back1].val < a[i]) back1--;
        q1[++back1] = {i, a[i]};
        while(front1 <= back1 && q1[front1].id < i - L + 1) front1++;
        while(front2 <= back2 && back2 >= 1 && q2[back2].val > a[i]) back2--;
        q2[++back2] = {i, a[i]};
        while(front2 <= back2 && q2[front2].id < i - L + 1) front2++;
        X = min(X, q1[front1].val - q2[front2].val);
    }
}

void solveL(){
    int l = 1, r = L;
    while(l < r){
        int mid = (l + r) >> 1;
        if(check(X, mid)) r = mid;
        else l = mid + 1;
    }
    L = l;
}

int main(){
    T = read();
    while(T--){
        n = read(), k = read();
        L = n - k + 1;
        for(int i = 1; i <= n; i++){
            a[i] = read();
        }
        solveX();
        solveL();
        // cout << "Ans : ";
        cout << X << ' ' << L << endl;
    }
    return 0;
}