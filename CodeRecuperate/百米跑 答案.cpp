#include<iostream>
#include<cstdio>
#include<map>//map库
using namespace std;
map<string,string> a;//建立映射
string fin(string x){//查找字符串x的祖先
	if(a[x]==x) return x;
	else return a[x]=fin(a[x]);//路径压缩
}
int main(){
	int n,m,k;
	string s1,s2;//s1,s2可重复使用
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>s1;//选手名字
		a[s1]=s1;//每个人的祖先初始化为自己
	}
	for(int i=1;i<=m;++i){
		cin>>s1>>s2;//两位选手
		string x1=fin(s1),x2=fin(s2);//合并
		if(x1!=x2) a[x1]=x2;
	}
	cin>>k;
	for(int i=1;i<=k;++i){
		cin>>s1>>s2;
		string x1=fin(s1),x2=fin(s2);//查询
		if(x1!=x2) printf("No.\n");
		else printf("Yes.\n");
	}
	return 0;//后话：STL大法好！
}
