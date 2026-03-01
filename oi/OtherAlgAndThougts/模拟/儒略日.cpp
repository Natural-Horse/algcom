#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
#define db double
#define int long long
using namespace std;

inline int read(){
	int x = 0, f = 1; char ch = getchar();
	while(!isdigit(ch)){if(ch == '-') f = -1; ch = getchar();}
	while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - 48; ch = getchar();}
	return x * f;
}

const int N = 1461, B = 2299164, F = 76;

int q, a[50], b[5000], f[1250]; 
int pm[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int rm[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void pre_work(){
    for(int i = 1; i <= 36; i++) a[i] = pm[(i-1)%12+1];
    for(int i = 1; i <= 12; i++) a[i+36] = rm[i];
    for(int i = 1; i <= 25; i++)
        for(int j = 1; j <= 48; j++) f[(i-1)*48+j] = a[j];
    f[99*12+2] -= 1;
    for(int i = 1; i <= 4; i++)
        for(int j = 1; j <= 1200; j++) b[(i-1)*1200+j] = f[j];
    b[399*12+2] += 1;
    for(int i = 1; i <= 48; i++) a[i] = a[i-1] + a[i];
    for(int i = 1; i <= 4800; i++) b[i] = b[i-1] + b[i];
}
int bi_ser1(int x){
    int l = 0, r = 50;
    while(l < r){
        int mid = (l+r+1) >> 1;
        //printf("l:%lld r:%lld mid:%lld\n", l, r, mid);
        if(x < a[mid]) r = mid - 1;
        else l = mid;
    }
    return l;
}
int bi_ser2(int x){
    int l = 0, r = 4801;
    while(l < r){
        int mid = (l+r+1) >> 1;
        if(x < b[mid]) r = mid - 1;
        else l = mid;
    }
    return l;
}

signed main(){
    pre_work();
    q = read();
    for(int i = 1, day; i <= q; i++){
        day = read();
        day += 1;
        if(day <= B){
            day += 1095;
            int fab = (day - 1) % 1461 + 1, y = day / 1461 * 4;
            //printf("fab : %lld\n", fab);
            int m = bi_ser1(fab);
//            printf("m : %d\n", m);
            int d = fab - a[m];
            y = y + m/12 + 1, m = m % 12 + 1; 
            if(y <= 4716){
                y = 4716 - y + 1;
                printf("%lld %lld %lld BC\n", d, m, y);
            }
            else{
                y -= 4716;
                printf("%lld %lld %lld\n", d, m, y);
            }
        }
        else{
            int d = 0, y = 0, m = 0, fab = 0;
            if(day <= 2299240){
                day -= 2299164, y = 1582;
                if(day <= 15) d = day, m = 10;
                else if(day <= 46) d = day - 15, m = 11;
                else d = d - 46, m = 12; 
            }
            else{
                day -= 2299240;
//                printf("B::%lld\n", b[4800]);
                fab = (day-1) % b[4800] + 1, y = day / b[4800] * 400 + 1582;
                m = bi_ser2(fab);
//                printf("fab:%lld m:%lld y:%lld\n", fab, m, y);
                y = y + m/12 + 1, d = fab - b[m], m = m % 12 + 1;
                printf("%lld %lld %lld\n", d, m, y);
            }
        }
    }
    return 0;
}

