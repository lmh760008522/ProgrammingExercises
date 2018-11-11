#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
int main(){
	//string s="babad";
	string s="cbbd";
	string ss = "$#";
	int p[15];
	int ans=0;
	for(int i=0;i<s.size();i++){
		ss+=s[i];
		ss+="#";
	}
	int id=0,ms=0;
	int reslen=0,rescenter=0;
	for(int i=1;i<ss.size();i++){
		p[i]= ms>i ? min(p[2*id-i], ms-i) : 1;
		while( ss[i-p[i]]== ss[i+p[i]]){
			p[i]++;
		}
		if(ms < i+p[i]){
			ms= i+p[i];
			id=i;
		}
		if(reslen<p[i]){
			reslen=p[i];
			rescenter=i;
		}
	}
	printf("%d ",reslen-1);
	cout<<s.substr((rescenter - reslen)/2, reslen-1);
	return 0;
}
