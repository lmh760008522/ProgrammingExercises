#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main(){
	char s[100];
	gets(s);
	int p,q;
	for(p=strlen(s)-1;p>=0; ){
		for(q=p; s[q]!=' ' && q>=0 ;q--);
		for(int j=q+1;j<=p;j++){
			cout<<s[j];
		}
		if(q!=-1){
			cout<<' ';
		}
		p=q-1;
	}
	return 0;
}
