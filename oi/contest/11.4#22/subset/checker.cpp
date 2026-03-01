#include"testlib.h"
using std::string;
bool vis[1<<20];
void checkOnce(int Tid)
{
	int n=inf.readInt();
	int m=inf.readInt();
	int t=n/m;
	string s=ouf.readToken();
	if(s!="Yes")
	{
		if(s=="No")return;
		quitf(_wa,"Expected Yes or No, found %s (test case %d)",s.c_str(),Tid);
	}
	long long S=n*1ll*(n+1)/2;
	long long elf=S/m;
	for(int i=1;i<=n;i++)vis[i]=0;
	for(int i=1;i<=m;i++)
	{
		long long Lsum=0;
		for(int c=1;c<=t;c++)
		{
			int sp=ouf.readInt(1,n);
			if(vis[sp])
				quitf(_wa,"Number %d appears more than once (test case %d)",sp,Tid);
			vis[sp]=1,Lsum+=sp;
		}
		if(Lsum!=elf)
			quitf(_wa,"Sum of the subsets aren't equal (test case %d)",Tid);
	}
}
int main(int argc,char*argv[])
{
	registerTestlibCmd(argc,argv);
	int T=inf.readInt();
	for(register int testCaseId=1;testCaseId<=T;testCaseId++)
		checkOnce(testCaseId);
	quitf(_ok,"Accepted (%d test cases)",T);
}