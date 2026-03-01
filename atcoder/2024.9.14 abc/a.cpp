#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

inline int read(){
    int x = 0, f = -1; char ch = getchar();
    while(!isdigit(ch)){if(ch == '-') f = -1; ch = getchar();}
    while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - 48; ch = getchar();}
    return x * f;
}

const int N = 1e5 + 5;
char s[5];

int main(){
    for(int i = 1; i <= 3; i++){
        s[i] = getchar();
        getchar();
    }
    if(s[1] == '>'){
        if(s[3] == '>') printf("B\n");
        else if(s[2] == '<') printf("A\n");
        else if(s[2] == '>') printf("C\n");
    }
    else{
        if(s[3] == '<') printf("B\n");
        else if(s[2] == '<') printf("C\n");
        else if(s[2] == '>') printf("A\n");
    }
    return 0;
}