#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

ll posa, posb, la, lb, l; //pos两青蛙位置，la,lb速度,l总距离 
ll s; //两青蛙间距 
ll ansa, ansb; // ansa = t, ansb = ((a-b)*t)/l;
ll t; // 两青蛙跳的次数 

ll exgcd(ll a, ll b, ll &x, ll &y){
	if(b == 0){
		x = 1, y = 0;
		return a;
	}
	ll d = exgcd(b, a%b, x, y);
	ll jud = x;
	x = y, y = jud - y * (a / b);
	return d;
}

int main(){
	scanf("%lld %lld %lld %lld %lld", &posa, &posb, &la, &lb, &l);
	if(la > lb){
		s = posb - posa;
		ll d = exgcd(la-lb, l, ansa, ansb);
		if(s % d != 0){
			printf("Impossible");
			return 0;
		}
		ansa = ansa*(s/d);
		if(ansa < 0){
			ansa = -ansa;
			t = l - ansa % (l/d);
		}
		else{
			t = ansa % (l/d);
		}		
	}
	else{
		s = posa - posb;
		ll d = exgcd(lb-la, l, ansa, ansb);
		if(s % d != 0){
			printf("Impossible");
			return 0;
		}
		ansa = ansa*(s/d);
		if(ansa < 0){
			if(ansa < 0){
				ansa = -ansa;
				t = l - ansa % (l/d);
		}
		}
		else{
			t = ansa % (l/d);
		}
	}
	printf("%lld", t);	
	return 0;
} 
