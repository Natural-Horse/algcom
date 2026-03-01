#include<bits/stdc++.h>
namespace fastread{
	const int LEN=1000000;
	char in[LEN+5];
	char *pin=in,*ed=in;
	inline char gc(void){
		return pin==ed&&(ed=(pin=in)+fread(in,1,LEN,stdin),ed==in)?EOF:*pin++;
	}
	template<typename T> inline void read(T &x){
		static int f;
		static char c;
		c=gc(),f=1,x=0;
		while(c<'0'||c>'9') f=(c=='-'?-1:1),c=gc();
		while(c>='0'&&c<='9') x=10*x+c-'0',c=gc();
		x*=f;
	}
}
using fastread::read;
int n;
int main(){
	read(n);
	std::cout<<n<<std::endl; 
	return 0;
}
